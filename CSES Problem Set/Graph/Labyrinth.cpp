#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<char> > grid(n, vector<char>(m));  
    int startX = -1, startY = -1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                startX = i;
                startY = j;
            }
        }
    }
    
    // BFS
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    vector<vector<pair<int,int> > > parent(n, vector<pair<int,int> >(m, make_pair(-1, -1)));
    
    queue<pair<int,int> > q;
    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;
    
    // Direction arrays: Down, Up, Right, Left
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char dir[] = {'D', 'U', 'R', 'L'};
    
    bool found = false;
    int endX = -1, endY = -1;
    
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        
        // Found the target!
        if(grid[x][y] == 'B'){
            found = true;
            endX = x;
            endY = y;
            break;
        }
        
        // Explore all 4 directions
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && 
               !visited[nx][ny] && grid[nx][ny] != '#'){
                visited[nx][ny] = true;
                parent[nx][ny] = make_pair(x, y);
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    if(!found){
        cout << "NO" << endl;
        return 0;
    }
    
    // Reconstruct path
    string path = "";
    int cx = endX, cy = endY;
    
    while(!(cx == startX && cy == startY)){
        int px = parent[cx][cy].first;
        int py = parent[cx][cy].second;
        
        // Determine direction
        if(cx == px + 1) path += 'D';      // Moved down
        else if(cx == px - 1) path += 'U'; // Moved up
        else if(cy == py + 1) path += 'R'; // Moved right
        else if(cy == py - 1) path += 'L'; // Moved left
        
        cx = px;
        cy = py;
    }
    
    reverse(path.begin(), path.end());
    
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
    
    return 0;
}