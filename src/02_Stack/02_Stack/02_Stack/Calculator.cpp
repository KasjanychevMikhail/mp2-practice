#include "Calculator.h"
#include <iostream>

bool Calculator::Prior(char a, char b)
{
	if ((a == '*' || a == '/') && (b == '*' || b == '/')) return true;
	if ((a == '+' || a == '-') && (b == '+' || b == '-')) return true;
	if ((a == '+' || a == '-') && (b == '*' || b == '/')) return true;
	return false;
}

double Calculator::Calc(double a, double b, char c)
{
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0) throw "Nelzya delit na zero";
		return a / b;
	}
}

string Calculator::CreatePostForm(const string& s)
{
	int left = 0;
	int right = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') left++;
		if (s[i] == ')') right++;
	}
	if (left != right) throw "Invalid";
	if ((s[0] == '+') || (s[0] == '-') || (s[0] == '*') || (s[0] == '/')) throw "Invalid";
	if (s[s.length() - 1] == '+' || s[s.length() - 1] == '-' || s[s.length() - 1] == '*' || s[s.length() - 1] == '/') throw "Invalid";
	for (int i = 0; i < s.length(); i++)
		if ((s[i] == '1') || (s[i] == '2') || (s[i] == '3') || (s[i] == '4') || (s[i] == '5') || (s[i] == '6') || (s[i] == '7') || (s[i] == '8') || (s[i] == '9') || (s[i] == '0'))
			throw "Invalid";
	for (int j = 1; j < s.length(); j++)
		if ((s[j] != '+') && (s[j] != '-') && (s[j] != '*') && (s[j] != '/') && (s[j] != '(') && (s[j] != ')') && (s[j - 1] != '+') && (s[j - 1] != '-') && (s[j - 1] != '*') && (s[j - 1] != '/') && (s[j - 1] != '(') && (s[j - 1] != ')'))
			throw "Invalid";
	for (int i = 1; i < s.length(); i++)
		if (((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/')) && ((s[i - 1] == '+') || (s[i - 1] == '-') || (s[i - 1] == '*') || (s[i - 1] == '/')))
			throw "Invalid";
	TStack<double> operands(s.length());
	TStack<double> operators(s.length());
	string PFForm = "";
	for (int i = 0; i < s.length(); i++)
	{
		bool f = (s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/') || (s[i] == '(') || (s[i] == ')');
		if (!f)
		{
			operands.Push(s[i]);
			continue;
		}
		if (f)
		{
			if (s[i] == ')')
			{
				while (operators.Top() != '(')
					operands.Push(operators.Pop());
				operators.Pop();
				continue;
			}
			if (Prior(s[i], operators.Top()))
			{
				while ((Prior(s[i], operators.Top())) && !(operators.IsEmpty()) && (operators.Top() != '('))
					operands.Push(operators.Pop());
				operators.Push(s[i]);
				continue;
			}
			operators.Push(s[i]);
		}
	}
	while (!operators.IsEmpty())
		operands.Push(operators.Pop());
	while (!operands.IsEmpty())
		operators.Push(operands.Pop());
	while (!operators.IsEmpty())
		PFForm += operators.Pop();
	return PFForm;
}

double Calculator::Calculate(const string& s, const double* a, const char* c, int d)
{
	TStack<double> L(d);
	for (int i = 0; i < s.length(); i++)
	{
		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/'))
		{
			double first = L.Pop();
			double second = L.Pop();
			L.Push(Calc(second, first, s[i]));
		}
		else
		{
			for (int j = 0; j < d; j++)
				if (c[j] == s[i])
					L.Push(a[j]);
		}
	}
	return L.Pop();
}

void Calculator::GetOper(const string& s, double*& a, char*& c, int d)
{
	d--;
	for (int i = 0; i < s.length(); i++)
		if (s[i] != '*' && s[i] != '/' && s[i] != '+' && s[i] != '-')
			d++;
	a = new double[d];
	c = new char[d];
	int P = 0;
	int W;
	for (int i = 0; i < s.length(); i++)
	{
		W = 0;
		if (s[i] != '*' && s[i] != '/' && s[i] != '+' && s[i] != '-')
		{
			for (int j = 0; j < P; j++) if (c[j] == s[i])
			{
				W = 1;
				break;
			}
			if (W == 0)
			{
				c[P] = s[i];
				cout << "Vvod " << s[i] << ": ";
				cin >> a[P];
				P++;
			}
		}
	}
}