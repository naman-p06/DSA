#include <bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<int>>&board,int i,int j,int n){
    int x=i;
    int y=j;
    while(y>=0){
        if(board[x][y]==1){
        return false;}
        y--;
    }
    x=i;
    y=j;
    while (x>=0 && y>=0)
    {
       if(board[x][y]==1){
        return false;}
        x--;
        y--;
    }
    x=i;
    y=j;
    while (x<n && y>=0)
    {
       if(board[x][y]==1){
        return false;}
        x++;
        y--;
    }
    return true;
}
void solve(vector<vector<int>>&board,vector<vector<vector<int>>>& ans,int n,int col){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(issafe(board,i,col,n)){
            board[i][col]=1;
            solve(board,ans,n,col+1);
            board[i][col]=0;
        }
    }
    return;
}
int main(){
 int n;
 cin>>n;
 vector<vector<int>>board(n,vector<int>(n,0));
 vector<vector<vector<int>>> ans;
 solve(board,ans,n,0);
 int h=ans.size();
 for(int i=0;i<h;i++){
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            cout<< ans[i][j][k]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
 }
return 0;
}