#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

int main() {
	Node* head;

	// allocate 3 nodes in the heap
	Node* node1 = new Node,
		* node2 = new Node,
		* node3 = new Node; 


	// Assign value values
	node1->value = 1;
	node2->value = 2;
	node3->value = 3;
	
	// Connect nodes
	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	// print the linked list value
	while (head != NULL) {
		Node* temp = head;

		cout << head->value << endl;
		head = head->next;
		
		delete temp;
	}

	system("pause > 0");

	return 0;
}