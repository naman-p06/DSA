#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
   vector<pair<pair<int, int>, int>> ans;
   map<int,list<pair<int,int>>> adj;
   for(int i=0;i<g.size();i++){
       int u=g[i].first.first;
       int v=g[i].first.second;
       int w=g[i].second;
       adj[u].push_back({v,w});
       adj[v].push_back({u,w});
   }
   vector<int> parent(n+1,-1);
   vector<bool> mst(n+1,false);
    vector<int> key(n+1,INT_MAX);
    key[1]=0;
    for(int i=1;i<=n;i++){
        int mini=INT_MAX;
        int u;
        for(int j=1;j<=n;j++){
            if(mst[j]==false && key[j]<mini){
                u=j;
                mini=key[j];
            }
        }
        mst[u]=true;
        for(auto j:adj[u]){
            if(!mst[j.first]&&j.second<key[j.first]){
                key[j.first]=j.second;
                parent[j.first]=u;
            }
        }
    }
    for(int i=2;i<=n;i++){
        
            ans.push_back({{parent[i],i},key[i]});
        
    }
    return ans;
}
