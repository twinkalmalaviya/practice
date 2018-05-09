#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
};

class linked_list {
private:
	node *head = NULL, *tail = NULL;

public:
	void add_node(int n) {
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL) {
			head = tmp;
			tail = tmp;
		} else {
			tail->next = tmp;
			tail = tail->next;
		}
	}

	node *gethead() {
		return head;
	}

	static void display(node *head_temp) {
		if (head_temp == NULL) {
			cout << "NULL" << endl;
		} else {
			cout << head_temp->data << endl;
			display(head_temp->next);
		}
	}
};

int main() {
	linked_list a;
	a.add_node(1);
	a.add_node(2);
	a.add_node(9);
	a.add_node(5);

	a.display(a.gethead());
	return 0;
}
