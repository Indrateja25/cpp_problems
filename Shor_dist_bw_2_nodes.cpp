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
int DistFromRoot(BST* root,int x){
    if(root->data == x || !root)
        return 0;
    else if(root->data > x)
        return 1+DistFromRoot(root->left,x);
    return 1+DistFromRoot(root->right,x);
}
int ShorDist(BST* root,int a,int b){
    if(!root || a==b)
        return 0;
    if(a < root->data && b < root->data)
        return ShorDist(root->left,a,b);
    else if(a > root->data && b > root->data)
        return ShorDist(root->right,a,b);
    return DistFromRoot(root,a)+DistFromRoot(root,b);
}
int main(){
    BST* root = new BST();
    root = NULL;
    root = insert(root,15);
    root = insert(root,5);
    root = insert(root,9);
    root = insert(root,18);
    root = insert(root,12);
    root = insert(root,26);
    root = insert(root,70);
    root = insert(root,140);

    printInorder(root);

    int a,b;
    cout<<endl<<"Enter Points: ";
    cin>>a>>b;
    cout<<"Shortest Distance b/w "<<a<<" & "<<b<<" is ";
    cout<<ShorDist(root,a,b);
}
