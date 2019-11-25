#pragma once
#include "TVector.h"

template<typename ValueType>
class TMatrix : public TVector<TVector<ValueType> >
{
public:
	TMatrix(int _size = 10);
	TMatrix(const TMatrix& mat);
	TMatrix(const TVector<TVector<ValueType> >& mat);
	~TMatrix();
	TMatrix operator+(const ValueType a);
	TMatrix operator-(const ValueType a);
	TMatrix operator*(const ValueType a);
	TMatrix operator+(const TMatrix& mat);
	TMatrix operator-(const TMatrix& mat);
	TMatrix operator*(const TMatrix& mat);
	TVector<ValueType> operator*(const TVector<ValueType>& mat);
	TMatrix& operator=(const TMatrix& mat);
	bool operator==(const TMatrix& mat)const;
	bool operator!=(const TMatrix& mat)const;

	friend istream& operator>>(istream& in, TMatrix<ValueType>& mat)
	{
		for (int i = 0; i < mat.size; i++)
			in >> mat.arr[i];
		return in;
	}
	friend ostream& operator<<(ostream & out, const TMatrix<ValueType> & mat)
	{
		for (int i = 0; i < mat.size; i++)
			out << mat[i] << endl;
		return out;
	}
};

template<typename ValueType>
TMatrix<ValueType>::TMatrix(int _size):TVector<TVector<ValueType> >(_size)
{
	this->size = _size;
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = TVector<ValueType>(this->size - i, i);
	}
}

template<typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix<ValueType> & mat):TVector<TVector<ValueType> >(mat)
{}

template<typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType> > & mat):TVector<TVector<ValueType> >(mat)
{}

template<typename ValueType>
TMatrix<ValueType>::~TMatrix()
{}

template<typename ValueType>
TMatrix<ValueType>& TMatrix<ValueType>::operator=(const TMatrix<ValueType> & mat)
{
	if (*this == mat)
		return *this;
	if (this->size != mat.size)
	{
		this->size = mat.size;
		delete this->arr;
		this->arr = new TVector<ValueType>[mat.size];
	}
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = mat.arr[i];
		this->arr[i].SSI(i);
	}
	return *this;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const ValueType a)
{
	TMatrix<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] + a;
	return rez;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const ValueType a)
{
	TMatrix<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] - a;
	return rez;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const ValueType a)
{
	TMatrix<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] * a;
	return rez;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const TMatrix & mat)
{
	if (this->size != mat.size)
		throw "SZ";
	TMatrix<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] + mat.arr[i];
	return rez;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const TMatrix & mat)
{
	if (this->size != mat.size)
		throw "SZ";
	TMatrix<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] - mat.arr[i];
	return rez;
}

template<typename ValueType>
bool TMatrix<ValueType>::operator==(const TMatrix & mat)const
{
	if (this->size != mat.size)
		return false;
	for (int i = 0; i < this->size; i++)
		if (this->arr[i] != mat.arr[i])
			return false;
	return true;
}

template<typename ValueType>
bool TMatrix<ValueType>::operator!=(const TMatrix & mat)const
{
	return (!(*this == mat));
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix & mat)
{
	if (this->size != mat.size)
		throw "SZ";
	TMatrix<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		for (int j = this->arr[i].GetStartInd(); j < this->size; j++)
		{
			rez.arr[i][j - i] = 0.0;
			for (int s = i; s <= j; s++)
				rez.arr[i][j - i] += this->arr[i][s - i] * mat.arr[s][j - s];
		}
	return rez;
}

template<typename ValueType>
TVector<ValueType> TMatrix<ValueType>::operator*(const TVector<ValueType> & mat)
{
	if (this->GetSize() != mat.GetSize())
		throw "SZ";
	TVector<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
	{
		rez[i] = 0;
		for (int j = 0; j < this->arr[i].GetSize(); j++)
			rez[i] += this->arr[i][j] * mat[i + j];
	}
	return rez;
}