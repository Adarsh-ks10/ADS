#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBegin(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning\n", data);
}

void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("%d inserted at end\n", data);
}

void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found\n", key);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // deleting head
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("%d deleted\n", key);
}

void displayForward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayReverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Reverse: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Display forward\n");
        printf("4. Delete a Node\n");
        printf("5. Display Reverse\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBegin(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 3:
                displayForward();
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
            case 5:
                displayReverse();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}



---OUTPUT---

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a Node
5. Display Reverse
6. Exit
Enter choice: 1
Enter value: 20
20 inserted at beginning

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a Node
5. Display Reverse
6. Exit
Enter choice: 1
Enter value: 30
30 inserted at beginning

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a Node
5. Display Reverse
6. Exit
Enter choice: 1
Enter value: 10
10 inserted at beginning

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a Node
5. Display Reverse
6. Exit
Enter choice: 2
Enter value: 50
50 inserted at end

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a Node
5. Display Reverse
6. Exit
Enter choice: 3
Forward: 10 <-> 30 <-> 20 <-> 50 <-> NULL

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a Node
5. Display Reverse
6. Exit
Enter choice: 5
Reverse: 50 <-> 20 <-> 30 <-> 10 <-> NULL

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a Node
5. Display Reverse
6. Exit
Enter choice: 4
Enter value to delete: 20
20 deleted

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a Node
5. Display Reverse
6. Exit
Enter choice: 3
Forward: 10 <-> 30 <-> 50 <-> NULL

1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a Node
5. Display Reverse
6. Exit
Enter choice: 6
