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
    public:
        ListNode* head;

    public:
        LinkedList(ListNode* head_param){
            if (head == nullptr){
                head = head_param;
            }
        }
};