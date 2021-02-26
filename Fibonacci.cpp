#include <iostream>
#include <fstream>
using namespace std;

int* FIB(int FIB_NUMBER) {
    int* arr = new int[FIB_NUMBER];
    memset(arr, 0, 4 * FIB_NUMBER); 
    arr[0] = arr[1] = 1;
    for (int i = 2; i < FIB_NUMBER; i++) {
        if (INT_MAX - arr[i - 1] < arr[i - 2]) {
            return arr;
        }
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr;
}

int main()
{
    int number = 0;
    int* fibs;
    while (number <= 0) {
        cout << "Enter a number: ";
        cin >> number;
    }
    if (number == 1) {  //в любом случае придется отдельно описывать этот случай, так зачем вызывать функцию
        cout << 1;
        return 0;
    }
    fibs = FIB(number); //чтобы не выполнять функцию каждый раз
    for (int i = 0; i < number; i++) {
        if (fibs[i] == 0) {
            cout << endl << "Last number was on: " << i - 2 << " position";
            return 0;
        }
        cout << fibs[i] << " ";
    }
    return 0;
}
