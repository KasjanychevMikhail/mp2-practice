#include "Tests.h"
#include <stdio.h>
#include <locale.h>
using namespace std;

void main() {
    setlocale(LC_ALL, "Russian");
    int rezh;
    cout << "Выберите тест" << endl;
    cout << "1 - Search" << endl << "2 - Push" << endl << "3 - InsertAfter" << endl << "4 - InsertBefore" << endl << "5 - Back" << endl << "6 - Copy" << endl << "7 - Remove" << endl << "0 - Выход" << endl;
    cin >> rezh;
    switch (rezh) {
    case 1: {
        TestSearch();
        break;
    }
    case 2: {
        TestPush();
        break;
    }
    case 3: {
        TestInsertAfter();
        break;
    }
    case 4: {
        TestInsertBefore();
        break;
    }
    case 5: {
        TestBack();
        break;
    }
    case 6: {
        TestCopy();
        break;
    }
    case 7: {
        TestRemove();
        break;
    }
    case 0: {
        return;
    }
    }
}