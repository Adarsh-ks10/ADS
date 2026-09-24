#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
void display(struct Node* head) {
struct Node* temp = head;
if (temp == NULL) {
printf("List is empty\n");
return;
}
printf("Linked List: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
void insertAtBeginning(struct Node** head, int data) {
struct Node* newNode = createNode(data);
newNode->next = *head;
*head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
struct Node* newNode = createNode(data);
if (*head == NULL) {
*head = newNode;
return;
}
struct Node* temp = *head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
}
void insertAtPosition(struct Node** head, int data, int position) {
if (position < 1) {
printf("Invalid position!\n");
return;
}
if (position == 1) {
insertAtBeginning(head, data);
return;
}
struct Node* temp = *head;
for (int i = 1; i < position - 1 && temp != NULL; i++)
temp = temp->next;
if (temp == NULL) {
printf("Position out of range!\n");
return;
}
struct Node* newNode = createNode(data);
newNode->next = temp->next;
temp->next = newNode;
}
void deleteAtBeginning(struct Node** head) {
if (*head == NULL) {
printf("List is empty!\n");

return;
}
struct Node* temp = *head;
*head = temp->next;
free(temp);
}
void deleteAtEnd(struct Node** head) {
if (*head == NULL) {
printf("List is empty!\n");
return;
}
if ((*head)->next == NULL) { /* only one node */
free(*head);
*head = NULL;
return;
}
struct Node* temp = *head;
while (temp->next->next != NULL)
temp = temp->next;
free(temp->next);
temp->next = NULL;
}
void deleteAtPosition(struct Node** head, int position) {
if (*head == NULL) {
printf("List is empty!\n");
return;
}
if (position < 1) {
printf("Invalid position!\n");
return;
}
struct Node* temp = *head;
if (position == 1) {
*head = temp->next;
free(temp);

return;
}
for (int i = 1; temp != NULL && i < position - 1; i++)
temp = temp->next;
if (temp == NULL || temp->next == NULL) {
printf("Position out of range!\n");
return;
}
struct Node* nextNode = temp->next->next;
free(temp->next);
temp->next = nextNode;
}
int main() {
struct Node* head = NULL;
int choice, data, pos;
while (1) {
printf("\n-- Linked List Menu --\n");
printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n"
"4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n"
"7. Display\n8. Exit\n");
printf("Enter your choice: ");
if (scanf("%d", &choice) != 1) {
return 0;
}
switch (choice) {
case 1:
printf("Enter data: ");
scanf("%d", &data);
insertAtBeginning(&head, data);
break;
case 2:
printf("Enter data: ");
scanf("%d", &data);

insertAtEnd(&head, data);
break;
case 3:
printf("Enter data and position: ");
scanf("%d %d", &data, &pos);
insertAtPosition(&head, data, pos);
break;
case 4:
deleteAtBeginning(&head);
break;
case 5:
deleteAtEnd(&head);
break;
case 6:
printf("Enter position: ");
scanf("%d", &pos);
deleteAtPosition(&head, pos);
break;
case 7:
display(head);
break;
case 8:
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}



__OUTPUT__


__-- Linked List Menu --
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Display
8. Exit
Enter your choice: 1
Enter data: 10

-- Linked List Menu --
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Display
8. Exit
Enter your choice: 2
Enter data: 20

-- Linked List Menu --
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete at Beginning
5. Delete at End
6. Delete at Position
7. Display
8. Exit
Enter your choice: 7
Linked List: 10 -> 10 -> 20 -> NULL