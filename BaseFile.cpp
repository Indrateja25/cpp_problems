#include<iostream>
using namespace std;

struct BST {
  int data;
  BST* left;
  BST* right;
};

BST* newnode(int data){
    BST* Node = new BST();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

BST* insert(BST* root,int key){
    if(root == NULL){
      root =  newnode(key);
      return root;
    }
    if(root->data >= key){
      root->left = insert(root->left,key);

    }
    else{
      root->right = insert(root->right,key);
    }
    return root;
}

void printInorder(BST* root){
   if(root->left)
      printInorder(root->left);
   cout<<root->data<<" ";



   if(root->right)
      printInorder(root->right);

}

int main(){
    BST* root = new BST();
    root = NULL;

    //Insertions
    root = insert(root,15);
    root = insert(root,5);
    root = insert(root,9);
    root = insert(root,18);
    root = insert(root,12);
    root = insert(root,26);
    root = insert(root,70);
    root = insert(root,140);

    printInorder(root);
}
