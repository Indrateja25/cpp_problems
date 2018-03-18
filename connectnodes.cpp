#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  struct Node *nextRight;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
void Connect(Node* root){
    cout<<"root = "<<root->data<<endl;
    if(root->right ){
        if(root->left){
            root->left->nextRight = root->right;
            Connect(root->left);
        }
        root->right->nextRight = NULL;
        Node* temp = root;
        while(temp->nextRight){
            temp = temp->nextRight;
            if(temp->left){
                root->right->nextRight = temp->left;
                break;
            }
            else if(root->right){
                root->right->nextRight = temp->right;
                break;
            }
        }
        Connect(root->right);
    }
    else if(root->left){
        root->left->nextRight = NULL;
        Node* temp = root;
        while(temp->nextRight){
            temp = temp->nextRight;
            if(temp->left){
                root->left->nextRight = temp->left;
                break;
            }
            else if(root->right){
                root->left->nextRight = temp->right;
                break;
            }
        }
        Connect(root->left);
    }
    return;
}
void connect(Node *root)
{
   // Your Code Here
   if(!root)
     return;
    root->nextRight = NULL;
    Connect(root);
}
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

void printSpecial(Node *root)
{
   if (root == NULL)
     return;

   Node *node = root;
   while (node != NULL)
   {
      printf("%d ", node->data);
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout<<"root = "<< root->data <<endl;
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     printf("\n");
     connect(root);
     printSpecial(root);
     printf("\n");
     inorder(root);
     printf("\n");
  }
  return 0;
}
