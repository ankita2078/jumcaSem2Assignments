/*Assignment 2 Q2*/
/*
Write a menu-driven program representing a polynomial as a data structure
using a singly linked list and write functions to add, subtract and multiply
two polynomials.

*/


#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	int index;
	struct node *next;
} node;



//Function prototypes
node *createPolynomial(node *head);
void printPolynomial(node *head);

/*01*/
node *addPolynomials(node *head1, node *head2);
/*02*/
node *subPolynomials(node *head1, node *head2);
/*03*/
node *mulPolynomials(node *head1, node *head2);


//main() function
int main() {

	node *p, *q, *addPoly, *subPoly;
	int choice, search, k, x, val;
	while (1) {
		printf("\n\t\t\t-----------MENU----------");
		printf("\n\t\t\t1.  Add two polynomials");
		printf("\n\t\t\t2.  Subtract two polynomials");
		printf("\n\t\t\t3.  Multiply two polynomials");
		printf("\n\t\t\t4.  Exit");
		printf("\n\n\t\t\tEnter choice(1-4):");
		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			printf("\n\nFirst Polynomial:\n");
			p = createPolynomial(p);
			printf("\n\nSecond Polynomial:\n");
			q = createPolynomial(q);
			addPoly = addPolynomials(p, q);
			printf("\n\nAfter Addition:");
			printPolynomial(addPoly);
			// printf("\nHEAD->DATA=%d", p->data);
			break;
		}

		case 2: {
			printf("\n\nFirst Polynomial:\n");
			p = createPolynomial(p);
			printf("\n\nSecond Polynomial:\n");
			q = createPolynomial(q);
			node *subPoly = subPolynomials(p, q);
			printf("\n\nAfter Subtraction:");
			printPolynomial(subPoly);
			break;
		}

		 case 3: {

		 	printf("\n\nFirst Polynomial:\n");
			p = createPolynomial(p);
			printf("\n\nSecond Polynomial:\n");
			q = createPolynomial(q);
			node *mulPoly=mulPolynomials(p,q);
			printf("\n\nAfter Multiplication:");
		 	printPolynomial(mulPoly);
			break;
		}

		case 4: {
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


node *createPolynomial(node *head) {
	int n, i;
	node *temp;
	head = NULL;
	printf("\n\tEnter degree of polynomial:");
	scanf("%d", &n);

	printf("\n\tEnter the coefficients of %d terms:\n", n);


	for (i = n; i >= 0; i--) {
		node *q = (node*)malloc(sizeof(node));
		printf("\n\t\tCoefficient of x%d : ", i);
		scanf("%d", &(q->data));
		q->index = i;
		if (head == NULL) {
			head = q;
			q->next = NULL;
		}
		else {

			for (temp = head; temp->next != NULL; temp = temp->next);
			temp->next = q;
			q->next = NULL;
		}
		// printf("\nindex=%d\ndata=%d", q->index, q->data);
	}

	printPolynomial(head);

	return head;
}


void printPolynomial(node *head) {
	node *temp;
	printf("\n\tPolynomial is:");
	printf("\t");
	for (temp = head; temp != NULL; temp = temp->next) {
		if (temp->data != 0) {
			printf(" (%d) x%d +", temp->data, temp->index);
		}
	} printf("\b \b");
	free(temp);
}

//case 1
node *addPolynomials(node *head1, node *head2) {
	int diff = 0, flag = 0, i;
	node *sum = NULL, *temp1 = head1, *temp2 = head2, *temp;

	if (head1->index >= head2->index) {
		diff = head1->index - head2->index;
		flag = 1;
	} else {
		diff = head2->index - head1->index;
		flag = 2;
	}


	for (i = 1; i <= diff; i++) {
		node *p = (node*)malloc(sizeof(node));
		if (flag == 1) {
			p->data = temp1->data;
			p->index = temp1->index;
			temp1 = temp1->next;
		}
		else if (flag == 2) {
			p->data = temp2->data;
			p->index = temp2->index;
			temp2 = temp2->next;
		}

		if (sum == NULL) {
			sum = p;
			sum->next = NULL;
			// printf("\nhead=%d", head->data);
		}
		else {
			for (temp = sum; temp->next != NULL; temp = temp->next);
			temp->next = p;
			p->next = NULL;
		}
	}


	for (; temp1 != NULL && temp2 != NULL; temp1 = temp1->next, temp2 = temp2->next) {
		node *p = (node*)malloc(sizeof(node));
		p->data = temp1->data + temp2->data;
		p->index = temp2->index;

		if (sum == NULL) {
			sum = p;
			sum->next = NULL;
			// printf("\nhead=%d", head->data);
		}
		else {
			for (temp = sum; temp->next != NULL; temp = temp->next);
			temp->next = p;
			p->next = NULL;
		}

	} return sum;
}

//case 2
node *subPolynomials(node *head1, node *head2) {
	int diff = 0, flag = 0, i;
	node *sub = NULL, *temp1 = head1, *temp2 = head2, *temp;

	if (head1->index >= head2->index) {
		diff = head1->index - head2->index;
		flag = 1;
	} else {
		diff = head2->index - head1->index;
		flag = 2;
	}


	for (i = 1; i <= diff; i++) {
		node *p = (node*)malloc(sizeof(node));
		if (flag == 1) {
			p->data = temp1->data;
			p->index = temp1->index;
			temp1 = temp1->next;
		}
		else if (flag == 2) {
			p->data = temp2->data;
			p->index = temp2->index;
			temp2 = temp2->next;
		}

		if (sub == NULL) {
			sub = p;
			sub->next = NULL;
			// printf("\nhead=%d", head->data);
		}
		else {
			for (temp = sub; temp->next != NULL; temp = temp->next);
			temp->next = p;
			p->next = NULL;
		}
	}


	for (; temp1 != NULL && temp2 != NULL; temp1 = temp1->next, temp2 = temp2->next) {
		node *p = (node*)malloc(sizeof(node));
		p->data = temp1->data - temp2->data;
		p->index = temp2->index;

		if (sub == NULL) {
			sub = p;
			sub->next = NULL;
			// printf("\nhead=%d", head->data);
		}
		else {
			for (temp = sub; temp->next != NULL; temp = temp->next);
			temp->next = p;
			p->next = NULL;
		}

	} return sub;
}


//case 3
node *mulPolynomials(node *head1, node *head2) {
	node *temp, *temp1, *temp2;
	int max = head1->index + head2->index;
	max++;
	int i = 0;
	int *arr = (int*)malloc(max * sizeof(int));
	for (i = 0; i <= max; i++) {
		arr[i] = 0;
	}
	node *mul = NULL;

	for (temp1 = head1; temp1 != NULL; temp1 = temp1->next) {
		for (temp2 = head2; temp2 != NULL; temp2 = temp2->next) {
			arr[(temp1->index + temp2->index)] += temp1->data * temp2->data;
		}
	}
	
//	printf("\n");
//	for (i = 0; i <= max; i++) {
//		printf(" %d ",arr[i]);
//	}
	
	for (i = max; i >= 0; i--) {
		node *q = (node*)malloc(sizeof(node));
		q->data = arr[i];
		q->index = i;
		if (mul == NULL) {
			mul = q;
			q->next = NULL;
		}
		else {

			for (temp = mul; temp->next != NULL; temp = temp->next);
			temp->next = q;
			q->next = NULL;
		}
		// printf("\nindex=%d\ndata=%d", q->index, q->data);
	} return mul;
}
