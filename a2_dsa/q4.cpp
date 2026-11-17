#include <bits/stdc++.h> 
using namespace std; 
  
int main(){ 
    int m,n; 
    cin>>m>>n; 
  
    int arr[m][n]; 
  
    for(int i=0;i<m;i++){ 
        for(int j=0;j<n;j++){ 
            cin>>arr[i][j]; 
        } 
    } 
  
    int count=0; 
  
    for(int i=0;i<m;i++){ 
        for(int j=0;j<n;j++){ 
            if(arr[i][j]!=0){ 
                count++; 
            } 
        } 
    } 
  
    int sparse[count+1][3]; 
  
    sparse[0][0]=m; 
    sparse[0][1]=n; 
    sparse[0][2]=count; 
  
    int k=1; 
  
    for(int i=0;i<m;i++){ 
        for(int j=0;j<n;j++){ 
            if(arr[i][j]!=0){ 
                sparse[k][0]=i; 
                sparse[k][1]=j; 
                sparse[k][2]=arr[i][j]; 
                k++; 
            } 
        } 
    } 
  
    cout<<"Sparse Matrix :\n"; 
  
    for(int i=0;i<=count;i++){ 
        for(int j=0;j<3;j++){ 
            cout<<sparse[i][j]<<" "; 
        } 
        cout<<endl; 
    } 
  
    return 0; 
}