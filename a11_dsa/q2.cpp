#include<iostream> 
using namespace std; 
struct Node{ 
    int data; 
    Node *left,*right; 
    Node(int x){ 
        data=x; 
        left=right=NULL; 
    } 
}; 
Node *first=NULL,*middle=NULL,*last=NULL,*previous=NULL; 
void recover(Node* root){ 
    if(root==NULL)return; 
    recover(root->left); 
    if(previous && root->data<previous->data){ 
        if(first==NULL){ 
            first=previous; 
            middle=root; 
        }else last=root; 
    } 
    previous=root; 
    recover(root->right); 
} 
void inorder(Node* root){ 
    if(root==NULL)return; 
    inorder(root->left); 
    cout<<root->data<<" "; 
    inorder(root->right); 
} 
int main(){ 
    Node* root=new Node(6); 
    root->left=new Node(10); 
    root->right=new Node(2); 
    root->left->left=new Node(1); 
    root->left->right=new Node(3); 
    root->right->right=new Node(12); 
    recover(root); 
    if(last){ 
        int t=first->data; 
        first->data=last->data; 
        last->data=t; 
    }else if(first && middle){ 
        int t=first->data; 
        first->data=middle->data; 
        middle->data=t; 
    } 
    cout<<"Recovered BST: "; 
    inorder(root); 
    return 0; 
} 