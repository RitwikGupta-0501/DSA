#include <iostream>

using namespace std;

class ListNode
{
    public:
        int data;
        ListNode* next;

        ListNode(int data_param) { 
            data = data_param;
            next = nullptr;
        }  
};

class CircularLinkedList {
    private:
        ListNode* head; 
        ListNode* tail;

    public:
        CircularLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void display() {
            ListNode* current = this->head;
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != this->head);
            cout << endl;
            return;
        }

        void insert_at_beginning(ListNode* node) {
            if (this->head == nullptr) {
                this->head = node;
                node->next = node;
                this->tail = node;
            }
            else {
                node->next = this->head;
                this->tail->next = node;
                this->head = node;
            }
            return;
        }

        void insert_at_tail(ListNode* node) {
            if (this->head == nullptr) {
                this->head = node;
                node->next = node;
                this->tail = node;
            }
            else {
                node->next = this->head;
                this->tail->next = node;
                this->tail = node;
            }
            return;
        }

        void delete_value(int value) {
            if (this->head == nullptr) {
                cout << "CLL is Empty." << endl;
                return;
            }

            if (this->head->data == value) {
                if (this->head == this->tail) {  // Only one node in the list
                    this->head = nullptr;
                    this->tail = nullptr;
                } else {
                    this->tail->next = this->head->next;
                    this->head = this->head->next;
                }
                return;
            }

            ListNode* current = this->head;
            do {
                if (current->next->data == value) {  

                    if (current->next == this->tail) {
                        this->tail = current;
                    }
                    current->next = current->next->next;
                    return;
                }
                current = current->next;
            } while (current != this->head);

            cout << "Value not found :(" << endl;
        }

        void delete_index(int index) {
            if (this->head == nullptr) {
                cout << "CLL is Empty." << endl;
                return;
            }
            else {
                if (index == 1) {
                    if (this->head == this->tail) {
                        this->head = nullptr;
                        this->tail = nullptr;
                    }
                    else {
                        this->tail->next = this->head->next;
                        this->head = this->head->next;
                    }
                    return;
                }
                
                ListNode* current = this->head;
                int count = 1;
                do {

                    if (count == index-1) {
                        if (current->next == this->tail) {
                            this->tail = current;
                        }
                        current->next = current->next->next;
                        return;
                    }

                    current = current->next;
                    count++;
                } while (current != this->head);

                cout << "Index Out of Range." << endl;
            }
        }
};

int main() {
    CircularLinkedList cll;
    int test;

    // Insert nodes at the tail
    cll.insert_at_tail(new ListNode(10));
    cll.insert_at_tail(new ListNode(20));
    cll.insert_at_tail(new ListNode(30));
    cll.insert_at_tail(new ListNode(40));

    // Display the list
    cout << "Circular Linked List after insertions: ";
    cll.display();

    // Delete node by index
    cout << "Deleting node at value 30:" << endl;
    cll.delete_value(30);
    cout << "List after deletion: ";
    cll.display();

    // Delete head
    cout << "Deleting node at index 1 (head):" << endl;
    cll.delete_index(1);
    cout << "List after deleting head: ";
    cll.display();

    // Delete tail
    cout << "Deleting node at index 2 (which is now the tail):" << endl;
    cll.delete_index(2);
    cout << "List after deleting tail: ";
    cll.display();

    // Try deleting at an out-of-range index
    cout << "Trying to delete at an out-of-range index (10):" << endl;
    cll.delete_index(10);
    cout << "Final List: ";
    cll.display();

    return 0;
}