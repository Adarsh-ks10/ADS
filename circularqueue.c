#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is FULL (Overflow).\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted.\n", value);
}
void dequeue() {
    if (front == -1) {
        printf("Queue is EMPTY (Underflow).\n");
        return;
    }
    printf("%d deleted.\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}
void display() {
    if (front == -1) {
        printf("Queue is EMPTY.\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue ---\n");
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

---OUTPUT---

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 30
30 inserted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 10
10 inserted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 20
20 inserted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 3
Queue: 30 10 20

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 2
30 deleted.

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 3
Queue: 10 20

--- Circular Queue ---
1. Insert
2. Delete
3. Display
4. Exit
Enter choice: 4
