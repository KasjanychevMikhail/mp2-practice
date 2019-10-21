#pragma once
#include <math.h>
#include <iostream>

using namespace std;

template <typename ValueType>
class TVector
{
protected:
	int size;
	ValueType* arr;
	int startIndex;
public:
	TVector();
	TVector(int _size, int _startIndex);
	TVector(const TVector&);
	~TVector();

	ValueType Len() const;
	TVector& operator=(const TVector&);
	TVector operator+(ValueType a);
	TVector operator-(ValueType a);
	TVector operator*(ValueType a);
	TVector operator+(const TVector& vec);
	TVector operator-(const TVector& vec);
	ValueType operator*(const TVector& vec);
	bool operator==(const TVector& vec) const;
	bool operator!=(const TVector& vec) const;
	ValueType& operator[](int i);
	const ValueType& operator[](int i) const;

	int GetStartInd() const;
	int GetSize() const;

	friend istream& operator>>(istream& in, TVector<ValueType>& vec)
	{
		for (int i = 0; i < vec.size; i++)
			in >> vec.arr[i];
		return in;
	}
	friend ostream& operator<<(ostream & out, const TVector<ValueType> & vec)
	{
		for (int i = 0; i < vec.startIndex; i++)
			out << "0 ";
		for (int i = 0; i < vec.size; i++)
			out << vec.arr[i] << " ";
		return out;
	}
};

template <typename ValueType>
TVector<ValueType>::TVector()
{}
template <typename ValueType>
TVector<ValueType>::TVector(int _size, int _startIndex)
{
	this->size = _size;
	this->startIndex = _startIndex;
	this->arr = new ValueType[this->size];
}
template <typename ValueType>
TVector<ValueType>::TVector(const TVector<ValueType> & vec)
{
	this->size = vec.size;
	this->startindex = vec.startindex;
	this->arr = new ValueType[this->size];
	for (int i = 0; i < this->size; i++)
		this->arr[i] = vec.arr[i];
}
template <typename ValueType>
TVector<ValueType>::~TVector()
{
	this->size = 0;
	delete[] this->arr;
}
template <typename ValueType>
ValueType TVector<ValueType>::Len() const
{
	ValueType rez = 0;
	for (int i = 0; i < this->size; i++)
		rez += this->arr[i] * this->arr[i];
	return sqrt(rez);
}
template <typename ValueType>
TVector<ValueType>& TVector<ValueType>::operator=(const TVector<ValueType> & vec)
{
	if (vec == *this)
		return *this;
	if (size != vec.size)
	{
		delete[] arr;
		size = vec.size;
		arr = new ValueType[size];
	}
	memcpy(vec.arr, arr, sizeof(ValueType) * size);
	return *this;
}
template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(ValueType a)
{
	TVector<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] += a;
	return rez;
}
template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(ValueType a)
{
	TVector<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] -= a;
	return rez;
}
template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(ValueType a)
{
	TVector<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] *= a;
	return rez;
}
template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const TVector<ValueType> & vec)
{
	if (this->startIndex != vec.startIndex)
		throw "SI";
	if (this->size != vec.size)
		throw "SZ";
	TVector<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] + vec.arr[i];
	return rez;
}
template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const TVector<ValueType>& vec)
{
	if (this->startIndex != vec.startIndex)
		throw "SI";
	if (this->size != vec.size)
		throw "SZ";
	TVector<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] - vec.arr[i];
	return rez;
}
template <typename ValueType>
ValueType TVector<ValueType>::operator*(const TVector& vec)
{
	if (this->startIndex != vec.startIndex)
		throw "SI";
	if (this->size != vec.size)
		throw "SZ";
	ValueType rez = 0;
	for (int i = 0; i < this->size; i++)
		rez += this->arr[i] * vec.arr[i];
	return rez;
}
template<typename ValueType>
bool TVector<ValueType>::operator==(const TVector<ValueType>& vec)const
{
	if ((this->size != vec.size) || (this->startIndex != vec.startIndex))
		return false;
	for (int i = 0; i < vec.size; i++)
		if (this->arr[i] != vec.arr[i])
			return false;
	return true;
}
template<typename ValueType>
bool TVector<ValueType>::operator!=(const TVector<ValueType>& vec)const
{
	if ((this->size != vec.size) || (this->startIndex != vec.startIndex))
		return true;
	for (int i = 0; i < vec.size; i++)
		if (this->arr[i] != vec.arr[i])
			return true;
	return false;
}
template<typename ValueType>
ValueType& TVector<ValueType>::operator[](int i)
{
	if ((i < 0) || (i >= this->size))
		throw "No el";
	return this->arr[i];
}
template<typename ValueType>
const ValueType& TVector<ValueType>::operator[](int i) const
{
	if ((i < 0) || (i >= this->size))
		throw "No el";
	return this->arr[i];
}
template<typename ValueType>
int TVector<ValueType>::GetStartInd()const
{
	return this->startIndex;
}
template<typename ValueType>
int TVector<ValueType>::GetSize()const
{
	return this->size;
}