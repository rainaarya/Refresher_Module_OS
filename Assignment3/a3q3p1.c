#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *left, *right;
};

// To Insert node
struct node *insert(struct node *node, int val)
{
    // Return a new node when tree is empty
    if (node == NULL) // Create node
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    // Insert the node
    if (val < node->val)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);

    return node;
}

// To Find inorder successor
struct node *minNode(struct node *node)
{
    struct node *current = node;

    // Find leftmost node
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int val)
{
    // Return NULL if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted (normal deletion process)
    if (val < root->val)
        root->left = deleteNode(root->left, val);
    else if (val > root->val)
        root->right = deleteNode(root->right, val);

    else
    {
        // If node has one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        else
        {
            // If the node has two children then do this
            struct node *temp = minNode(root->right);

            // Put inorder successor in position of the node which is to be deleted
            root->val = temp->val;

            // Remove inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

// Inorder Traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        // For Traversing left
        inorder(root->left);

        // For printing the root
        printf("%d ", root->val);

        //For Traversing right
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int choice;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y')
    {
        printf("\n\t\t\tBinary Search Tree:");
        printf("\nEnter Your Choice\n1) Insertion\n2) Deletion\n3) Display Inorder Traversal\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:;
            int value;
            printf("\nEnter value to be Inserted in BST: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Value has been Inserted!");
            break;
        case 2:
            printf("\nEnter value to be Deleted in BST: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Value has been Deleted! (if it existed)");
            break;

        case 3:
            printf("\nInorder traversal of BST currently: ");
            inorder(root);
            break;

        default:
            printf("\nInvalid option selected.\n");
        }

        printf("\nDo you want to repeat the Menu? (y/n): ");
        getchar();
        scanf("%c", &ch);
    }
}