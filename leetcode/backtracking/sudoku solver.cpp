#include <bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<char>>& board,char k,int i,int j){
        for(int a=0;a<9;a++){
            if(board[i][a]==k+'0'){
                return false;
            }
            if(board[a][j]==k+'0'){
                return false;
            }
            if(board[3*(i/3)+a/3][3*(j/3)+a%3]==k+'0'){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(issafe(board,k,i,j)){
                            board[i][j]=k+'0';
                            bool a=solve(board);
                            if(a==true){
                                return true;
                            }
                            else
                            board[i][j]='.';
                            
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
int main(){
    vector<vector<char>> board;
    // give values to the board
  bool a=solve(board);
        return ;
return 0;
}