class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;  
    }
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if(row >= grid.size() || col >= grid[0].size())
            return; 

        visited[row][col] = true; 

        for(int i = 0;i < 4; i++) {
            int nextX = row + dir[i][0]; 
            int nextY = col + dir[i][1]; 
            if(isValid(nextX, nextY, grid.size(), grid[0].size()) && !visited[nextX][nextY] && grid[nextX][nextY] == '1') {
                dfs(nextX, nextY, grid, visited); 
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
                    dfs(i, j, grid, visited); 
                    num_islands++; 
                }
            }
        }
        return num_islands; 
    }
};
