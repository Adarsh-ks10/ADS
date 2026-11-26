#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void enqueue(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("%d inserted.\n", value);
}
void dequeue() {
    struct Node *temp;
    if (front == NULL) {
        printf("Queue is EMPTY (Underflow).\n");
        return;
    }
    temp = front;
    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
        rear->next = front;
    }
    printf("%d deleted.\n", temp->data);
    free(temp);
}
void display() {
    struct Node *temp;
    if (front == NULL) {
        printf("Queue is EMPTY.\n");
        return;
    }
    temp = front;
    printf("Circular Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Using Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

--- OUTPUT ---

--- Circular Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 40
40 inserted.

--- Circular Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 20
20 inserted.

--- Circular Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 60
60 inserted.

--- Circular Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 3
Circular Queue: 40 20 60

--- Circular Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 2
40 deleted.

--- Circular Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 3
Circular Queue: 20 60

--- Circular Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 4
