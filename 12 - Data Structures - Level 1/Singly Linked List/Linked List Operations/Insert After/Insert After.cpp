#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void insert_at_beginning(Node* &head, int val) {
	Node* new_node = new Node;

	new_node->data = val;
	new_node->next = head;

	head = new_node;
}

Node* find(Node* head, int val) {
	while (head != NULL) {
		if (head->data == val)
			break;

		head = head->next;
	}

	return head;
}

// Insert a node after a node
void insert_after(Node* prev_node, int data) {
	Node* new_node = new Node;

	if (prev_node == NULL) {
		cout << "the given previous node cannot be NULL" << endl;
		return;
	}

	new_node->data = data;
	new_node->next = prev_node->next;

	prev_node->next = new_node;
}

void print_list(Node* head) {
	while (head != NULL) {
		cout << head->data << ' ';
		head = head->next;
	}
}

int main() {
	Node* head = NULL;

	insert_at_beginning(head, 10);

	insert_after(find(head, 10), 11);

	insert_at_beginning(head, 20);

	print_list(head);

	system("pause > 0");

	return 0;
}