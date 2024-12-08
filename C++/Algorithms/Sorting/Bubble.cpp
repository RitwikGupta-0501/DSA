#include <bits/stdc++.h>
using namespace std;

template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j=0; j < size-1-i; j++) {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
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
    int arr[] = {2, 6, 1, 3, 5, 6};
    display(arr, 6);
    bubbleSort(arr, 6);
    display(arr, 6);
    return 0;
}