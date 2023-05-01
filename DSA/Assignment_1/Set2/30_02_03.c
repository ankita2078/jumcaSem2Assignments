/*Assignment 2 Q3*/
/*
1. Write a menu-driven program that performs the following on a double
linked list. (Write a function for each of the operations)
I. Create a linked list.
II. Print the content of the list.
III. Insert an element at the front of the list
IV. Insert an element at the end of the list
V. Insert a node after the kth node.
VI. Insert a node after the node (first from the start) containing a
given value.
VII. Insert a node before the kth node.
VIII. Insert a node before the node (first from the start) containing a
given value.
IX. Delete the first node.
X. Delete the last node.
XI. Delete a node after the kth node.
XII. Delete a node before the kth node.
XIII. Delete the kth node.
XIV. Delete the node(first from the start) containing a specified value.
XV. Find the reverse of a list(not just printing in reverse)
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
} node;



//Function prototypes
/*01*/node *create(node *head);
/*02*/void print(node *head);
/*03*/node *insertFront(node *head, int val);
/*04*/node *insertEnd(node *head, int val);
/*05*/node *insertAfterK(node *head, int k, int val);
/*06*/node *insertAfterNodeVal(node *head, int x, int val);
/*07*/node *insertBeforeK(node *head, int k, int val);
/*08*/node *insertBeforeNodeVal(node *head, int x, int val);
/*09*/node *deleteFirst(node *head);
/*10*/node *deleteLast(node *head);
/*11*/node *deleteAfterK(node *head, int k);
/*12*/node *deleteBeforeK(node *head, int k);
/*13*/node *deleteKthNode(node *head, int k);
/*14*/node *deleteNodeVal(node *head, int x);
/*15*/node *reverseList(node *head);



//main() function
int main() {

	node *p, *q, n, *cList;
	int choice, search, k, x, val;
	while (1) {
		printf("\n\t\t\t-----------MENU----------");
		printf("\n\t\t\t1.  Create a linked list.");
		printf("\n\t\t\t2.  Print the content of the list.");
		printf("\n\t\t\t3.  Insert an element at the front of the list");
		printf("\n\t\t\t4.  Insert an element at the end of the list");
		printf("\n\t\t\t5.  Insert a node after the kth node.");
		printf("\n\t\t\t6.  Insert a node after the node (first from the start) containing a given value.");
		printf("\n\t\t\t7.  Insert a node before the kth node.");
		printf("\n\t\t\t8.  Insert a node before the node (first from the start) containing a given value.");
		printf("\n\t\t\t9.  Delete the first node.");
		printf("\n\t\t\t10. Delete the last node.");
		printf("\n\t\t\t11. Delete a node after the kth node.");
		printf("\n\t\t\t12. Delete a node before the kth node.");
		printf("\n\t\t\t13. Delete the kth node.");
		printf("\n\t\t\t14. Delete the node(first from the start) containing a specified value.");
		printf("\n\t\t\t15. Find the reverse of a list(not just printing in reverse)");
		printf("\n\t\t\t16. Exit");
		printf("\n\n\t\t\tEnter choice(1-21):");
		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			p = create(p);
			// printf("\nHEAD->DATA=%d", p->data);
			break;
		}

		case 2: {
			print(p);
			break;
		}

		case 3: {

			printf("\nEnter value to be inserted:");
			scanf("%d", &val);
			p = insertFront(p, val);
			printf("\nInsertion successful");
			break;
		}

		case 4: {
			printf("\nEnter value to be inserted:");
			scanf("%d", &val);
			p = insertEnd(p, val);

			printf("\nInsertion successful");
			break;
		}

		case 5: {
			printf("\nEnter position K:");
			scanf("%d", &k);
			printf("\nEnter value to be inserted:");
			scanf("%d", &val);
			p = insertAfterK(p, k, val);
			break;
		}

		case 6: {
			printf("\nEnter value after which insertion needs to be done:");
			scanf("%d", &x);
			printf("\nEnter value to be inserted:");
			scanf("%d", &val);
			p = insertAfterNodeVal(p, x, val);
			break;
		}

		case 7: {
			printf("\nEnter position K:");
			scanf("%d", &k);
			printf("\nEnter value to be inserted:");
			scanf("%d", &val);
			p = insertBeforeK(p, k, val);
			break;
		}
		case 8: {
			printf("\nEnter value before which insertion needs to be done:");
			scanf("%d", &x);
			printf("\nEnter value to be inserted:");
			scanf("%d", &val);
			insertBeforeNodeVal(p, x, val);
			break;
		}

		case 9: {
			p = deleteFirst(p);
			break;
		}

		case 10: {
			p = deleteLast(p);
			break;
		}
		case 11: {
			printf("\nEnter position K:");
			scanf("%d", &k);
			p = deleteAfterK(p, k);
			break;
		}

		case 12: {
			printf("\nEnter position K:");
			scanf("%d", &k);
			p = deleteBeforeK(p, k);
			break;
		}
		case 13: {
			printf("\nEnter position K:");
			scanf("%d", &k);
			p = deleteKthNode(p, k);
			break;
		}

		case 14: {
			printf("\nEnter value:");
			scanf("%d", &x);
			p = deleteNodeVal(p, x);
			break;
		}

		case 15: {
			p = reverseList(p);
			printf("\nReverse successful");
			break;
		}

		case 16: {
			printf("\nExitting!!!");
			exit(0);
			break;
		}

		default: {
			printf("\nWrong Choice!");
			break;
		}

		}
	}

	return 0;
}



//Function definitions

