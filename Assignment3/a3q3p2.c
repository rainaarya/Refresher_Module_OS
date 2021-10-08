//Height Balanced BST
#include <stdio.h>
#include <stdlib.h>

// Implementation using AVL tree
struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to find minimum Node
struct Node *minNode(struct Node *node)
{
    struct Node *temp = node;

    // loop to find the leftmost node
    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

// Function to get height of tree
int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        return root->height;
    }
}

// Function to find maximum
int maximum(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Function that initialises a new Node
struct Node *newNode(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // the new node is initially added at leaf
    return node;
}

// Function to right rotate subtree rooted with root

struct Node *rightRotate(struct Node *root)
{
    struct Node *temp1 = root->left;
    struct Node *temp2 = temp1->right;

    // First, Perform rotation
    temp1->right = root;
    root->left = temp2;

    //After that, we need to Update the heights
    root->height = maximum(height(root->left), height(root->right)) + 1;
    temp1->height = maximum(height(temp1->left), height(temp1->right)) + 1;

    //Finally, return the new root
    return temp1;
}

// Function to left rotate subtree rooted with root

struct Node *leftRotate(struct Node *root)
{
    struct Node *temp1 = root->right;
    struct Node *temp2 = temp1->left;

    // First, Perform rotation
    temp1->left = root;
    root->right = temp2;

    //After that, we need to Update the heights
    root->height = maximum(height(root->left), height(root->right)) + 1;
    temp1->height = maximum(height(temp1->left), height(temp1->right)) + 1;

    //Finally, return the new root
    return temp1;
}

// Function to get BF(Balance factor) of node root
int balfactor(struct Node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

//Function to insert in the AVL TREE
struct Node *insert(struct Node *node, int val)
{
    //First, Perform the normal insertion of BST
    if (node == NULL)
        return newNode(val);

    // If val<node's val, then val is in left subtree
    if (val < node->val)
        node->left = insert(node->left, val);
    
    // If val>node's val, then val is in right subtree
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        return node;

    // Then we need to update height of ancestor node
    node->height = maximum(height(node->left), height(node->right)) + 1;

    // Get the balance factor
    int balance = balfactor(node);

    // Left Left Case
    if (balance > 1 && val < node->left->val)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && val > node->right->val)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && val > node->left->val)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && val < node->right->val)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to delete a node
struct Node *delete (struct Node *root, int val)
{
    // First, perform normal BST deletion

    if (root == NULL)
        return root;

    // If val<root's val, then val is in left subtree
    if (val < root->val)
        root->left = delete (root->left, val);

    // If val>root's val, then val is in right subtree
    else if (val > root->val)
        root->right = delete (root->right, val);

    //otherwise, delete this node
    else
    {
        // If node has one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        else
        {
            // If the node has two children then do this
            struct Node *temp = minNode(root->right);

            // Put inorder successor in position of the node which is to be deleted
            root->val = temp->val;

            // Remove inorder successor
            root->right = delete (root->right, temp->val);
        }
    }

    if (root == NULL)
        return root;

    // After this, we need to update height of node (current one)
    root->height = maximum(height(root->left), height(root->right)) + 1;

    // Then, get the balance factor
    int balance = balfactor(root);

    // Left Left Case
    if (balance > 1 && balfactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && balfactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && balfactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && balfactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to print preorder traversal of Height Balacned BST
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y') //menu driven program
    {
        printf("\n\t\t\tHeight Balanced Binary Search Tree:");
        printf("\nEnter Your Choice\n1) Insertion\n2) Deletion\n3) Display Preorder Traversal\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:;
            int value;
            printf("\nEnter value to be Inserted in Height Balacned BST: ");
            scanf("%d", &value);
            root = insert(root, value); //insert value into Height Balanced BST and assign retuned node to root
            printf("Value has been Inserted!");
            break;
        case 2:
            printf("\nEnter value to be Deleted in BST: ");
            scanf("%d", &value);
            root = delete (root, value); //insert value from Height Balanced BST and assign retuned node to root
            printf("Value has been Deleted! (if it existed)");
            break;

        case 3:
            printf("\nPreorder traversal of Height Balanced BST currently: ");
            preOrder(root); //print pre-order traversal
            break;

        default:
            printf("\nInvalid option selected.\n");
        }

        printf("\nDo you want to repeat the Menu? (y/n): ");
        getchar();
        scanf("%c", &ch);
    }
}
