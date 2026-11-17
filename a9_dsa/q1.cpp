#include<iostream>
using namespace std;
int maxGroup(int a[],int n,int K){
    int dmax[1000],dmin[1000];
    int hmax=0,tmax=0,hmin=0,tmin=0;
    int i=0,best=0;
    for(int j=0;j<n;j++){
        while(tmax>hmax && a[dmax[tmax-1]]<=a[j]) tmax--;
        dmax[tmax++]=j;
        while(tmin>hmin && a[dmin[tmin-1]]>=a[j]) tmin--;
        dmin[tmin++]=j;
        while(a[dmax[hmax]]-a[dmin[hmin]]>K){
            i++;
            if(dmax[hmax]<i) hmax++;
            if(dmin[hmin]<i) hmin++;
        }
        if(j-i+1>best) best=j-i+1;
    }
    return best;
}
int main(){
    int a1[]={8,2,4,7};
    int a2[]={10,1,2,4,7,2};
    cout<<"Example 1: "<<maxGroup(a1,4,4)<<endl;
    cout<<"Example 2: "<<maxGroup(a2,6,5)<<endl;
    return 0;
}