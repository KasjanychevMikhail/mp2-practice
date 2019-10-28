#include <iostream>
#include "TMatrix.h"
using namespace std;

int main()
{
	int test, n;
	TMatrix<double> A(n);
	TMatrix<double> B(n);
	TMatrix<double> C(n);
	do
	{
		cin >> test;
		switch (test)
		{
		case 1:
			cout << "TEST 1" << endl << "A + B" << endl;
			cout << "Size A = ";
			cin >> n;
			cout << "A = " << endl;
			cin >> A; cout << A;
			cout << "Size B = ";
			cin >> n;
			cout << "B = " << endl;
			cin >> B;
			cout << "A + B" << endl;
			try
			{
				C = A + B;
				cout << C;
			}
			catch (const char* er)
			{
				cout << er << endl;
			}
			cout << "TEST 1 !" << endl << endl;
			break;
		case 2:
			cout << "TEST 2" << endl << "A - B" << endl;
			cout << "Size A = ";
			cin >> n;
			cout << "A = " << endl;
			cin >> A;
			cout << "Size B = ";
			cin >> n;
			cout << "B = " << endl;
			cin >> B;
			cout << "A - B" << endl;;
			try
			{
				C = A - B;
				cout << C;
			}
			catch (const char* er)
			{
				cout << er << endl;
			}
			cout << "TEST 2!" << endl << endl;
			break;
		case 3:
			cout << "TEST 3" << endl << "A * B" << endl;
			cout << "Size A = ";
			cin >> n;
			cout << "A = " << endl;
			cin >> A;
			cout << "Size B = ";
			cin >> n;
			cout << "B = " << endl;
			cin >> B;
			cout << "A * B" << endl;
			try
			{
				C = A * B;
				cout << C;
			}
			catch (const char* er)
			{
				cout << er << endl;
			}
			cout << "TEST 3!" << endl << endl;
			break;
		case 4:
			cout << "TEST 4" << endl << "A + const" << endl;
			cout << "Size A = ";
			cin >> n;
			cout << "A = " << endl;
			cin >> A;
			cout << "Const = ";
			double c;
			cin >> c;
			cout << "A + const" << endl;
			C = A + c;
			cout << C;
			cout << "TEST 4!" << endl << endl;
			break;
		case 5:
			cout << "TEST 5" << endl << "A - const" << endl;
			cout << "Size A = ";
			cin >> n;
			cout << "A = " << endl;
			cin >> A;
			cout << "Const = ";
			cin >> c;
			cout << "A - const" << endl;
			C = A - c;
			cout << C;
			cout << "TEST 5!" << endl << endl;
			break;
		case 6:
			cout << "TEST 6" << endl << "A * const" << endl;
			cout << "Size A = ";
			cin >> n;
			cout << "A = " << endl;
			cin >> A;
			cout << "Const = ";
			cin >> c;
			cout << "A * const" << endl;
			C = A * c;
			cout << C;
			cout << "TEST 6!" << endl << endl;
			break;
		case 7:
			cout << "TEST 7" << endl << "A * vec" << endl;
			cout << "Size A = ";
			int v;
			cin >> n;
			cout << "A = " << endl;
			cin >> A;
			cout << "Size vec = ";
			cin >> n;
			cout << "B = " << endl;
			cin >> v;
			cout << "A * vec" << endl;
			try
			{
				C = A * v;
				cout << C;
			}
			catch (const char* er)
			{
				cout << er << endl;
			}
			cout << "TEST 7!" << endl << endl;
			break;
		case 8:
			cout << "TEST 8" << endl << "A == B" << endl;
			cout << "Size A = ";
			cin >> n;
			cout << "A = " << endl;
			cin >> A;
			cout << "Size B = ";
			cin >> n;
			cout << "B = " << endl;
			cin >> B;
			try
			{
				if (A == B)
					cout << "A = B" << endl;
				else
					cout << "A != B" << endl;
			}
			catch (const char* er)
			{
				cout << er << endl;
			}
			cout << "TEST 8!" << endl << endl;
			break;
		case 9:
			cout << "TEST 9" << endl << "A != B" << endl;
			int n;
			cout << "Size A = ";
			cin >> n;
			cout << "A = " << endl;
			cin >> A;
			cout << "Size B = ";
			cin >> n;
			cout << "B = " << endl;
			cin >> B;
			try
			{
				if (A != B)
					cout << "A != B" << endl;
				else
					cout << "A = B" << endl;
			}
			catch (const char* er)
			{
				cout << er << endl;
			}
			cout << "TEST 9!" << endl << endl;
			break;
		case 10:
			cout << "TEST 10" << endl << "A = B" << endl;
			cout << "Size A = ";
			cin >> n;
			cout << "A = " << endl;
			cin >> A;
			cout << B;
			break;
		}
	} while (test != 0);
}
