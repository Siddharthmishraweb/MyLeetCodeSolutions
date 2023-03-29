class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> pendingNodes;
        int fresh = 0, time = 0, rotten = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) {
                    pendingNodes.push({i,j});
                    fresh++;
                }
            }
        }
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            rotten += size;
            //level wise
            for(int i = 0 ; i < size; i++){
                int x = pendingNodes.front().first,y= pendingNodes.front().second;
                pendingNodes.pop();
                //for four direction
                //x+1,y
                if(x+1 < grid.size() && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    pendingNodes.push({x+1,y});
                }
                //x,y+1
                if(y+1 < grid[0].size() && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    pendingNodes.push({x,y+1});
                }
                //x-1 ,y
                if(x-1 >= 0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    pendingNodes.push({x-1,y});
                }
                //x ,y - 1
                if(y-1 >= 0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    pendingNodes.push({x,y-1});
                }
            }
            if(pendingNodes.size() != 0) time++;
        }
        if(fresh > rotten) return -1;
        return time;
    }
};