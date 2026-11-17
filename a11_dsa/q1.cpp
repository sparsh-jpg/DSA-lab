#include<iostream> 
using namespace std; 
struct Node{ 
    int data; 
    Node *left,*right; 
}; 
Node* create(int x){ 
    Node* n=new Node; 
    n->data=x; 
    n->left=n->right=NULL; 
    return n; 
} 
int a[100],vis[100]={0},level[100]; 
void topview(Node* root,int h,int d){ 
    if(root==NULL) return; 
    if(vis[h+50]==0 || d<level[h+50]){ 
        a[h+50]=root->data; 
        level[h+50]=d; 
        vis[h+50]=1; 
    } 
    topview(root->left,h-1,d+1); 
    topview(root->right,h+1,d+1); 
} 
int main(){ 
    Node* root=create(1); 
    root->left=create(2); 
    root->right=create(3); 
    root->left->left=create(4); 
    root->left->right=create(5); 
    topview(root,0,0); 
    for(int i=0;i<100;i++){ 
        if(vis[i]) 
            cout<<a[i]<<" "; 
    } 
    return 0; 
} 