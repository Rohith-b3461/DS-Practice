#include<stdio.h>
#include<conio.h>
#define MAX 20

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n = 0;

void main() {
    int ch;
    char g = 'y';
    
    do {
        printf("\n Main Menu");
        printf("\n 1. Create");
        printf("\n 2. Delete");
        printf("\n 3. Search");
        printf("\n 4. Insert");
        printf("\n 5. Display");
        printf("\n 6. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf(" \n Enter the correct choice:");
        }
        
        printf("\n Do you want to continue (y/n)? ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');
    
    getch();
}

void create() {
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("\n Enter the element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    int pos;
    
    printf("\n Enter the position you want to delete: ");
    scanf("%d", &pos);
    
    if (pos >= n || pos < 0) {
        printf("\n Invalid location");
    } else {
        for (int i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
        printf("\n The elements after deletion:");
        for (int i = 0; i < n; i++) {
            printf("\t%d", b[i]);
        }
    }
}

void search() {
    int e, found = 0;
    
    printf("\n Enter the element to be searched: ");
    scanf("%d", &e);
    
    for (int i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

void insert() {
    int pos, p;
    
    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);
    
    if (pos > n || pos < 0 || n >= MAX) {
        printf("\n Invalid location");
    } else {
        for (int i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        
        printf("\n Enter the element to insert: ");
        scanf("%d", &p);
        
        b[pos] = p;
        n++;
        
        printf("\n The list after insertion:");
        display();
    }
}

void display() {
    printf("\n The elements of the list are:");
    for (int i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
}
