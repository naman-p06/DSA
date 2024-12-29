#include <bits/stdc++.h>
using namespace std;
class compare{
    public:
    bool operator()( pair<int,int> &p1,pair<int,int> &p2){
        return p1.first>p2.first;
    }
};
class Solution {
  public:
    
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
           int v=adj.size();
           vector<int> dis(v,INT_MAX);
           priority_queue<pair<int,int>,vector<pair<int,int>>,compare> p;
           dis[src]=0;
           p.push(make_pair(0,src));
           while(!p.empty()){
               pair<int,int> c=p.top();
               p.pop();
               for(auto j:adj[c.second]){
                   if(dis[j.first]>c.first+j.second){
                       dis[j.first]=c.first+j.second;
                       p.push({dis[j.first],j.first});
                   }
               }
           }
           for (int i = 0; i < v; i++){ 
               if (dis[i] == INT_MAX){
               dis[i] = -1; 
               
           } 
               
           }
           return dis;
    }
};
int main(){
 
return 0;
}