class Solution {
public:
    const int mod=1e9+7;
    int row;
    int col;
    int dir1[4]={-1,1,0,0};
    int dir2[4]={0,0,-1,1};
    int dp[1005][1005];
    int helper(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j)
    {
        if(dp[i][j]!=-1)
        return dp[i][j];
        vis[i][j]=true;
        long long ans=1;
        for(int x=0;x<4;x++)
        {
            int u=dir1[x]+i,v=dir2[x]+j;
            if(u<0 || v<0 || u>=row || v>=col || vis[u][v]|| grid[u][v]<=grid[i][j])continue;
            ans=(ans+helper(grid,vis,u,v))%mod;
            
        }
        vis[i][j]=false;
        return dp[i][j]=(int)ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        memset(dp,-1,sizeof(dp));
        long long ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans=(ans+helper(grid,vis,i,j))%mod;
            }
        }
        return (int)ans;
    }
};