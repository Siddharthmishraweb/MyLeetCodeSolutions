class Solution {
public:
void dfs(int i,int j,vector<vector<int>> &grid,int n,int m){
        if (i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
            return;
        }

        grid[i][j]=0;

        dfs(i+1,j,grid,n,m);
        dfs(i-1,j,grid,n,m);
        dfs(i,j+1,grid,n,m);
        dfs(i,j-1,grid,n,m);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int i,j;

        for (i=0; i<n; i++){
            if (grid[i][0]==1){
                dfs(i,0,grid,n,m);
            }
        }

        for (i=0; i<n; i++){
            if (grid[i][m-1]==1){
                dfs(i,m-1,grid,n,m);
            }
        }

        for (i=0; i<m; i++){
            if (grid[n-1][i]==1){
                dfs(n-1,i,grid,n,m);
            }
        }

        for (i=0; i<m; i++){
            if (grid[0][i]==1){
                dfs(0,i,grid,n,m);
            }
        }
        
        int ans=0;
        
        for (i=0; i<n; i++){
            for (j=0; j<m; j++){
                if (grid[i][j]==1){
                    ans++;
                }
            }
        }

     return ans;
    }
};