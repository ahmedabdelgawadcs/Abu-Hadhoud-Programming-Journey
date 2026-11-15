#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

void insert_at_beginning(Node*& head, int val) {
	Node* new_node = new Node;

	new_node->value = val;
	new_node->next = head;

	head = new_node;
}

Node* find(Node* head, int val) {
	while (head != NULL) {
		if (head->value == val)
			break;

		head = head->next;
	}

	return head;
}

void print_list(Node* head) {
	while (head != NULL) {
		cout << head->value << ' ';
		head = head->next;
	}
}

int main() {
	Node* head = NULL;

	insert_at_beginning(head, 1);
	insert_at_beginning(head, 2);
	insert_at_beginning(head, 3);
	insert_at_beginning(head, 4);
	insert_at_beginning(head, 5);

	print_list(head);

	Node* n1 = find(head, 2);

	cout << "\n\n" << (n1 != NULL ? "Node Found :-)" : "Node Is not found :-(") << endl;

	system("pause > 0");

	return 0;
}