#include<iostream>
using namespace std;
#define SIZE 5
struct ArrayQueue{
    int a[SIZE];
    int front,rear,count;
    ArrayQueue(){
        front=0;
        rear=-1;
        count=0;
    }
    void enqueue(int x){
        if(count==SIZE){

            cout<<"Queue Overflow\n";
            return;
        }
        rear=(rear+1)%SIZE;
        a[rear]=x;
        count++;
    }
    void dequeue(){
        if(count==0){
            cout<<"Queue Underflow\n";
            return;
        }
        cout<<"Dequeued: "<<a[front]<<endl;
        front=(front+1)%SIZE;
        count--;
    }
    void display(){
        if(count==0){
            cout<<"Queue is empty\n";
            return;
        }
        for(int i=0;i<count;i++){
            cout<<a[(front+i)%SIZE]<<" ";
        }
        cout<<endl;
    }
};
struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
struct ListQueue{
    Node *front,*rear;
    ListQueue(){
        front=rear=NULL;

    }
    void enqueue(int x){
        Node* n=new Node(x);
        if(rear==NULL){
            front=rear=n;
        }else{
            rear->next=n;
            rear=n;
        }
    }
    void dequeue(){
        if(front==NULL){
            cout<<"Queue Underflow\n";
            return;
        }
        Node* t=front;
        cout<<"Dequeued: "<<t->data<<endl;
        front=front->next;
        if(front==NULL) rear=NULL;
        delete t;
    }
    void display(){
        if(front==NULL){
            cout<<"Queue is empty\n";
            return;
        }
        for(Node* t=front;t;t=t->next){
            cout<<t->data<<" ";
        }
        cout<<endl;
    }
};
int main(){
    cout<<"Queue using Array:\n";
    ArrayQueue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.display();
    q1.dequeue();
    q1.display();

    cout<<"\nQueue using Linked List:\n";
    ListQueue q2;
    q2.enqueue(10);
    q2.enqueue(20);
    q2.enqueue(30);
    q2.display();
    q2.dequeue();
    q2.display();
    return 0;
}