#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    ListNode * next = NULL;
    int data = 0;
};

int main() {
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *head1Copy = head1;
    ListNode *head2Copy = head2;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int value; cin >> value;
        ListNode * node = NULL;
        node->data = value;
        node->next = NULL;
        head1Copy->next = node;
        head1Copy= head1Copy->next;
    }

    int m; cin >> m;
    
    for (int i = 0; i < m; i++) {
        int value; cin >> value;
        ListNode * node = NULL;
        node->data = value;
        node->next = NULL;
        head2Copy->next = node;
        head2Copy = head2Copy->next;
    }

    head1Copy = head1;
    head2Copy = head2;

    ListNode *ansHead = NULL;
    ListNode *ansHeadCopy = ansHead;

    int i = 0, j = 0;
    while (i < n and j < m) {
        ListNode * node = NULL;
        if (head1Copy->data < head2Copy->data) {
            node->data = head1Copy->data;
            i++;
        } else if (head1Copy->data > head2Copy->data) {
            node->data = head2Copy->data;
            j++;
        } else {
            node->data = head2Copy->data;
            i++;
            j++;
        }
        ansHead->next = node;
        ansHead = ansHead->next;
    }

    while (i < n) {
        ListNode * node = NULL;
        node->data = head1Copy->data;
        i++;  
        ansHead->next = node;
        ansHead = ansHead->next;  
    }

    while (j < m) {
        ListNode * node = NULL;
        node->data = head2Copy->data;
        j++;
        ansHead->next = node;
        ansHead = ansHead->next;
    }

    while (ansHeadCopy != NULL) {
        cout << ansHeadCopy->data << " ";
    }

    return 0;
}