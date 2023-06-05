class Solution {
public:
    void dfs(int vertex, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[vertex]) return;
        visited[vertex] = 1;
        for(auto &child: adj[vertex]){
            dfs(child,adj,visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n, vector<int> (n));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] && i!=j) adj[i].push_back(j);
            }
        }
        vector<bool> visited(n,0);
        int ct = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                ct++;
            }
        }
        return ct;
    }
};