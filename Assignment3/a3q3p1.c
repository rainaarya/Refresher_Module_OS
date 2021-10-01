#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *left, *right;
};

// Insert a node
struct node *insert(struct node *node, int val)
{
    // Return a new node if the tree is empty
    if (node == NULL) // Create a node
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    // Traverse to the right place and insert the node
    if (val < node->val)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);

    return node;
}

// Find the inorder successor
struct node *minNode(struct node *node)
{
    struct node *current = node;

    // Find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int val)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (val < root->val)
        root->left = deleteNode(root->left, val);
    else if (val > root->val)
        root->right = deleteNode(root->right, val);

    else
    {
        // If the node is with only one child or no child
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
            // If the node has two children
            struct node *temp = minNode(root->right);

            // Place the inorder successor in position of the node to be deleted
            root->val = temp->val;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

// Inorder Traversal
void inorder(struct node *root)
{
    if (root != NULL)
    {
        // Traverse left
        inorder(root->left);

        // Traverse root
        printf("%d ", root->val);

        // Traverse right
        inorder(root->right);
    }
}

// Driver code
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