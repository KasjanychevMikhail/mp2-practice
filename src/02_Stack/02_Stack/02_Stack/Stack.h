#pragma once

template<class ValueType>
class TStack
{
private:
	int size;
	ValueType *arr;
	int top;
public:
	TStack(int _size = 10);
	TStack(const TStack<ValueType>& tmp);
	~TStack();
	void Push(ValueType c);
	void Pop();
	ValueType Top() const;
	TStack& operator=(const TStack& tmp);
	bool IsFull()const;
	bool IsEmpty()const;
};

template<class ValueType>
TStack<ValueType>::TStack(int _size)
{
	size = _size;
	top = -1;
	arr = new ValueType[size];
}

template<class ValueType>
TStack<ValueType>::TStack(const TStack<ValueType>& tmp)
{
	size = tmp.size;
	top = tmp.top;
	arr = new ValueType[size];
	for (int i = 0; i < size; i++)
		arr[i] = tmp.arr[i];
}

template<class ValueType>
TStack<ValueType>::~TStack()
{
	size = 0;
	top = -1;
	delete[] arr;
}

template<class ValueType>
void TStack<ValueType>::Push(ValueType c)
{
	if (this->IsFull())
		throw "Full";
	arr[++top] = c;
}

template<class ValueType>
void TStack<ValueType>::Pop()
{
	if (this->IsEmpty())
		throw "Empty";
	top--;
}

template<class ValueType>
ValueType TStack<ValueType>::Top() const
{
	if (this->IsEmpty())
		throw "Empty";
	return arr[top];
}