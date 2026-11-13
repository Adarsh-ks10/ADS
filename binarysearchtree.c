
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int key) {
    struct Node* node = malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        printf("%d already exists.\n", key);
    return root;
}
struct Node* minNode(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* succ = minNode(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void freeTree(struct Node* root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main() {
    struct Node* root = NULL;
    int choice, value;
    while (1) {
        printf("\n--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder\n");
        printf("4. Preorder\n");
        printf("5. Postorder\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            freeTree(root);
            return 1;
        }
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) {
                    freeTree(root);
                    return 1;
                }
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1) {
                    freeTree(root);
                    return 1;
                }
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                freeTree(root);
                printf("Program terminated.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}


---OUTPUT---

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 1
Enter value to insert: 10

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 1
Enter value to insert: 50

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 1
Enter value to insert: 30

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 1
Enter value to insert: 40

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 1
Enter value to insert: 20

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 3
Inorder: 10 20 30 40 50

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 4
Preorder: 10 50 30 20 40

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 5
Postorder: 20 40 30 50 10

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 2
Enter value to delete: 30

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 1
Enter value to insert: 20
20 already exists.

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 3
Inorder: 10 20 40 50

--- Binary Search Tree ---
1. Insert
2. Delete
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter choice: 6
Program terminated.
