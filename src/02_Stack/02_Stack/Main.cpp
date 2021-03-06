#include "Calculator.h"
#include "Stack.h"
#include <locale.h>
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	string s, rez;
	int h = 1;
	double PFV = 0;
	cout << "Введите строку:" << endl;
	cin >> s;
	try
	{
		rez = Calculator::CreatePostForm(s);
	}
	catch(const char *osh)
	{
		cout << osh << endl;
		system("pause");
		return;
	}
	cout << "Постфиксная форма = ";
	cout << rez << endl;
	double* ex;
	char* oper;
	try
	{
		Calculator::GetOper(rez, ex, oper, h);
	}
	catch (const char* osh)
	{
		cout << osh << endl;
		system("pause");
		return;
	}
	try
	{
		PFV = Calculator::Calculate(rez, ex, oper, h);
	}
	catch (const char* osh)
	{
		cout << osh << endl;
		system("pause");
		return;
	}
	cout << "Значение выражения: " << endl;
	cout << PFV << endl;
	system("pause");
}