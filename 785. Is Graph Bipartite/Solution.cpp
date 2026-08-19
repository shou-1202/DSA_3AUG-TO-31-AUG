class Solution {
public:
    bool helper(vector<vector<int>>& graph, vector<int>& color, queue<int>& q, int start){
        color[start] = 0;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neigh: graph[node]){
                if(color[neigh] == -1){
                    color[neigh] = !color[node];
                    q.push(neigh);
                }
                else if(color[neigh] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        queue<int>q;
        for(int i =0; i<n; i++){
            if(color[i]==-1){
                if(!helper(graph, color, q, i)){
                    return false;
                }
            }
        }
        return true;
    }
};