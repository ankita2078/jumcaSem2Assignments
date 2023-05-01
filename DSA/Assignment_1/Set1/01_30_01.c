#include<stdio.h>
#include<stdlib.h>



int *create(int *n) {
    int *p, i;
    // printf("\nEnter number of values:");
    // scanf("%d",&n);
    p = (int*)malloc((*n) * sizeof(int));

    printf("\nEnter %d values:\n", *n);
    for (i = 0; i < (*n); i++) {
        printf("\nArray[%d]=", i);
        scanf("%d", &p[i]);
    }
    return p;
}

void display(int *p, int *n) {
    int i;
    // printf("\nDisplaying values:\n");

    for (i = 0; i < *n; i++) {
        printf("\nArray[%d]=%d", i, p[i]);
    }

}

int count(int *n) {
    printf("\nCount=%d", *n);
}

int *reverse(int *p, int *n) {
    int i, j, temp;
    for (i = 0; i < *n / 2; i++) {
        j = *n - i - 1;
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
    printf("\nReverse successful!");
    return p;
}

void indexOfElement(int *p, int *n, int x) {
    int flag = 0, i;
    if (*n == 0) {
        printf("\nArray empty!");
    }
    else {
        for (i = 0; i < *n; i++) {
            if (p[i] == x) {
                flag = 1;
                printf("\nElement %d is present in index %d", x, i);
            }
        }
    }
    if (flag == 0) {
        printf("\nElement not found!");
    }
}



int *insert(int *p, int *n) {
    int pos, i, x;
    int *q = (int*)malloc((*n + 1) * sizeof(int));

    //p=(int*)realloc(p,*n);

    printf("\nEnter position:");
    scanf("%d", &pos);
    printf("\nEnter value to be inserted:");
    scanf("%d", &x);
    q[pos] = x;

    for (i = 0; i < pos; i++) {
        q[i] = p[i];
    }
    for (i = pos + 1; i < (*n + 1); i++) {
        q[i] = p[i - 1];
    }

    printf("\nInsertion Successful!");
    (*n)++;
    free(p);
    return q;
}


int *deleteElement(int *p, int *n) {
    int pos, i, k = 0;
    int *q = (int*)malloc((*n - 1) * sizeof(int));

    if (*n == 0) {
        printf("\nArray empty!!!");
    }
    else {
        printf("\nEnter position:");
        scanf("%d", &pos);


        for (i = 0; i < (*n); i++) {
            if (i != pos) {
                q[k] = p[i];
                k++;
            }
        }
        printf("\nDeletion Successful!");
        (*n)--;

    }

    free(p);
    return q;
    // if (pos == (*n - 1)) {
    //     (*n)--;
    // }
    // else {
    //     for (i = pos + 1; i < (*n); i++) {
    //         p[i - 1] = p[i];
    //         (*n)--;
    //     }

    //     printf("\nDeletion Successful!");


    // }
    //use of above commented snippet was working in linux but not in windows..."unqualified id not found before *delete"
}


int *sortElements(int *p, int *n) {
    int i, temp, j;

    for (i = 0; i < *n; i++) {
        for (j = i + 1; j < *n; j++) {
            if (p[i] > p[j]) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\nSorting successful!!!");
    return p;
}





int main() {
    int choice, n, *p, x, i, *q, n1;
    while (1) {
        printf("\n\t\t\t\t----MENU----\n\t\t\t\t1.Create\n\t\t\t\t2.Display\n\t\t\t\t3.Count\n\t\t\t\t4.Reverse\n\t\t\t\t5.Index of a given element\n\t\t\t\t7.Insert\n\t\t\t\t8.Delete\n\t\t\t\t11.Sort\n\t\t\t\t13.Exit\nEnter choice(1-13):");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
        {
            printf("\nEnter number of values:");
            scanf("%d", &n);
            p = create(&n);
            break;
        }
        case 2:
        {
            printf("\n-:Display:-");
            display(p, &n);
            break;
        }
        case 3:
        {
            count(&n);
            break;
        }
        case 4:
        {
            p = reverse(p, &n);
            break;
        }
        case 5:
        {
            printf("\nEnter element:");
            scanf("%d", &x);
            indexOfElement(p, &n, x);
            break;
        }

        /*       case 6:
               {
                   printf("\nEnter index:");
                   scanf("%d", &i);
                   indexedElement(p, i, &n);
                   break;
               }
        */
        case 7:
        {
            p = insert(p, &n);
            break;
        }
        case 8:
        {
            p = deleteElement(p, &n);
            break;
        }
        /*        case 9:
                {
                    printf("\nMerging Function called!\n\nFirst array is:");
                    display(p, &n);
                    printf("\n\n-:Second array:-");
                    printf("\nEnter number of values:");
                    scanf("%d", &n1);
                    q = create(&n1);
                    merge(p, q, &n, &n1);
                    break;
                }
                case 10:
                {
                    printf("\nEnter index for splitting:");
                    scanf("%d", &i);
                    split(p, i, &n);
                    break;
                }

        */
        case 11:
        {
            p = sortElements(p, &n);
            break;
        }
        /*
                case 12:
                {
                    printf("\nEnter element:");
                    scanf("%d", &x);
                    search(p, &n, x);
                    break;
                }
        */
        case 13:
        {
            printf("\nExiting!!!");
            exit(0);
            break;
        }

        default: printf("\nWrong choice!!!");
            break;

        }
    }

    return 0;
}



