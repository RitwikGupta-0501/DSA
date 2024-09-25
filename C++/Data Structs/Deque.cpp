#include <iostream>
using namespace std;

class Deque {
    private:
        int size;
        int* queue;
        int front;
        int rear;
    
    public:
        Deque(int size) {
            this->queue = new int[size];
            this->front = -1;
            this->rear = -1;
            this->size = size;
        }

        bool isFull() {
            return (this->front == (this->rear+1)%this->size);
        }

        bool isEmpty() {
            return (this->front == -1);
        }

        void push_back(int element) {
            if (this->isFull()) {
                cout << "Queue is Full." << endl;
                return;
            }
            
            if (this->front == -1) {
                front = 0;
            }
            this->rear = (this->rear+1)%this->size;
            this->queue[this->rear] = element;
            return;
        }

        int pop_front() {
            if (this->isEmpty()) {
                cout << "Queue is Empty. " << endl;
                return;
            }

            int element = this->queue[this->front];
            if (this->front == this->rear) {
                this->front = -1;
                this->rear = -1;
            }
            else {
                this->front = (this->front+1) % this->size;
            }
            return element;
        }

        void push_front(int element) {
            if (this->isFull()) {
                cout << "Queue is Full." << endl;
                return;
            }
            
            if (this->front == -1) {
                this->front = 0;
                this->rear = 0;
            }
            else if (this->front == 0) this->front = this->size-1;
            else this->front--;
            this->queue[this->front] = element;
            return;
        }

        int pop_back() {
            if (this->isEmpty()) {
                cout << "Queue is Empty. " << endl;
                return;
            }

            int element = this->queue[this->rear];
            if (this->front == this->rear) {
                this->front = -1;
                this->rear = -1;
            }
            else if (this->rear == 0) this->rear = this->size-1;
            else this->rear--;
            return element;
        }

        void display() {
            if (this->isEmpty()) cout << "Queue is Empty." << endl;
            else {
                int i;
                for (i=this->front; i != this->rear; i = (i+1) % this->size) {
                    cout << this->queue[i] << " ";
                }
                cout << this->queue[i] <<  endl;
            }
            return;
        }
};