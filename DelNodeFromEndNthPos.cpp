#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
};

class linked_list {
private:
	node *head = NULL;

public:
	node *gethead() {
		return head;
	}

	void add_node(int n, int position) {
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL) {
			head = tmp;
			return;

		}
		/* add at given position */
		else if (position == 1) {
			tmp->next = head;
			head = tmp;
			return;
		} else {
			node *currentNode = head;
			while ((position - 1 > 1) && (currentNode->next != NULL)) {
				currentNode = currentNode->next;
				position--;
			}
			tmp->next = currentNode->next;
			currentNode->next = tmp;
		}
	}
	void update_head() {
		head = head->next;
		return;
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
	int sizeof_linkedlist(node *head_temp) {
		if (head_temp == NULL) {
			cout << "NULL" << endl;
			return 0;
		} else {
			int count = 0;
			while (head_temp != NULL) {
				count++;
				head_temp = head_temp->next;
			}
			return ((sizeof(node)) * count);
		}
	}
	void Remove_Nth_Node_From_End(node *temp_remove_head, int n) {
		int len = 0, i;
		node *Temp_node;
		Temp_node = temp_remove_head;

		/* find length of the linked list */
		len = sizeof_linkedlist(Temp_node);
		len = len / (sizeof(node));
		cout << "length of linked list = " << len << endl;
		/* if value of n is more than length of the linked list dont do any
		 * thing */
		if (len < n)
			return;
		else if (len == n) {
			/* delete from start */
			update_head();
			delete Temp_node;
			return;
		} else {
			/* find (len-n+1)th node from the begining */
			for (i = 1; i < len - n + 1; i++) {
				Temp_node = temp_remove_head;
				temp_remove_head = temp_remove_head->next;
			}

			/* delete nth node from end */
			Temp_node->next = temp_remove_head->next;
			delete temp_remove_head;

			return;
		}
	}
};

class function_list {
public:
	void Remove_duplicate_node(node *head) {
		node *ptr1, *ptr2, *dup;
		ptr1 = head;

		/* check  elements one by one */
		while (ptr1 != NULL && ptr1->next != NULL) {
			ptr2 = ptr1;

			/* Compare the selected element with rest
			   of the elements */
			while (ptr2->next != NULL) {
				/* If duplicate then delete it */
				if (ptr1->data == ptr2->next->data) {
					dup = ptr2->next;
					ptr2->next = ptr2->next->next;
					delete (dup);
				} else /* This is tricky */
					ptr2 = ptr2->next;
			}
			ptr1 = ptr1->next;
		}
	}
	/* Function to remove  Nth node from the end of linked list*/
};
int main() {
	linked_list a;
	function_list b;
	a.add_node(2, 1);
	a.add_node(3, 1);
	a.add_node(1, 2);
	a.add_node(2, 3);
	a.display(a.gethead());
	a.Remove_Nth_Node_From_End(a.gethead(), 5);
	a.display(a.gethead());
	b.Remove_duplicate_node(a.gethead());
	cout << "size of node = " << sizeof(node) << endl;
	cout << "size of linked list = " << a.sizeof_linkedlist(a.gethead())
		 << endl;
	a.display(a.gethead());
	a.del(a.gethead());
	a.display(a.gethead());
	a.add_node(5, 7);
	a.display(a.gethead());
	a.add_node(6, 11);
	a.display(a.gethead());
	a.del(a.gethead());
	a.display(a.gethead());
	a.del(a.gethead());
	a.display(a.gethead());
	a.add_node(7, 4);
	a.add_node(7, 4);
	a.add_node(7, 4);
	b.Remove_duplicate_node(a.gethead());
	a.display(a.gethead());
	cout << a.search(a.gethead(), 7) << endl;
	return 0;
}
