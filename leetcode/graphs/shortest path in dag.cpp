#include <bits/stdc++.h>
using namespace std;

class Solution {
    void top(map<int,list<pair<int,int>>> &adj,stack<int> &sorted,map<int,bool>vis,int src){
        for(auto j:adj[src]){
            if(!vis[j.first]){
                vis[j.first]=true;
                top(adj,sorted,vis,j.first);
            }
        }
        sorted.push(src);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        map<int,list<pair<int,int>>> adj;
        for(int i=0;i<E;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int t=edges[i][2];
            pair<int,int>p=make_pair(v,t);
            adj[u].push_back(p);
        }
        stack<int> s;
        map<int,bool>vis;
        int src=0;
        top(adj,s,vis,src);
        vector<int>dis(V,10000);
        dis[s.top()]=0;
        while(!s.empty()){
            int a=s.top();
            s.pop();
            for(auto j:adj[a]){
                if(dis[a]+j.second<dis[j.first]){
                    dis[j.first]=dis[a]+j.second;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dis[i]==10000){
                dis[i]=-1;
            }
        }
        return dis;
    }
};
int main(){
 
return 0;
}