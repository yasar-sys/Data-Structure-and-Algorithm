#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    int n, i, value;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {

        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        }
        else {
            temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

void deleteNode() {
    int value;

    struct Node *temp = head;
    struct Node *prev = NULL;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    if(head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if(head->data == value) {
        head = head->next;
        free(temp);

        printf("Node deleted successfully\n");
        return;
    }

    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value not found\n");
    }
    else {
        prev->next = temp->next;
        free(temp);

        printf("Node deleted successfully\n");
    }
}

void search() {
    int value, position = 1;
    struct Node *temp = head;

    printf("Enter value to search: ");
    scanf("%d", &value);

    while(temp != NULL) {

        if(temp->data == value) {
            printf("Value found at position %d\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Value not found\n");
}

void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    printf("Linked List: ");

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- LINKED LIST ---\n");
        printf("1. Create\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                create();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                search();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}