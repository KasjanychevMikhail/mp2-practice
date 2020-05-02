#include "Tests.h"
#include <iostream>
#include <locale.h>
using namespace std;

void TestSearch() {
    setlocale(LC_ALL, "Russian");
    cout << "TestSearch" << endl;
    int size;
    cout << "������: " << endl;
    cin >> size;
    double key;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "����: ";
        cin >> key;
        cout << "������:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "������� ���� ��� ������: " << endl;
    cin >> key;
    if (list.Search(key) == 0) cout << "������� �� ������" << endl << "���� ��������" << endl;
    cout << *(list.Search(key)) << endl << "���� ��������" << endl;
}

void TestPush() {
    setlocale(LC_ALL, "Russian");
    cout << "TestPush" << endl;
    int size;
    cout << "������: " << endl;
    cin >> size;
    double key;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "����: ";
        cin >> key;
        cout << "������:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "������� ���� ��� �������: " << endl;
    cin >> key;
    cout << "������� ������ ��� �������: " << endl;
    cin >> data;
    list.Push(key, &data);
    cout << list << endl;
    cout << "���� ��������" << endl;
}

void TestInsertAfter() {
    setlocale(LC_ALL, "Russian");
    cout << "TestInsertAfter" << endl;
    int size;
    cout << "������: " << endl;
    cin >> size;
    double key, key1;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "����: ";
        cin >> key;
        cout << "������:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "������� ���� ��� ������: " << endl;
    cin >> key1;
    cout << "������� ���� ��� �������: " << endl;
    cin >> key;
    cout << "������� ������ ��� �������: " << endl;
    cin >> data;
    try {
        list.InsertAfter(key, &data, key1);
    }
    catch(const char osh) {
        cout << osh << endl;
    }
    cout << list << endl << "���� ��������" << endl;
}

void TestInsertBefore() {
    setlocale(LC_ALL, "Russian");
    cout << "TestInsertAfter" << endl;
    int size;
    cout << "������: " << endl;
    cin >> size;
    double key, key1;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "����: ";
        cin >> key;
        cout << "������:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "������� ���� ��� ������: " << endl;
    cin >> key1;
    cout << "������� ���� ��� �������: " << endl;
    cin >> key;
    cout << "������� ������ ��� �������: " << endl;
    cin >> data;
    try {
        list.InsertBefore(key, &data, key1);
    }
    catch (const char* osh) {
        cout << osh << endl;
    }
    cout << list << endl << "���� ��������" << endl;
}

void TestBack() {
    setlocale(LC_ALL, "Russian");
    cout << "TestBack" << endl;
    int size;
    cout << "������: " << endl;
    cin >> size;
    double key;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "����: ";
        cin >> key;
        cout << "������:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "������� ���� ��� �������: " << endl;
    cin >> key;
    cout << "������� ������ ��� �������: " << endl;
    cin >> data;
    list.Back(key, &data);
    cout << list << endl << "���� ��������" << endl;
}

void TestCopy() {
    setlocale(LC_ALL, "Russian");
    cout << "TestCopy" << endl;
    int size;
    cout << "������: " << endl;
    cin >> size;
    double key;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "����: ";
        cin >> key;
        cout << "������:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    TList<double, char> list2(list);
    cout << list2 << endl << "���� ��������" << endl;
}

void TestRemove() {
    setlocale(LC_ALL, "Russian");
    cout << "TestRemove" << endl;
    int size;
    cout << "������: " << endl;
    cin >> size;
    double key;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "����: ";
        cin >> key;
        cout << "������:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "������� ���� ��� ��������: " << endl;
    cin >> key;
    try {
        list.Remove(key);
    }
    catch (const char* osh) {
        cout << osh << endl;
    }
    cout << list << endl << "���� ��������" << endl;
}