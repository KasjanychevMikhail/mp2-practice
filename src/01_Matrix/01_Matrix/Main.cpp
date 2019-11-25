#include <iostream>
#include "TMatrix.h"
using namespace std;

void Slozh()
{
	cout << "Slozhenie" << endl << "A + B" << endl;
	int n;
	cout << "Size A = ";
	cin >> n;
	TMatrix<double> A(n);
	cout << "A = " << endl;
	cin >> A; cout << A;

	cout << "Size B = ";
	cin >> n;
	TMatrix<double> B(n);
	cout << "B = " << endl;
	cin >> B;
	cout << "A + B" << endl;
	TMatrix<double> C(n);
	try
	{
		C = A + B;
		cout << C;
	}
	catch (const char* osh)
	{
		cout << osh << endl;
	}
	cout << "Zaversheno" << endl << endl;
}

void Raz()
{
	cout << "Vichitanie" << endl << "A - B" << endl;
	int n;
	cout << "Size A = ";
	cin >> n;
	TMatrix<double> A(n);
	cout << "A = " << endl;
	cin >> A;

	cout << "Size B = ";
	cin >> n;
	TMatrix<double> B(n);
	cout << "B = " << endl;
	cin >> B;

	cout << "A - B" << endl;
	TMatrix<double> C(n);
	try
	{
		C = A - B;
		cout << C;
	}
	catch (const char* osh)
	{
		cout << osh << endl;
	}
	cout << "Zaversheno" << endl << endl;
}

void Umnozh()
{
	cout << "Umnozhenie" << endl << "A * B" << endl;
	int n;
	cout << "Size A = ";
	cin >> n;
	TMatrix<double> A(n);
	cout << "A = " << endl;
	cin >> A;

	cout << "Size B = ";
	cin >> n;
	TMatrix<double> B(n);
	cout << "B = " << endl;
	cin >> B;

	cout << "A * B" << endl;
	TMatrix<double> C(n);
	try
	{
		C = A * B;
		cout << C;
	}
	catch (const char* osh)
	{
		cout << osh << endl;
	}
	cout << "Zaversheno" << endl << endl;
}

void SlConst()
{
	cout << "Slozhenie s const" << endl << "A + const" << endl;
	int n;
	cout << "Size A = ";
	cin >> n;
	TMatrix<double> A(n);
	cout << "A = " << endl;
	cin >> A;

	cout << "Const = ";
	double c;
	cin >> c;

	cout << "A + const" << endl;
	TMatrix<double> C(n);
	C = A + c;
	cout << C;
	cout << "Zaversheno" << endl << endl;
}

void MiConst()
{
	cout << "Vichitanie const" << endl << "A - const" << endl;
	int n;
	cout << "Size A = ";
	cin >> n;
	TMatrix<double> A(n);
	cout << "A = " << endl;
	cin >> A;

	cout << "Const = ";
	double c;
	cin >> c;

	cout << "A - const" << endl;
	TMatrix<double> C(n);
	C = A - c;
	cout << C;
	cout << "Zaversheno" << endl << endl;
}

void UmConst()
{
	cout << "Umnozhenie na const" << endl << "A * const" << endl;
	int n;
	cout << "Size A = ";
	cin >> n;
	TMatrix<double> A(n);
	cout << "A = " << endl;
	cin >> A;

	cout << "Const = ";
	double c;
	cin >> c;

	cout << "A * const" << endl;
	TMatrix<double> C(n);
	C = A * c;
	cout << C;
	cout << "Zaversheno" << endl << endl;
}

void UmVec()
{
	cout << "Umnozhenie na vector" << endl << "A * vec" << endl;
	int n;
	cout << "Size A = ";
	cin >> n;
	TMatrix<double> A(n);
	cout << "A = " << endl;
	cin >> A;

	cout << "Size vec = ";
	cin >> n;
	TVector<double> v(n);
	cout << "B = " << endl;
	cin >> v;

	cout << "A * vec" << endl;
	TVector<double> C(n);
	try
	{
		C = A * v;
		cout << C << endl;
	}
	catch (const char* osh)
	{
		cout << osh << endl;
	}
	cout << "Zaversheno" << endl << endl;
}

void Rav()
{
	cout << "Sravnenie na ravenstvo" << endl << "A == B" << endl;
	int n;
	cout << "Size A = ";
	cin >> n;
	TMatrix<double> A(n);
	cout << "A = " << endl;
	cin >> A;

	cout << "Size B = ";
	cin >> n;
	TMatrix<double> B(n);
	cout << "B = " << endl;
	cin >> B;

	try
	{
		if (A == B)
			cout << "A = B" << endl;
		else
			cout << "A != B" << endl;
	}
	catch (const char* osh)
	{
		cout << osh << endl;
	}
	cout << "Zaversheno" << endl << endl;
}

void Nerav()
{
	cout << "Sravnenie na neravenstvo" << endl << "A != B" << endl;
	int n;
	cout << "Size A = ";
	cin >> n;
	TMatrix<double> A(n);
	cout << "A = " << endl;
	cin >> A;

	cout << "Size B = ";
	cin >> n;
	TMatrix<double> B(n);
	cout << "B = " << endl;
	cin >> B;

	try
	{
		if (A != B)
			cout << "A != B" << endl;
		else
			cout << "A = B" << endl;
	}
	catch (const char* osh)
	{
		cout << osh << endl;
	}
	cout << "Zaversheno" << endl << endl;
}

void Pris()
{
	cout << "Prisvaivanie" << endl << "A = B" << endl;
	int n;
	cout << "Size A = ";
	cin >> n;
	TMatrix<double> A(n);
	cout << "A = " << endl;
	cin >> A;
	TMatrix<double> B(A);
	cout << B;
}

void Zav()
{
	return;
}

int main()
{
	int n;
	do
	{
		cout << "1 - Slozhenie" << endl << "2 - Vichitanie" << endl << "3 - Umnozhenie" << endl << "4 - Slozhenie s const" << endl << "5 - Vichitanie const" << endl << "6 - Umnozhenie na const" << endl << "7 - Umnozhenie na vector" << endl << "8 - Sravnenie na ravenstvo" << endl << "9 - Sravnenie na neravenstvo" << endl << "10 - Prisvaivanie" << endl << "0 - Zavershit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			Slozh();
			break;
		}
		case 2:
		{
			Raz();
			break;
		}
		case 3:
		{
			Umnozh();
			break;
		}
		case 4:
		{
			SlConst();
			break;
		}
		case 5:
		{
			MiConst();
			break;
		}
		case 6:
		{
			UmConst();
			break;
		}
		case 7:
		{
			UmVec();
			break;
		}
		case 8:
		{
			Rav();
			break;
		}
		case 9:
		{
			Nerav();
			break;
		}
		case 10:
		{
			Pris();
			break;
		}
		}
	} while (n != 0);
}