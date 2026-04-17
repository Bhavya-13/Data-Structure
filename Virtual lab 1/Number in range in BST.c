#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void findInRange(struct Node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->data > low)
        findInRange(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (root->data < high)
        findInRange(root->right, low, high);
}

int main() {
    struct Node* root = NULL;
    int low, high;

    int values[] = {10, 5, 50, 1, 40, 100};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Enter low value: ");
    scanf("%d", &low);
    printf("Enter high value: ");
    scanf("%d", &high);

    printf("Nodes in range [%d, %d]: ", low, high);
    findInRange(root, low, high);
    printf("\n");

    printf("Code Executed Succesfully");

    return 0;
}
