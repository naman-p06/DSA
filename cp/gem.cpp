#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    map<pair<int,int>,bool> m;
    vector<vector<int>> v;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    int count=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            
            if(v[i][j]==1 &&!m[make_pair(i,j)]){
                if(i+1<2 && v[i+1][j]==1 &&!m[make_pair(i+1,j)]){
                    count++;
                    m[make_pair(i,j)]=true;
                    m[make_pair(i+1,j)]=true;
                }
                else if(j+1<n && v[i][j+1]==1  &&!m[make_pair(i,j+1)]){
                    count++;
                m[make_pair(i,j)]=true;
                m[make_pair(i,j+1)]=true;
                }
                else if(i-1>=0&& v[i-1][j]==0 &&!m[make_pair(i-1,j)]){
                    count++;
                    m[make_pair(i,j)]=true;
                    m[make_pair(i-1,j)]=true;
                }
                else if(j-1>=0 && v[i][j-1]==0 &&!m[make_pair(i,j-1)]){
                    count++;
                    m[make_pair(i,j)]=true;
                    m[make_pair(i,j-1)]=true;
                }
                else if(i+1<2 &&v[i+1][j]==0 &&!m[make_pair(i,j)] &&!m[make_pair(i+1,j)]){
                count++;
                m[make_pair(i,j)]=true;
                m[make_pair(i+1,j)]=true;
                }
                else if(j+1<n&&v[i][j+1]==0 &&!m[make_pair(i,j)] &&!m[make_pair(i,j+1)]){
                count++;
                m[make_pair(i,j)]=true;
                m[make_pair(i,j+1)]=true;
                }
            }
        }
    }
    cout<<count<<endl;
}
return 0;
}