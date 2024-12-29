#include <bits/stdc++.h>
using namespace std;
//creating graph using adj list
class graph{
    public:
    map<int,list<int>> adj;

    void insert(int u,int v,bool dir){
        adj[u].push_back(v);
        if(dir==0){
            adj[v].push_back(u);
        }
    }
    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

};
int main(){
 graph g;
 int n;
 cout<<"enter no of nodes"<<endl;
 cin>>n;
 int m;
 cout<<"enter no of edges"<<endl;
 cin>>m;
 for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    g.insert(u,v,0);
 }
g.print();
return 0;
}