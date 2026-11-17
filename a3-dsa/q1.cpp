#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
int minPrice=arr[0];
int a=0,b=0,maxProfit=0;
for(int i=1;i<n;i++){
if(arr[i]-minPrice>maxProfit){
maxProfit=arr[i]-minPrice;
b=i;
}
if(arr[i]<minPrice){
minPrice=arr[i];
a=i;
}
}
cout<<maxProfit;
return 0;
}