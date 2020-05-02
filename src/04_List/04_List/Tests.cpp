#include "Tests.h"
#include <iostream>
#include <locale.h>
using namespace std;

void TestSearch() {
    setlocale(LC_ALL, "Russian");
    cout << "TestSearch" << endl;
    int size;
    cout << "Размер: " << endl;
    cin >> size;
    double key;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "Ключ: ";
        cin >> key;
        cout << "Данные:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "Введите ключ для поиска: " << endl;
    cin >> key;
    if (list.Search(key) == 0) cout << "Элемент не найден" << endl << "Тест завершен" << endl;
    cout << *(list.Search(key)) << endl << "Тест завершен" << endl;
}

void TestPush() {
    setlocale(LC_ALL, "Russian");
    cout << "TestPush" << endl;
    int size;
    cout << "Размер: " << endl;
    cin >> size;
    double key;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "Ключ: ";
        cin >> key;
        cout << "Данные:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "Введите ключ для вставки: " << endl;
    cin >> key;
    cout << "Введите данные для вставки: " << endl;
    cin >> data;
    list.Push(key, &data);
    cout << list << endl;
    cout << "Тест завершен" << endl;
}

void TestInsertAfter() {
    setlocale(LC_ALL, "Russian");
    cout << "TestInsertAfter" << endl;
    int size;
    cout << "Размер: " << endl;
    cin >> size;
    double key, key1;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "Ключ: ";
        cin >> key;
        cout << "Данные:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "Введите ключ для поиска: " << endl;
    cin >> key1;
    cout << "Введите ключ для вставки: " << endl;
    cin >> key;
    cout << "Введите данные для вставки: " << endl;
    cin >> data;
    try {
        list.InsertAfter(key, &data, key1);
    }
    catch(const char osh) {
        cout << osh << endl;
    }
    cout << list << endl << "Тест завершен" << endl;
}

void TestInsertBefore() {
    setlocale(LC_ALL, "Russian");
    cout << "TestInsertAfter" << endl;
    int size;
    cout << "Размер: " << endl;
    cin >> size;
    double key, key1;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "Ключ: ";
        cin >> key;
        cout << "Данные:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "Введите ключ для поиска: " << endl;
    cin >> key1;
    cout << "Введите ключ для вставки: " << endl;
    cin >> key;
    cout << "Введите данные для вставки: " << endl;
    cin >> data;
    try {
        list.InsertBefore(key, &data, key1);
    }
    catch (const char* osh) {
        cout << osh << endl;
    }
    cout << list << endl << "Тест завершен" << endl;
}

void TestBack() {
    setlocale(LC_ALL, "Russian");
    cout << "TestBack" << endl;
    int size;
    cout << "Размер: " << endl;
    cin >> size;
    double key;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "Ключ: ";
        cin >> key;
        cout << "Данные:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "Введите ключ для вставки: " << endl;
    cin >> key;
    cout << "Введите данные для вставки: " << endl;
    cin >> data;
    list.Back(key, &data);
    cout << list << endl << "Тест завершен" << endl;
}

void TestCopy() {
    setlocale(LC_ALL, "Russian");
    cout << "TestCopy" << endl;
    int size;
    cout << "Размер: " << endl;
    cin >> size;
    double key;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "Ключ: ";
        cin >> key;
        cout << "Данные:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    TList<double, char> list2(list);
    cout << list2 << endl << "Тест завершен" << endl;
}

void TestRemove() {
    setlocale(LC_ALL, "Russian");
    cout << "TestRemove" << endl;
    int size;
    cout << "Размер: " << endl;
    cin >> size;
    double key;
    char data;
    TList<double, char> list;
    for (int i = 0; i < size; i++)
    {
        cout << "Ключ: ";
        cin >> key;
        cout << "Данные:  ";
        cin >> data;
        list.Back(key, &data);
    }
    cout << list << endl;
    cout << "Введите ключ для удаления: " << endl;
    cin >> key;
    try {
        list.Remove(key);
    }
    catch (const char* osh) {
        cout << osh << endl;
    }
    cout << list << endl << "Тест завершен" << endl;
}