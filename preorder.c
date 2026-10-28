#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insertion
struct Node* insert(struct Node *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Searching
void search(struct Node *root, int key) {
    if (root == NULL) {
        printf("Element not found\n");
        return;
    }

    if (root->data == key) {
        printf("Element found\n");
    }
    else if (key < root->data) {
        search(root->left, key);
    }
    else {
        search(root->right, key);
    }
}

// Preorder Traversal: Root, Left, Right
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Display BST using inorder traversal
void display(struct Node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, data, key;

    do {
        printf("\n\n--- BST MENU ---");
        printf("\n1. Insertion");
        printf("\n2. Searching");
        printf("\n3. Preorder Traversal");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(root, key);
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                break;

            case 4:
                printf("BST elements: ");
                display(root);
                break;

            case 5:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}




___OUTPUT___


--- BST MENU ---
1. Insertion
2. Searching
3. Preorder Traversal
4. Display
5. Exit
Enter your choice: 1
Enter element to insert: 30


--- BST MENU ---
1. Insertion
2. Searching
3. Preorder Traversal
4. Display
5. Exit
Enter your choice: 1
Enter element to insert: 40


--- BST MENU ---
1. Insertion
2. Searching
3. Preorder Traversal
4. Display
5. Exit
Enter your choice: 1
Enter element to insert: 20


--- BST MENU ---
1. Insertion
2. Searching
3. Preorder Traversal
4. Display
5. Exit
Enter your choice: 1
Enter element to insert: 10


--- BST MENU ---
1. Insertion
2. Searching
3. Preorder Traversal
4. Display
5. Exit
Enter your choice: 2
Enter element to search: 25
Element not found


--- BST MENU ---
1. Insertion
2. Searching
3. Preorder Traversal
4. Display
5. Exit
Enter your choice: 2
Enter element to search: 10
Element found


--- BST MENU ---
1. Insertion
2. Searching
3. Preorder Traversal
4. Display
5. Exit
Enter your choice: 3
Preorder Traversal: 30 20 10 40

--- BST MENU ---
1. Insertion
2. Searching
3. Preorder Traversal
4. Display
5. Exit
Enter your choice: 4
BST elements: 10 20 30 40

--- BST MENU ---
1. Insertion
2. Searching
3. Preorder Traversal
4. Display
5. Exit
Enter your choice: 5
Exiting program
