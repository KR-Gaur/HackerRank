
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int node, d;
};

void find(unordered_map<int , vector<Node>> &g, int s, int e, int &count, unordered_map<int,int> &dist){
    
    unordered_map<int,int> visited;
    priority_queue< pair<int,int> , vector< pair<int,int> >, greater<pair<int,int> > > pq;
   

    pq.push(pair<int,int>(0, s));
    while(!pq.empty()){
        pair<int, int> f = pq.top();
        // cout<<"popped-"<<f.second<<endl;
        pq.pop();
        if(visited[f.second]) continue;
        visited[f.second]=1;
        for( Node c: g[f.second] ){
            if(!visited[c.node] && dist[c.node] > c.d + f.first) { 
                dist[c.node] = c.d+f.first;
                pq.push( pair<int,int>(dist[c.node], c.node) );
            }
        }
    }
        
}


int main(){

    unordered_map<int,vector<Node> > g;
    unordered_map<int,int> dist;

    int n;
    // Number of Nodes
    cin>>n;

    int node;
    while(n--){
        // Enter Node number
        cin>>node;
        g.insert(pair< int,vector<Node> >(node,vector<Node>()) );
        dist[node] = INT_MAX;
    }

    int edges, s, e, d;
    cin>>edges;

    while(edges--){
        // u v distance
        cin>>s>>e>>d;
        g[s].push_back({e,d});
        g[e].push_back({s,d});
    }

    cin>>s>>e;
    int count=INT_MAX;
    if(s==e) cout<<"Minimum Distance ("<<s<<"->"<<e<<")"<<min(0,count);
    else { find(g, s, e, count, dist); cout<<"Minimum Distance ("<<s<<"->"<<e<<") : "<<dist[e]; }

    return 0;

    /*
    Number of Nodes
    4
    Nodes
    7
    9
    5
    2
    4
    U V Distance
    7 2 3
    2 9 2
    7 9 7
    9 5 1
    Source
    7
    Target
    9
    Distance (7->9) : 5
    */
}