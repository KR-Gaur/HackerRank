#include<bits/stdc++.h>
using namespace std;
void make_tree(vector<int>&v,int segTree[],int i,int j,int pos){
    if(i==j) {segTree[pos]=v[i]; return;}
    int mid = (i+j)/2;
    make_tree(v,segTree,i,mid,2*pos+1);
    make_tree(v,segTree,mid+1,j,2*pos+2);
    segTree[pos] = min(segTree[2*pos+1],segTree[2*pos+2]);
}
void update(vector<int>&v,int segTree[],int i,int j,int pos,int index,int val){

    int mid = (i+j)/2;
    if(i == j) { 
        v[index] = val;         
        segTree[pos] = val; 
        return; 
    }
    if(i<=index && index<=mid)
    update(v,segTree,i,mid,2*pos+1,index,val);
    else
    update(v,segTree,mid+1,j,2*pos+2,index,val);

    segTree[pos] = min(segTree[2*pos+1],segTree[2*pos+2]);
}
int RMQ(int segTree[],int qi,int qj,int i,int j,int pos){
    if(qj<i || qi>j) return INT_MAX;
    if(qi<=i && qj >=j) return segTree[pos];
    int mid = (i+j)/2;
    return min(RMQ(segTree,qi,qj,i,mid,2*pos+1),RMQ(segTree,qi,qj,mid+1,j,2*pos+2)) ;
}
int main(){

    int a[] = {-1,2,4,0};
    vector<int> v={-1,2,4,0,1};
    // int size = sizeof(a)/sizeof(a[0]);
    int size = v.size();
    int *segTree = new int [2*size-1];
    // cout<< 2 * pow(2,ceil(log(5)/log(2)))-1;
    make_tree(v,segTree,0,size-1,0);

    // for(int i=0;i<2*size-1;i++) cout<<segTree[i]<<" ";
    // cout<<endl;
    for(int i=0;i<size;i++) cout<<v[i]<<" ";
    cout<<endl;
    cout<<"RMQ = "<< RMQ(segTree,0,2,0,size-1,0)<<endl;

    update(v,segTree,0,size-1,0,0,-100);
    for(int i=0;i<size;i++) cout<<v[i]<<" ";
    cout<<endl;
    cout<<"RMQ = "<< RMQ(segTree,0,2,0,size-1,0)<<endl;
    return 0;
}