//case 1
node *create(node *head) {
	int n, i;


	printf("\nEnter number of nodes:");
	scanf("%d", &n);

	printf("\nEnter %d values:\n", n);


	node *p = (node*)malloc(sizeof(node));
	scanf("%d", &(p->data));

	head = p;
	head->next = NULL;
	head->prev = NULL;

	for (i = 1; i < n; i++) {
		node *q = (node*)malloc(sizeof(node));
		scanf("%d", &(q->data));
		p->next = q;
		q->next = NULL;
		q->prev = p;
		p = q;
	}

	printf("\nDouble Linked List created successfully.");

	return head;
}

//case2
void print(node *head) {
	node *temp;
	printf("\n\tNULL ->");
	for (temp = head; temp != NULL; temp = temp->next) {
		printf(" %d ->", temp->data);
	} printf(" NULL");
	free(temp);
}

//case 3
node *insertFront(node *head, int val) {
	node *p = (node*)malloc(sizeof(node));
	p->data = val;

	if (head == NULL) {
		head = p;
		head->next = NULL;
		head->prev = NULL;
	}
	else {

		p->next = head;
		head->prev = p;
		p->prev = NULL;
		head = p;

	}
	return head;
}

// case 4
node *insertEnd(node *head, int val) {
	node *p = (node*)malloc(sizeof(node));
	node *temp;
	p->data = val;

	if (head == NULL) {
		head = p;
		head->next = NULL;
		head->prev = NULL;
		// printf("\nhead=%d", head->data);
	}
	else {
		for (temp = head; temp->next != NULL; temp = temp->next);
		temp->next = p;
		p->next = NULL;
		p->prev = temp;
	}



	return head;
}

// case 5
node *insertAfterK(node *head, int k, int val) {
	node *p = (node*)malloc(sizeof(node));
	node *temp;
	int i;
	p->data = val;

	for (temp = head, i = 1; i < k; temp = temp->next, ++i);
	p->next = temp->next;
	p->prev = temp;
	temp->next->prev = p;
	temp->next = p;
	return head;
}

//case 6
node *insertAfterNodeVal(node *head, int x, int val) {
	// int i = searchElement(head, x);

	int i;

	if (head == NULL) {
		printf("\nList empty!!!");
		i = 0;
	} else {

		node *temp;
		int flag = 0;
		i = 1;
		for (temp = head; temp != NULL; temp = temp->next, ++i) {
			if (temp->data == x) {
				flag = 1;
				break;
			}

		} if (flag == 0) {
			i = -1;
		}
	}

	if (i <= 0) {
		printf("\nInsertion not possible");
	}
	else {
		insertAfterK(head, i, val);
	}
	return head;
}

// case 7
node *insertBeforeK(node *head, int k, int val) {

	if (k == 1) {
		return insertFront(head, val);
	}

	node *p = (node*)malloc(sizeof(node));
	node *temp;
	int i;

	p->data = val;

	for (temp = head, i = 1; i != k - 1; temp = temp->next, i++);

	p->next = temp->next;
	p->prev = temp;
	temp->next->prev = p;
	temp->next = p;


	return head;
}

// case 8
node *insertBeforeNodeVal(node *head, int x, int val) {
	// int i = searchElement(head, x);

	int i;

	if (head == NULL) {
		printf("\nList empty!!!");
		i = 0;
	} else {

		node *temp;
		int flag = 0;
		i = 1;
		for (temp = head; temp != NULL; temp = temp->next, ++i) {
			if (temp->data == x) {
				flag = 1;
				break;
			}

		} if (flag == 0) {
			i = -1;
		}
	}





	if (i <= 0) {
		printf("\nInsertion not possible");
	} else {
		insertBeforeK(head, i, val);
	}
	return head;
}

//case 9
node *deleteFirst(node *head) {
	node *p = head;
	head = head->next;
	head->prev = NULL;

	free(p);
	return head;
}

//case 10
node *deleteLast(node *head) {
	node *temp, *p;
	for (temp = head; temp->next->next != NULL; temp = temp->next);
	p = temp->next;
	temp->next = NULL;
	free(p);
	return head;
}

//case 11
node *deleteAfterK(node *head, int k) {

	node *temp;
	int i = 1;
	for (temp = head; i != k; ++i, temp = temp->next);
	node *p = temp->next;
	p->next->prev = temp;
	temp->next = temp->next->next;
	free(p);
	return head;

}

//case 12
node *deleteBeforeK(node *head, int k) {
	node *temp;
	int i = 1;
	for (temp = head; i != k - 2; ++i, temp = temp->next);
	node *p = temp->next;
	p->next->prev = temp;
	temp->next = temp->next->next;
	free(p);
	return head;
}

//case 13
node *deleteKthNode(node *head, int k) {
	node *temp;
	int i = 1;
	for (temp = head; i != k - 1; ++i, temp = temp->next);
	node *p = temp->next;
	p->next->prev = temp;
	temp->next = temp->next->next;
	free(p);
	return head;
}

//case 14
node *deleteNodeVal(node *head, int x) {
	// int i = searchElement(head, x);
	int i;

	if (head == NULL) {
		printf("\nList empty!!!");
		i = 0;
	} else {

		node *temp;
		int flag = 0;
		i = 1;
		for (temp = head; temp != NULL; temp = temp->next, ++i) {
			if (temp->data == x) {
				flag = 1;
				break;
			}

		} if (flag == 0) {
			i = -1;
		}
	}


	if (i <= 0) {
		printf("\nInsertion not possible");
	} else {
		deleteKthNode(head, i);
	}
	return head;
}

//case 15
node *reverseList(node *head) {
	node *temp;

	node *newList = NULL;
	// newList=insertFront(head);

	for (temp = head; temp != NULL; temp = temp->next) {
		newList = insertFront(newList, temp->data);
	}
	return newList;

}


