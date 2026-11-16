#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void insert_at_end(Node* &head, int val) {
	Node* new_node = new Node;

	new_node->data = val;
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

void delete_node(Node* &head, int data) {
	if (head == NULL)
		return;
	
	Node* curr;

	if (head->data == data) {
		curr = head;
		head = head->next;
	}
	else {
		Node* prev_node = head;
		curr = head->next;

		while (curr != NULL && curr->data != data) {
			prev_node = prev_node->next;
			curr = curr->next;
		}
		
		if (curr != NULL)
			prev_node->next = curr->next;
	}

	delete curr;
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

	delete_node(head, 3);

	print_list(head);

	system("pause > 0");

	return 0;
}