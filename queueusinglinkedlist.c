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
    newNode->next = NULL;
    if (front == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
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
    printf("%d deleted.\n", front->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}
void display() {
    struct Node *temp;
    if (front == NULL) {
        printf("Queue is EMPTY.\n");
        return;
    }
    temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Queue Using Linked List ---\n");
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

--- Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 30
30 inserted.

--- Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 60
60 inserted.

--- Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 90
90 inserted.

--- Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 3
Queue: 30 60 90

--- Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 2
30 deleted.

--- Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 60
Invalid choice.

--- Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 3
Queue: 60 90

--- Queue Using Linked List ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 4
