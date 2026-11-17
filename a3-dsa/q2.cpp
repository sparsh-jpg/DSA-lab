#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
int total=0;
for(int i=0;i<n;i++){
cin>>arr[i];
total+=arr[i];
}
int left=0;
for(int i=0;i<n;i++){
int right=total-left-arr[i];
if(left==right){
cout<<"req idx:"<<i<<" ";
}
left+=arr[i];
}
return 0;
}