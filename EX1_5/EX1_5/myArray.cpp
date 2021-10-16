#include "myArray.h"

//PRIVATE PART

// Comparative functions are smaller or equal
bool MY_ARRAY::increase(int a, int b) {
    return a <= b;
}

// Larger or equal comparison function
bool MY_ARRAY::decrease(int a, int b) {
    return a >= b;
}

// function merge array
void MY_ARRAY::merge(int a[], int l, int m, int r, bool (MY_ARRAY::* s)(int, int)) {

    int sizeLeft = m - l + 1;
    int sizeRight = r - m;

    // Create 2 temporary arrays to contain elements after division
    int* L = new int[sizeLeft], * R = new int[sizeRight];

    // Copy data to temporary arrays
    for (int i = 0; i < sizeLeft; i++)
        L[i] = a[l + i];
    for (int j = 0; j < sizeRight; j++)
        R[j] = a[m + 1 + j];

    // initialize the original values
    int i = 0, j = 0, k = l;

    //Combine two temporary arrays into arrays a
    for (; i < sizeLeft && j < sizeRight; k++)
        if ((this->*s)(L[i], R[j])) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }

    // Copy the remaining elements of the L array to A if available
    for (; i < sizeLeft; i++, k++)
        a[k] = L[i];

    // Copy the remaining elements of the R array into A if available
    for (; j < sizeRight; j++, k++)
        a[k] = R[j];

    delete[]L;
    delete[]R;
}

// function detached array
void MY_ARRAY::Sort(int arr[], int l, int r, bool (MY_ARRAY::* s)(int, int)) {
    // l is the left index and r is the right index of arrays to be arranged
    if (l < r) {
        int m = l + (r - l) / 2;
        // call recursive function to divide the array
        Sort(arr, l, m, s);
        Sort(arr, m + 1, r, s);

        merge(arr, l, m, r, s);
    }
}

//PUBLIC PART

MY_ARRAY::MY_ARRAY() {
    size = 0;
    pArr = nullptr;
}

MY_ARRAY::MY_ARRAY(int sz) {
    if (sz <= 0) {
        this->size = 0;
        pArr = nullptr;
        return;
    }
    this->size = sz;
    pArr = new int[size];
    for (int i = 0; i < size; i++)
        *(pArr + i) = 0;
}

MY_ARRAY::~MY_ARRAY() {
    if (size > 0) {
        size = 0;
        delete pArr;
        pArr = nullptr;
    }
}

//  Function takes the position of the element
int MY_ARRAY::operator[](int idx) {
    return pArr[idx];
}

// Function copy the size and element of the array
void MY_ARRAY::copyArray(MY_ARRAY& arrayNew) {
    arrayNew.size = this->size;
    arrayNew.pArr = new int[arrayNew.size];
    for (int i = 0; i < this->size; i++)
        arrayNew.pArr[i] = this->pArr[i];
}

// Function takes the size of array
int MY_ARRAY::getSize() {
    return size;
}

// Function find a value in array
int MY_ARRAY::find(int value) {
    for (int i = 0; i < size; i++)
        if (pArr[i] == value) return i;

    return -1;
}

// Function array increases gradually
void MY_ARRAY::sortIncrease() {
    Sort(this->pArr, 0, this->size - 1, &MY_ARRAY::increase);
}

// Function array decrease gradually
void MY_ARRAY::sortDecrease() {
    Sort(this->pArr, 0, this->size - 1, &MY_ARRAY::decrease);
}

//-------Friend--------
// Function input array
istream& operator>>(istream& is, MY_ARRAY& array) {
    array.~MY_ARRAY();
    do {
        cout << "Enter the number of pArr: ";
        is >> array.size;
        if (array.size < 0)
            cout << "number of pArr must bigger or equal 0, please re_enter\n\n";
    } while (array.size < 0);
    array.pArr = new int[array.size];

    for (int i = 0; i < array.size; i++) {
        cout << "a[" << i << "] = ";
        is >> array.pArr[i];
    }
    return is;
}

// Function output array
ostream& operator<<(ostream& os, MY_ARRAY& array) {
    for (int i = 0; i < array.size; i++)
        cout << array.pArr[i] << " ";
    return os;
}