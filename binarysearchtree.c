#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("\n1. Insert\n2. Search\n3. Display BST\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &data);

                if (search(root, data) != NULL)
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}



----OUTPUT----

1. Insert
2. Search
3. Display BST
4. Exit
Enter choice: 1
Enter value: 10

1. Insert
2. Search
3. Display BST
4. Exit
Enter choice: 1
Enter value: 20

1. Insert
2. Search
3. Display BST
4. Exit
Enter choice: 1
Enter value: 30

1. Insert
2. Search
3. Display BST
4. Exit
Enter choice: 2
Enter value to search: 20
Element found

1. Insert
2. Search
3. Display BST
4. Exit
Enter choice: 3
Inorder Traversal: 10 20 30

1. Insert
2. Search
3. Display BST
4. Exit
Enter choice: 4
Exiting...
