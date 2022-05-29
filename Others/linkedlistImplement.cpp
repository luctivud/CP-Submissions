#include <bits/stdc++.h>
using namespace std;

class LinkedListNode {
public:
    int value;
    LinkedListNode* next;
    LinkedListNode() {
        value = 0;
        next = NULL;
    }
    LinkedListNode(int m_value) : value(m_value) { }
    LinkedListNode(int m_value, LinkedListNode* m_next) : value(m_value), next(m_next) { }
    void addToNext(LinkedListNode* nextNodePointer) {
        this->next = nextNodePointer;
    }
};

void PrintLinkedList(LinkedListNode* head) {
    while (head != NULL) {
        cout << head->value << " "; 
        head = head->next;
    }
}


int main() {
    LinkedListNode* node = new LinkedListNode(0);
    LinkedListNode* node2 = new LinkedListNode(1);
    node->addToNext(node2);
    PrintLinkedList(node);
    return 0;
}