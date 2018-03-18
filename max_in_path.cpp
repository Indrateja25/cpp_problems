
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

BST* LCA(BST* root,int a,int b){
    if(!root )
        return NULL;
    if(a < root->data && b < root->data)
        return LCA(root->left,a,b);
    else if(a > root->data && b > root->data)
        return LCA(root->right,a,b);
    return root;
}
int maxelm(BST* root,int a,int b){
   BST* lca = LCA(root,a,b);
   cout<<"lca = "<<lca->data<<endl;
   while(b >= lca->data && lca->right){
       lca = lca->right;
   }
   return lca->data;
}
int main(){
    BST* root = new BST();
    root = NULL;

    //Insertions
    root = insert(root,18);
    root = insert(root,36);
    root = insert(root,9);
    root = insert(root,6);
    root = insert(root,12);
    root = insert(root,10);
    root = insert(root,1);
    root = insert(root,8);

    printInorder(root);
    int a,b;
    cout<<endl;
    cin>>a>>b;
    if(a>b){
        int temp = a;
        a = b;
        b = temp;
    }
    cout<<"Maximum element between "<<a<<" & "<<b<<" is "<<maxelm(root,a,b);
}
