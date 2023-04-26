// English ver.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char data[20];
    struct node *left, *right;
};

struct node *newNode(char data[]) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->data, data);
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, char data[]) {
    if(root == NULL)
        return newNode(data);

    if(strcmp(data, root->data) < 0)
        root->left = insert(root->left, data);
    else if(strcmp(data, root->data) > 0)
        root->right = insert(root->right, data);

    return root;
}

void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
    }
}

struct node *search(struct node *root, char data[]) {
    if(root == NULL || strcmp(root->data, data) == 0)
        return root;

    if(strcmp(root->data, data) < 0)
        return search(root->right, data);

    return search(root->left, data);
}

int main() {
    struct node *root = NULL;
    int n, i;
    char data[20], search_data[20];
    printf("Enter the number of data strings (max. 10): ");
    scanf("%d", &n);
    printf("\nEnter the data strings:\n");
    for(i=0; i<n; i++) {
        scanf("%s", data);
        root = insert(root, data);
    }
    printf("\nInorder traversal of the Binary Search Tree: ");
    inorder(root);
    printf("\nEnter the data to be searched: ");
    scanf("%s", search_data);
    struct node *result = search(root, search_data);
    if(result != NULL)
        printf("\n%s found at location %p", result->data, result);
    else
        printf("\n%s not found", search_data);

    return 0;
}
