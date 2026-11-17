#include<iostream>
using namespace std;
void sortArr(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
bool can(int k,int tasks[],int n,int workers[],int m,int pills,int strength){
    int dq[1000];
    int head=0,tail=0,ptr=0;
    for(int w=m-k;w<m;w++){
        while(ptr<k && tasks[ptr]<=workers[w]+strength){
            dq[tail++]=tasks[ptr++];
        }
        if(head==tail) return false;
        if(dq[head]<=workers[w]){
            head++;
        }else{
            if(pills==0) return false;
            pills--;
            tail--;
        }
    }
    return true;
}
int maxTasks(int tasks[],int n,int workers[],int m,int pills,int strength){
    sortArr(tasks,n);
    sortArr(workers,m);
    int lo=0,hi=(n<m)?n:m,ans=0;

    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(can(mid,tasks,n,workers,m,pills,strength)){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return ans;
}
int main(){
    int tasks[]={3,2,1};
    int workers[]={0,3,3};
    cout<<"Maximum tasks: "<<maxTasks(tasks,3,workers,3,1,1)<<endl;
    return 0;
}