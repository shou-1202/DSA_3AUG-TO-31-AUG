class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>>adj[n+1];

        for(int i = 0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int, int>> pq;
        
        pq.push({k, 0});
        vector<int>vis(n+1, 1e9);
        vis[0] = 0;
        vis[k] = 0;
        while(!pq.empty()){
            int u = pq.front().first;
            int time = pq.front().second;
            pq.pop();
            
            for(auto neigh: adj[u]){
                if(vis[neigh.first] > time+neigh.second){
                    vis[neigh.first] = time+neigh.second;
                    pq.push({neigh.first, time+neigh.second});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i<n+1; i++){
            if(vis[i]==1e9)return -1;
            ans = max(vis[i], ans);
        }
        return ans;
    }
};