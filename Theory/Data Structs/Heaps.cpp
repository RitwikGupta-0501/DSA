#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Heap {
private:
    T* arr;
    int size;
    int capacity;

    int parent(int child) {
        return (child - 1) / 2;
    }

    int left(int parent) {
        return 2 * parent + 1;
    }

    int right(int parent) {
        return 2 * parent + 2;
    }

    void maxHeapify(int index) {
        int largest = index;
        int l = left(index);
        int r = right(index);

        if (l < size && arr[l] > arr[largest]) {
            largest = l;
        }

        if (r < size && arr[r] > arr[largest]) {
            largest = r;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            maxHeapify(largest);
        }
    }

public:
    Heap(int cap) : size(0), capacity(cap) {
        arr = new T[cap];
    }

    ~Heap() {
        delete[] arr;
    }

    void buildMaxHeap(T array[], int inputSize) {
        if (inputSize > capacity) {
            cout << "Input array exceeds heap capacity." << endl;
        }

        for (int i = 0; i < inputSize; i++) {
            arr[i] = array[i];
        }

        size = inputSize;

        for (int i = (size - 1) / 2; i >= 0; i--) {
            maxHeapify(i);
        }
    }
};