#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

void insert_at_beginning(Node*& head, int value) {
	// Allocate memory to a node
	Node* node = new Node;

	// insert the data
	node->value = value;
	node->next = head;

	// Move head to new node
	head = node;
}

// Print the linked list
void print_list(Node* head) {
	while (head != NULL) {
		cout << head->value << ' ';
		head = head->next;
	}
}

int main() {
	Node* head = NULL; // NULL

	insert_at_beginning(head, 1); 
	insert_at_beginning(head, 2);
	insert_at_beginning(head, 3);
	insert_at_beginning(head, 4);
	insert_at_beginning(head, 5);

	print_list(head);

	system("pause > 0");

	return 0;
}