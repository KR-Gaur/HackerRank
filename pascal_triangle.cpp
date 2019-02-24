#include<bits/stdc++.h>
using namespace std;
void copyToFromShiftRight(int a[],int b[]){
    //b to a
    for(int i=0; i<9 ; i++)
        a[i+1] = b[i];
}
void add(int a[], int b[], int c[]){
    for(int i=0; i<10 ; i++)
    	c[i] = a[i] + b[i];
}
void copyToFrom(int a[], int b[]){
    for(int i=0; i<10 ; i++)
        a[i] = b[i];
}
int main() {

	int n;
    int pre[10] = { 0 };
    int temp[10] = { 0 };
    int ans[10] = { 0 };
    
    cin>>n;
    pre[0] = 1;
    
    if(n)
    cout<<1<<endl;
    
    for(int i=2; i<=n; i++){
    	copyToFromShiftRight(temp,pre);
        add(temp,pre,ans);
        copyToFrom(pre,ans);
        
       for(int i=0; i<10 ; i++)
        if(pre[i]) cout<<pre[i]<<" ";
        
        cout<<endl;
    }
}
