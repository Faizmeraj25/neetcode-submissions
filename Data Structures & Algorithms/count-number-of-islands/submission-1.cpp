class Solution {
public:
    vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 
    // Using Breadth First Search.   
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;  
    }
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        queue<vector<int>> qu; 
        qu.push({row, col}); 
        while(!qu.empty()) {
            
            int x = qu.front()[0]; 
            int y = qu.front()[1]; 
            visited[x][y] = true; 
            qu.pop(); 
            for(int i = 0; i < 4; i++) {
                int newX = x + dir[i][0]; 
                int newY = y + dir[i][1]; 
                if(isValid(newX, newY, grid.size(), grid[0].size()) && !visited[newX][newY] && grid[newX][newY] == '1') {
                    qu.push({newX, newY}); 
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        int num_islands = 0; 
        for(int i = 0;i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    bfs(i, j, grid, visited); 
                    num_islands++; 
                }
            }
        }
        return num_islands; 
    }
};
