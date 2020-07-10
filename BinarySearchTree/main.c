
#include<stdio.h>
#include<stdlib.h>
int IDs[10];
struct node
{
    char key;
    struct node *left, *right;
};

struct node *newNode(char item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
    return newNode(key);
    
    if (key < node->key)
    node->left  = insert(node->left, key);
    else
    node->right = insert(node->right, key);
    
    return node;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
    
    while (current->left != NULL)
    current = current->left;
    
    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
    return root;
    
    if (key < root->key)
    root->left = deleteNode(root->left, key);
    
    else if (key > root->key)
    root->right = deleteNode(root->right, key);
    
    else
    {
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
        
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

struct node *search(struct node *root, int value)
{
    while(root!=NULL && value!=root->key)
    {
        if(value < root->key)
        root = root->left;
        else
        root = root->right;
    }
    return(root);
}

// Driver Program to test above functions
int main()
{
    struct node *root = NULL;
    struct node *temp;
    int id;
    char student_name[50],grades[10];
    printf("BINARY SEARCH TREE OPERATIONS");
    for(int i=0; i < 10; i++)
    {
        id = rand() % 100 + 2;
        if(id < 10)
        id = rand() % 100 - 2;
        if(id > 10)
        {
            IDs[i] = id;
            printf("\n\nEnter the Student Name :");
            scanf("%s",student_name);
            printf("\nThe Student Name : %s",student_name);
            printf("\nThe student ID : %d \n", id);
            
            for(int x=0; x < 10; x++)
            {
                scanf("%s",grades);
                printf("%s ",grades);
            }
            root = insert(root,id);
            
            printf("\nInorder traversal of the given tree after Insertion \n");
            inorder(root);
        }
    }
    printf("\nDelete a node 32");
    root = deleteNode(root, 32);
    printf("\nDeleted the node");
    printf("\nInorder traversal of the modified tree after Deletion\n");
    inorder(root);
    
    printf("\nDelete a node 47");
    root = deleteNode(root, 47);
    printf("\nDeleted the node");
    printf("\nInorder traversal of the modified tree after Deletion\n");
    inorder(root);
    
    /* Search node into tree */
    printf("\nSearch Operation");
    temp = search(root, 60);
    if (temp)
    {
        printf("\nFound the node = %d\n", temp->key);
    }
    else
    {
        printf("\nData Not found in tree.\n");
    }
    printf("\nInorder traversal of the tree \n");
    inorder(root);
    
    printf("\n");
    return 0;
}

