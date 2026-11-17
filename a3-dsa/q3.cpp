#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
int ans[n];
int left=1;
for(int i=0;i<n;i++){
ans[i]=left;
left*=arr[i];
}
int right=1;
for(int i=n-1;i>=0;i--){
ans[i]*=right;
right*=arr[i];
}
for(int i=0;i<n;i++){
cout<<ans[i]<<" ";
}
return 0;
}