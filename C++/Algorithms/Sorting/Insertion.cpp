#include <bits/stdc++.h>
using namespace std;

template <typename T>
void insertionSort(T arr[], int size) {
    for (int i=1; i < size; i++) {
        int j=i-1;
        int key = arr[i];
        while (j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

template <typename T>
void display(T arr[], int size) {
    for (int i=0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 4, 6, 1, 4, 7};
    display(arr, 6);
    insertionSort(arr, 6);
    display(arr, 6);
    return 0;
}