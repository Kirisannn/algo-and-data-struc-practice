/** Practice script for designing dynamic arrays. */
#include <iostream>
using namespace std;

int main() {
    // int staticArray[5];	// Basic static array of size 5
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* dynamicArray = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Set dynamicArray[" << i << "] = ";
        cin >> dynamicArray[i];
    }

    for (auto i = 0; i < size; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    delete[] dynamicArray;
    dynamicArray = nullptr;

    cout << "====== DynamicArrays Finished ======" << endl
         << endl;
    return 0;
}