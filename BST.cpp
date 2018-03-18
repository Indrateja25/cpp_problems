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

bool SearchKey(BST* root,int key){
    if(!root)
         return 0;
    //cout<<"root = "<<root->data<<" key = "<<key<<endl;
    if(root->data < key)
        return SearchKey(root->right,key);
    else if(root->data > key)
        return SearchKey(root->left,key);
    return 1;
}

int inordsucc(BST* root,int s){
    while(root->left){
       root = root->left;
    }
    return root->data;
}

BST* deleteNode(BST* root,int x){
  if(!root)
    return NULL;
  if(root->data > x)
    root->left =  deleteNode(root->left,x);
  else if (root->data < x)
    root->right = deleteNode(root->right,x);
  else{
      BST* temp = root;
      if(!root->left && !root->right){
        delete(temp);
        return NULL;
      }
      else if(!root->left && root->right){
        delete(temp);
        return root->right;
      }
      else if(root->left && !root->right){
        delete(temp);
        return root->left;
      }
      else{
          int s = inordsucc(root->right,x);
          root = deleteNode(root,s);
          root->data = s;
      }
  }
  return root;
}

int maxnode(BST* root){
    while(root->right)
        root = root->right;
    return root->data;
}
int LSN(BST* root,int N){
    if(!root)
        return -1;
    cout<<"root = "<<root->data<<endl;
    if(root->data > N)
        return LSN(root->left,N);
    else if(root->data < N){
        if(root->right && root->right->data < N)
           return LSN(root->right,N);
    }
    return root->data;
}

//second largest element -approach 1
int seclarg2(BST* root){
    if(!root)
        return -1;
    if(!root->right)
        return maxnode(root->left);
    else if(!root->right->right && root->right->left)
        return maxnode(root->right->left);
    else if(root->right->right)
        return seclarg2(root->right);
    return root->data;
}

//second largest element -approach 2
int seclarg(BST* root){
    if(!root)
        return -1;
    BST* parent = NULL;
    while(root->right){
        parent = root;
        root = root->right;
    }
    if(root->left)
       return maxnode(root->left);
    return parent->data;
}
//Kth largest element
int kthlarg(BST* root,int k,int &c,int &temp){
    if(!root )
        return -1;
    if(root->right)
      kthlarg(root->right,k,c,temp);
    c++;
    if(c==k){
        temp = root->data;
    }
    if(root->left);
      kthlarg(root->left,k,c,temp);
    return temp;
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

    int Key;
    cout<<endl<<"Enter Search key : ";
    cin>>Key;
    bool s = SearchKey(root,Key);
    cout<<s<<endl;
    if(s){

    }
  /*root = deleteNode(root,14); //leaf
    root = deleteNode(root,18); //single-childed
    root = deleteNode(root,15); //double-childed

    printInorder(root);
    */
     cout<<"largest: "<<maxnode(root)<<endl;
     cout<<"second largest: "<<seclarg(root)<<endl;
     int c=0,temp = 0 ,k;
     cin>>k;
     cout<<"kth-largest: "<<kthlarg(root,k,c,temp);
}
