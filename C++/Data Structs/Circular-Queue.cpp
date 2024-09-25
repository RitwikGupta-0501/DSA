#include <iostream>
using namespace std;

class CircularQueue {
    private:
        int size;
        int* queue;
        int front;
        int rear;
    
    public:
        CircularQueue(int size) {
            this->queue = new int[size];
            this->front = -1;
            this->rear = -1;
        }

        bool isFull() {
            return (this->front == (this->rear+1)%this->size);
        }

        bool isEmpty() {
            return (this->front == -1);
        }

        void enqueue(int element) {
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

        int dequeue() {
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

        void display() {
            if (this->isEmpty()) cout << "Queue is Empty." << endl;
            else {
                int i;
                for (i=this->front; i != this->rear; i = (i+1) % this->size) {
                    cout << this->queue[i] << " ";
                }
                cout << this->queue[i];
            }
            return;
        }
};