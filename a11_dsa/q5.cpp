#include<iostream> 
#include<sstream> 
using namespace std; 
struct Node{ 
    int data; 
    Node *left,*right; 
    Node(int x){ 
        data=x; 
        left=right=NULL; 
    } 
}; 
void save(Node* r,string &s){ 
    if(r==NULL){ 
        s+="# "; 
        return; 
    } 
    s+=to_string(r->data)+" "; 
    save(r->left,s); 
    save(r->right,s); 
} 
Node* load(stringstream &ss){ 
    string s; 
    ss>>s; 
    if(s=="#")return NULL; 
    Node* r=new Node(stoi(s)); 
    r->left=load(ss); 
    r->right=load(ss); 
    return r; 
} 
void inorder(Node* r){ 
    if(r==NULL)return; 
    inorder(r->left); 
    cout<<r->data<<" "; 
    inorder(r->right); 
} 
int main(){ 
    Node* r=new Node(1); 
    r->left=new Node(2); 
    r->right=new Node(3); 
    r->left->left=new Node(4); 
    r->left->right=new Node(5); 
    string s=""; 
    save(r,s); 
    cout<<"Serialized: "<<s<<endl; 
    stringstream ss(s); 
    Node* r2=load(ss); 
    cout<<"Tree after deserialization: "; 
    inorder(r2); 
    return 0; 
}