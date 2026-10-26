#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
int main() {
struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *newNode, *temp;
int choice, value;
while (1) {
printf("\n-- Queue using Linked List --\n");
printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to enqueue: ");
scanf("%d", &value);
newNode = (struct Node *)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Queue overflow\n");
break;
}
newNode->data = value;
newNode->next = NULL;
if (rear == NULL) {
front = rear = newNode;
} else {
rear->next = newNode;
rear = newNode;
}
printf("%d enqueued to queue\n", value);
break;
case 2:
if (front == NULL) {
printf("Queue underflow\n");
break;
}
temp = front;
printf("%d dequeued from queue\n", front->data);
front = front->next;
if (front == NULL)
rear = NULL;
free(temp);
break;
case 3:
if (front == NULL) {
printf("Queue is empty\n");
break;
}
temp = front;
printf("Queue elements: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
break;
case 4:
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}
            




___OUTPUT____



-- Queue using Linked List --
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value to enqueue: 10
10 enqueued to queue

-- Queue using Linked List --
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value to enqueue: 20
20 enqueued to queue

-- Queue using Linked List --
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 10 -> 20 -> NULL

-- Queue using Linked List --
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
10 dequeued from queue

-- Queue using Linked List --
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 20 -> NULL

-- Queue using Linked List --
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
