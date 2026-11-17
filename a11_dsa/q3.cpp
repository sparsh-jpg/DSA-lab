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
Node* p[100],*s[100]; 
int pt=-1,st=-1; 
void pred(Node* r,int x){ 
    while(r){ 
        if(r->data<=x){ 
            p[++pt]=r; 
            r=r->right; 
        }else r=r->left; 
    } 
} 
void succ(Node* r,int x){ 
    while(r){ 
        if(r->data>x){ 
            s[++st]=r; 
            r=r->left; 
        }else r=r->right; 
    } 
} 
int main(){ 
    Node* r=create(10); 
    r->left=create(5); 
    r->right=create(15); 
    r->left->left=create(2); 
    r->left->right=create(7); 
    r->right->left=create(12); 
    r->right->right=create(20); 
    int x=9,k=4; 
    pred(r,x); 
    succ(r,x); 
    for(int i=0;i<k;i++){ 
        if(pt==-1){ 
            cout<<s[st]->data<<" "; 
            Node* n=s[st--]; 
            for(n=n->right;n;n=n->left)s[++st]=n; 
        }else if(st==-1){ 
            cout<<p[pt]->data<<" "; 
            Node* n=p[pt--]; 
            for(n=n->left;n;n=n->right)p[++pt]=n; 
        }else if(x-p[pt]->data<=s[st]->data-x){ 
            cout<<p[pt]->data<<" "; 
            Node* n=p[pt--]; 
            for(n=n->left;n;n=n->right)p[++pt]=n; 
        }else{ 
            cout<<s[st]->data<<" "; 
            Node* n=s[st--]; 
            for(n=n->right;n;n=n->left)s[++st]=n; 
        } 
    } 
    return 0; 
}