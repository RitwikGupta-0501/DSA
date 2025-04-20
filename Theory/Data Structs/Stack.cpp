#include <iostream>
using namespace std;

class Stack {
    private:
        int *arr;
        int top;
        int capacity;
    
    public: 
        Stack(int capacity) {
            arr = new int[this->capacity];
            this->top = -1;
        }
        ~Stack() {
            delete this->arr;
        }

        bool isEmpty() {
            return this->top == -1;
        }

        bool isFull() {
            return this->top+1 == this->capacity;
        }

        void push(int element) {
            if (!this->isFull()) {
                this->arr[++top] = element;
            }
            else {
                cout << "ERROR: Overflow." << endl;
            }
        }

        void pop() {
            if (!this->isEmpty()) {
                cout << this->arr[top--];
            }
            else {
                cout << "ERROR: Underflow.";
            }
        }

        int peek() {
            return this->arr[top];
        }
};

int main() {

    return 0;
}