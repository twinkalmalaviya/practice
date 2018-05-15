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
			tmp->next = currentNode;
			currentNode->next = tmp;
		}
	}
	void update_head(node *new_head) {
		head = new_head;
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
			update_head(Temp_node->next);
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
	/* Function to reverse the linked list */
	void reverse(node *head_ref) {
		node *prev = NULL;
		node *current = head_ref;
		node *next = NULL;
		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		update_head(prev);
	}
/*function for detecting cycle in linked list
 Floyd’s Cycle detection algorithm */

int detectCycle(node *temp_list_head)
{
     node  *slow_p = temp_list_head, *fast_p = temp_list_head;
 
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p)
        {

            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }
 
    /* Return 0 to indeciate that ther is no loop*/
    return 0;
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
	cout<<a.detectCycle(a.gethead())<<endl;
	return 0;
}
