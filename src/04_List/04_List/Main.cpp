#include "Tests.h"
#include <stdio.h>
#include <locale.h>
using namespace std;

void main() {
    setlocale(LC_ALL, "Russian");
    int rezh;
    do {
        cout << "Выберите тест" << endl;
        cout << "1 - Search" << endl << "2 - Push" << endl << "3 - InsertAfter" << endl << "4 - InsertBefore" << endl << "5 - Back" << endl << "6 - Copy" << endl << "7 - Remove" << endl << "0 - Выход" << endl;
        cin >> rezh;
        switch (rezh) {
        case 1: {
            TestSearch();
            rezh = -1;
            break;
        }
        case 2: {
            TestPush();
            rezh = -1;
            break;
        }
        case 3: {
            TestInsertAfter();
            rezh = -1;
            break;
        }
        case 4: {
            TestInsertBefore();
            rezh = -1;
            break;
        }
        case 5: {
            TestBack();
            rezh = -1;
            break;
        }
        case 6: {
            TestCopy();
            rezh = -1;
            break;
        }
        case 7: {
            TestRemove();
            rezh = -1;
            break;
        }
        }
    } while (rezh != 0);
}