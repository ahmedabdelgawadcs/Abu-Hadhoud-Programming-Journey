#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void insert_at_beginning(Node* &head, int data) {
	Node* new_node = new Node;

	new_node->data = data;
	new_node->next = head;

	head = new_node;
}

// Insert at the end
void insert_at_end(Node* &head, int data) {
	Node* new_node = new Node;

	new_node->data = data;
	new_node->next = NULL;

	if (head == NULL)
		head = new_node;
	else {
		Node* last_node = head;

		while (last_node->next != NULL)
			last_node = last_node->next;

		last_node->next = new_node;
	}
}

void print_list(Node* head) {
	while (head != NULL) {
		cout << head->data << ' ';
		head = head->next;
	}
}

int main() {
	Node* head = NULL;

	insert_at_end(head, 1);
	insert_at_end(head, 2);
	insert_at_end(head, 3);

	insert_at_beginning(head, 0);

	print_list(head);

	system("pause > 0");

	return 0;
}