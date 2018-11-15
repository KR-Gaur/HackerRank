#include<bits/stdc++.h>
using namespace std;
void rec(int i,vector<int>v2,vector<int>v){
 // if()
  if(i>v.size()) {
 /* for(int i=0;i<12;i++)
      cout<<v2[i]<<" ";
    cout<<endl;cout<<"*"<<endl;*/
    return;}
  if(v2.size()==12) {
    for(int i=0;i<12;i++)
      cout<<v2[i]<<" ";
    cout<<endl;
  }
  else {
    v2.push_back(v[i]);
    rec(i+1,v2,v);
    v2.pop_back();
    rec(i+1,v2,v);
  }
}
int main() {

  int n,t;
  cin>>n;
  vector<int>v,v2;
  for(int i=0;i<n;i++){
    cin>>t;
    v.push_back(t);
  }
  rec(0,v2,v);
}
