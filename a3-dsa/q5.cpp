#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
unordered_map<int,int>hash;
for(int i=0;i<n;i++){
hash[arr[i]]+=1;
}
for(auto x:hash){
cout<<x.first<<" "<<x.second<<endl;
}
return 0;
}