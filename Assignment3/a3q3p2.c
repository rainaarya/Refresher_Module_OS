// C program for Balanced BST
#include <stdio.h>
#include <stdlib.h>

// An AVL tree node
struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    int height;
};

/* Given a non-empty binary search tree, return the
node with minimum val value found in that tree.
Note that the entire tree does not need to be
searched. */
struct Node *minNode(struct Node *node)
{
    struct Node *temp = node;

    /* loop down to find the leftmost leaf */
    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

// A utility function to get height of the tree
int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        return root->height;
    }
}

// A utility function to get maximum of two integers
int maximum(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

/* Helper function that allocates a new node with the given val and
	NULL left and right pointers. */
struct Node *newNode(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially added at leaf
    return node;
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *root)
{
    struct Node *temp1 = root->left;
    struct Node *temp2 = temp1->right;

    // Perform rotation
    temp1->right = root;
    root->left = temp2;

    // Update heights
    root->height = maximum(height(root->left), height(root->right)) + 1;
    temp1->height = maximum(height(temp1->left), height(temp1->right)) + 1;

    // Return new root
    return temp1;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *root)
{
    struct Node *temp1 = root->right;
    struct Node *temp2 = temp1->left;

    // Perform rotation
    temp1->left = root;
    root->right = temp2;

    // Update heights
    root->height = maximum(height(root->left), height(root->right)) + 1;
    temp1->height = maximum(height(temp1->left), height(temp1->right)) + 1;

    // Return new root
    return temp1;
}

// Get Balance factor of node N
int balfactor(struct Node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

struct Node *insert(struct Node *node, int val)
{
    /* 1. Perform the normal BST rotation */
    if (node == NULL)
        return newNode(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else // Equal keys not allowed
        return node;

    /* 2. Update height of this ancestor node */
    node->height = maximum(height(node->left), height(node->right)) + 1;

    /* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
    int balance = balfactor(node);

    // If this node becomes unbalanced, then there are 4 cases

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

    /* return the (unchanged) node pointer */
    return node;
}



// Recursive function to delete a node with given val
// from subtree with given root. It returns root of
// the modified subtree.
struct Node *delete(struct Node *root, int val)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the val to be deleted is smaller than the
    // root's val, then it lies in left subtree
    if (val < root->val)
        root->left = delete(root->left, val);

    // If the val to be deleted is greater than the
    // root's val, then it lies in right subtree
    else if (val > root->val)
        root->right = delete(root->right, val);

    // if val is same as root's val, then This is
    // the node to be deleted
    else
    {
        // If the node is with only one child or no child
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
            // If the node has two children
            struct Node *temp = minNode(root->right);

            // Place the inorder successor in position of the node to be deleted
            root->val = temp->val;

            // Delete the inorder successor
            root->right = delete(root->right, temp->val);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = maximum(height(root->left), height(root->right)) + 1;

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = balfactor(root);

    // If this node becomes unbalanced, then there are 4 cases

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

// A utility function to print preorder traversal of
// the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Driver program to test above function*/
int main()
{
    struct Node *root = NULL;
    int choice;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y')
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
            root = insert(root, value);
            printf("Value has been Inserted!");
            break;
        case 2:
            printf("\nEnter value to be Deleted in BST: ");
            scanf("%d", &value);
            root = delete(root, value);
            printf("Value has been Deleted! (if it existed)");
            break;

        case 3:
            printf("\nPreorder traversal of Height Balanced BST currently: ");
            preOrder(root);
            break;

        default:
            printf("\nInvalid option selected.\n");
        }

        printf("\nDo you want to repeat the Menu? (y/n): ");
        getchar();
        scanf("%c", &ch);
    }
}
