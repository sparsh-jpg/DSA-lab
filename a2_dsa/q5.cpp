#include <bits/stdc++.h> 
using namespace std; 
void rotate(vector<int>& nums, int k) { 
        for(int i=0;i<nums.size()/2;i++){ 
            int swap=nums[i]; 
                nums[i]=nums[nums.size()-i-1]; 
                nums[nums.size()-i-1]=swap; 
        } 
        int a=k%nums.size(); 

        for(int i=0;i<a/2;i++){ 
            int swap=nums[i]; 
            nums[i]=nums[a-1-i]; 
            nums[a-1-i]=swap; 
        } 
        int x=1; 
        for(int i=a;i<=(nums.size()+a-1)/2;i++){ 
            int swap=nums[i]; 
            nums[i]=nums[nums.size()-x]; 
            nums[nums.size()-x]=swap; 
            x+=1; 
        } 
    } 
    int main(){ 
        int k; 
        cin >> k; 
        vector<int>nums={1,2,3,4,5}; 
        rotate(nums,k); 
        for(int i=0;i<nums.size();i++){ 
            cout << nums[i] << endl; 
        } 
        return 0; 
    }