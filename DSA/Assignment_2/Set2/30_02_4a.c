/*
Given a problem, “people are standing in a circle waiting to be executed.
Counting begins at a specified point in the circle and proceeds in a specified
direction (e.g., clockwise). After a specified number of people is skipped,
the next person is executed (i.e., removed). The procedure is repeated with
the remaining people, starting with the next person, going in the same
direction and skipping the same number of people until only one person
remains and is freed”. The solution is to find the person to be freed. Solve
it using
i) 2D array
ii) A circular linked list.
iii) A circular doubly linked list.
*/


//input:-direction,skip,start,num

#include<stdio.h>
#include<stdlib.h>


int main() {
	int n, skip, *arr;
	printf("Enter number of people:");
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	printf("\nEnter skips :");
	scanf("%d", &skip);



	printf("\nPlayers are : ");
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}

	int pos = 0;

	while (n > 1) {
		pos = (pos + skip) % n;
		printf("\n%d executed!", arr[pos]);
		for (int i = pos; i < n - 1; i++) {
			arr[i] = arr[i + 1];
			// printf("\n%d->%d", i, arr[i]);
		}

		--n;
	}

	printf("\nWinner is : %d", arr[0]);

}