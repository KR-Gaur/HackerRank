#include<bits/stdc++.h>
#include<stack>
#include<utility>
#include<map>
using namespace std;

vector<long long> solve (vector<int> arr) {

   // Write your code here
   vector<long long> result ;//= {5,4,2,1,1};
   map<long long,long long> result_in;

  // cout<<"hello";
   stack<pair<long,long>> s;
  
   s.push(make_pair(arr[0],1));
//    cout<<"pushed < "<<arr[0]<<", 1"<<" >"<<endl;

   for(auto i=1; i<arr.size(); i++){
    //    pair<long,long>g = make_pair(arr[i],1);
       if(s.top().first == arr[i])
       {
           //g.second = max(g.second,s.top().second);
        //    result.push_back(s.top().second);
           result_in.insert(pair<long long,long long>(s.top().first,s.top().second));

           int x = s.top().second;

           if(!s.empty())  s.pop();

        //    cout<< typeid(s.top()).name()<<endl;
            if(s.empty())  continue;
            pair <long ,long > l = make_pair(s.top().first,s.top().second + x);
            if(!s.empty()) s.pop();
            //else cout<<" stack empty!!! at "<<i<<endl;
            

            s.push(l);
            //result.push_back(l.second);
            // cout<<"pushed < "<<l.first<<", "<< l.second<<" >"<<endl;
       }
       else{
           pair<long,long>g = make_pair(arr[i],1);
           s.push(g);
        //    cout<<"pushed < "<<arr[i]<<", "<<1<<" >"<<endl;
       }
       
   }
    map<long long, long long>::iterator itr; 
    // cout << "\nThe map result_in is : \n"; 
    // cout << "\tKEY\tELEMENT\n"; 
    for (itr = result_in.begin(); itr != result_in.end(); ++itr) { 
        // cout << '\t' << itr->first 
        //      << '\t' << itr->second << '\n';
        result.push_back(itr->second);
    }
    return result; 
   
}

int main() {

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int N;
    int N=10;
    
    // cin >> N;
    // vector<int> arr(N);
    vector<int> arr = {1, 2, 3 ,5,6,6, 5 ,3 ,4 ,4 ,2 ,1};
    // for(int i_arr=0; i_arr<N; i_arr++)
    // {
    // cin >> arr[i_arr];
    // }

    vector<long long> out_;
   // cout<<"hello";
    out_ = solve(arr);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    cout << " "  << out_[i_out_];
    }
    cout<<endl;
    
}