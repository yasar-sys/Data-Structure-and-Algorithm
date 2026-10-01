#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push() {
    int value;

    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    }
    else {
        printf("Enter value: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("Value pushed successfully\n");
    }
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
    }
    else {
        printf("Popped value: %d\n", stack[top]);
        top--;
    }
}

void peek() {
    if(top == -1) {
        printf("Stack is empty\n");
    }
    else {
        printf("Top value: %d\n", stack[top]);
    }
}

void display() {
    int i;

    if(top == -1) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack elements:\n");

        for(i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }

        printf("\n");
    }
}

void isEmpty() {
    if(top == -1)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. IsEmpty\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}