ListNode<int>* removeNthNodeFromEnd(ListNode<int>* list, int N) {
	ListNode<int> *head = list;
	while (--N) head = head->next;
	ListNode<int> *head2 = list;
	while (head) {
		head = head -> next;
		head2 = head2 -> next;
	}

	if (head2 -> next) {
		head2 -> value = head2 -> next -> value;
		head2 -> next = head2 -> next -> next;
	} else {
		head2 = NULL;
	}
	return list;
}