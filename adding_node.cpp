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

		}
		/* add at end */
		else {
			tail->next = tmp;
			tail = tmp;
		}
	}

	node *gethead() {
		return head;
	}

	void display(node *head_temp) {
		if (head_temp == NULL) {
			cout << "NULL" << endl;
		} else {
			cout << head_temp->data << endl;
			display(head_temp->next);
		}
	}
	void del(node *del_temp) {
		if (del_temp == NULL) {
			cout << "NULL" << endl;
		} else {
			/* delete from start */
			head = del_temp->next;
			delete del_temp;
		}
	}

	bool search(node *Search_temp, int number) {
		while (Search_temp != NULL) {
			if (Search_temp->data == number)
				return true;
			Search_temp = Search_temp->next;
		}
		return false;
	}
};

int main() {
	linked_list a;
	a.add_node(1);
	a.add_node(2);
	a.add_node(9);
	a.add_node(5);

	a.display(a.gethead());
	a.del(a.gethead());
	a.add_node(7);
	a.add_node(8);
	a.del(a.gethead());

	a.del(a.gethead());
	a.add_node(3);
	a.display(a.gethead());
	cout << a.search(a.gethead(), 10) << endl;
	return 0;
}
