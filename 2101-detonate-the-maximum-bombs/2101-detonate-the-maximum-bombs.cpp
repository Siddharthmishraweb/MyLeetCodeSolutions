class Solution {
private:
    int bfs(int u,vector<vector<int>> &adj){
        int n=adj.size();
        int temp=0;
        queue<int> q;
        vector<int> vis(n);
        q.push(u);
        vis[u]=1;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            temp++;
            for(auto it:adj[v]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return temp;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long x=bombs[i][0]-bombs[j][0];
                long long y=bombs[i][1]-bombs[j][1];
                long long d=(x*x+y*y);
                long long r1=bombs[i][2];
                long long r2=bombs[j][2];
                if(d<=r1*r1){
                    adj[i].push_back(j);
                }
                if(d<=r2*r2){
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,bfs(i,adj));
        }
        return ans;
    }
};