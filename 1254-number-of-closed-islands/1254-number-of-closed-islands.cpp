class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        bool edge = false;
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    edge = false;
                    dfs(grid, i, j, edge);
                    if(edge == false) count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, bool& edge){
        grid[i][j] = 1;
        if(i == grid.size() - 1 || i == 0 || j == grid[0].size() - 1 || j == 0) edge = true;
        if(i != grid.size() - 1 && grid[i+1][j] == 0) dfs(grid, i + 1, j, edge);
        if(i != 0 && grid[i-1][j] == 0) dfs(grid, i - 1, j, edge);
        if(j != grid[0].size() - 1 && grid[i][j+1] == 0) dfs(grid, i, j + 1, edge);
        if(j != 0 && grid[i][j-1] == 0) dfs(grid, i, j - 1, edge);
        return;
    }
};