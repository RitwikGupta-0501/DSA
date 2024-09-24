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

class LinkedList {
    private:
        ListNode* head;

    public:
        LinkedList(){
            this->head = nullptr;
        }

        void reverse() {
            ListNode* prev = nullptr;
            ListNode* current = this->head;
            while (current != nullptr) {
                ListNode* forward = current->next;
                current->next = prev;
                prev = current;
                current = forward;
            }
            this->head = prev;
        }

        void insert_at_end(ListNode* node) {
            if (this->head == nullptr) {
                this->head = node;
            }
            else {
                ListNode* current = this->head;

                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = node;
            }
            return;
        }

        void insert_at_beginning(ListNode* node) {
            if (this->head == nullptr) {
                this->head = node;
            }
            else {
                node->next = this->head;
                this->head = node;
            }
            return;
        }

        void insert_at_position(ListNode* node, int pos) {
            if (this->head == nullptr) {
                this->head = node;
            }
            else {
                ListNode* current = this->head;
                for (int i=0; i<pos-1 && current != nullptr; i++) {
                    current = current->next;
                }
                if (current == nullptr) {
                    cout << "Position out of bounds, inserting at the end." << endl;
                    this->insert_at_end(node);
                }
                else {
                    node->next = current->next;
                    current->next = node;
                }
            }
            return;
        }

        void insert_after_value(ListNode* node, int value) {
            if (this->head == nullptr) {
                this->head = node;
            }
            else {
                ListNode* current = this->head;
                while(current != nullptr && current->data != value) {
                    current = current->next;
                }
                if (current == nullptr) {
                    cout << "Value doesn't Exits";
                }
                else {
                    node->next = current->next;
                    current->next = node;
                }
            }
            return;
        }

        void delete_value(int value) {
            if (this->head == nullptr) {
               cout << "Linked List is Empty.";
            }
            else if (this->head->data == value) {
                this->head = this->head->next;
            }
            else {
                ListNode* current = this->head;
                while (current->next != nullptr && current->next->data != value) {
                    current = current->next;
                }
                if (current->next == nullptr) {
                    cout << "Node not found";
                }
                else {
                    current->next = current->next->next;
                }
            }
        }

        void delete_index(int index) {
            if (this->head == nullptr) {
               cout << "Linked List is Empty.";
            }
            else if (this->head->data == value) {
                this->head = this->head->next;
            }
            else {
                ListNode* current = this->head;
                while (current->next != nullptr && current->next->data != value) {
                    current = current->next;
                }
                if (current->next == nullptr) {
                    cout << "Node not found";
                }
                else {
                    current->next = current->next->next;
                }
            }
        }

        void display() {
            ListNode* current = this->head;

            if (this->head == nullptr) {
                cout << "Enpty list." << endl;
                return;
            }

            while(current != nullptr) {
                cout << current->data << ' ';
                current = current->next;
            }
        }
};

int main() {
    LinkedList l;
    ListNode n1(1);
    l.insert_at_beginning(&n1);
    ListNode n2(2);
    l.insert_at_beginning(&n2);
    ListNode n3(3);
    l.insert_at_end(&n3);
    ListNode n4(4);
    l.insert_at_end(&n4);
    l.display();
    cout << endl << "Reversed" << endl;
    l.reverse();
    l.display();
}