#pragma once
#include "Stack.h"
#include <string>
using namespace std;

class Calculator
{
private:
	static bool Prior(char, char);
	static double Calc(double, double, char);
public:
	static string CreatePostForm(const string&);
	static double Calculate(const string&, const double*, const char*, int);
	static void GetOper(const string&, double*&, char*&, int);
};