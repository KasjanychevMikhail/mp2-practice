#include "Calculator.h"
#include "Stack.h"
#include <iostream>

using namespace std;

void main()
{
	string s, rez;
	int size = 0;
	double PFV = 0;
	cout << "Vvedite stroku" << endl;
	cin >> s;
	try
	{
		rez = Calculator::CreatePostForm(s);
	}
	catch(char *osh)
	{
		cout << osh << endl;
	}
	cout << "Postfix form = " << endl;
	cout << rez << endl;
	double* ex = new double[rez.length()];
	char* oper = new char[rez.length()];
	try
	{
		Calculator::GetOper(rez, ex, oper, size);
	}
	catch (char* osh)
	{
		cout << osh << endl;

	}
	try
	{
		PFV = Calculator::Calculate(rez, ex, oper, size);
	}
	catch (char* osh)
	{
		cout << osh << endl;
	}
	cout << "Znachenie virazheniya:" << endl;
	cout << PFV;
	system("pause");
}