#include <bits/stdc++.h> 
#include <chrono> 
using namespace std; 
using namespace std::chrono; 
  
void bubbleSort(vector<int>& arr){ 
    int n=arr.size(); 

    for(int i=0;i<n-1;i++){ 
        for(int j=0;j<n-i-1;j++){ 
            if(arr[j]>arr[j+1]){ 
                swap(arr[j],arr[j+1]); 
            } 
        } 
    } 
} 
  
void insertionSort(vector<int>& arr){ 
    int n=arr.size(); 
    for(int i=1;i<n;i++){ 
        int key=arr[i]; 
        int j=i-1; 
  
        while(j>=0 && arr[j]>key){ 
            arr[j+1]=arr[j]; 
            j--; 
        } 
  
        arr[j+1]=key; 
    } 
} 
  
int main(){ 
    int n; 
    cin>>n; 
  
    vector<int> arr(n); 
  
    for(int i=0;i<n;i++){ 
        cin>>arr[i]; 
    } 
  
    vector<int> bubble=arr; 
    vector<int> insertion=arr; 
  
    auto start1=high_resolution_clock::now(); 
    bubbleSort(bubble); 
    auto end1=high_resolution_clock::now(); 
  
    auto duration1=duration_cast<microseconds>(end1-start1); 
  
    auto start2=high_resolution_clock::now(); 
    insertionSort(insertion); 
    auto end2=high_resolution_clock::now(); 

  
    auto duration2=duration_cast<microseconds>(end2-start2); 
  
    cout<<"Bubble Sort Output:\n"; 
    for(int x:bubble) 
        cout<<x<<" "; 
  
    cout<<"\nTime: "<<duration1.count()<<" microseconds\n"; 
  
    cout<<"\nInsertion Sort Output:\n"; 
    for(int x:insertion) 
        cout<<x<<" "; 
  
    cout<<"\nTime: "<<duration2.count()<<" microseconds\n"; 
  
    return 0; 
}