#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<char> >& grid, int n, int m,int xcor,int ycor, vector<vector<bool> >& visited){
    if(xcor<0 || ycor<0 || xcor>=n || ycor>=m || grid[xcor][ycor]=='#' || visited[xcor][ycor]==true){
        return ;
    }
    visited[xcor][ycor]=true;
    dfs(grid,n,m,xcor+1,ycor,visited);
    dfs(grid,n,m,xcor,ycor+1,visited);
    dfs(grid,n,m,xcor-1,ycor,visited);
    dfs(grid,n,m,xcor,ycor-1,visited);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> >grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<bool> >visited(n,vector<bool>(m,false));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && visited[i][j]==false){
                cnt++;
                dfs(grid,n,m,i,j,visited);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}