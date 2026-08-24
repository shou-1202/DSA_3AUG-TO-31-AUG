class Solution {
    vector<int> parent;

    // Standard Union-Find with path compression
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // Stores the index of the edge that points to a specific node
        vector<int> indegree(n + 1, -1); 
        
        int cand1 = -1; // First edge that gives a node two parents
        int cand2 = -1; // Second edge that gives a node two parents

        // Step 1: Find if any node has two parents
        for (int i = 0; i < n; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if (indegree[v] != -1) {
                cand1 = indegree[v];
                cand2 = i;
                break; // A node can have at most 2 parents in this problem
            } else {
                indegree[v] = i;
            }
        }

        // Initialize Union-Find array
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        // Step 2: Build the tree using Union-Find to detect cycles
        for (int i = 0; i < n; ++i) {
            // CRUCIAL: If we found a node with two parents, we temporarily IGNORE 
            // the second edge (cand2) to see if the graph is valid without it.
            if (i == cand2) continue;
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            int rootU = find(u);
            int rootV = find(v);
            
            if (rootU == rootV) {
                // CYCLE DETECTED!
                if (cand1 == -1) {
                    // Case 1: No node had two parents. It's just a cycle of nodes 
                    // with in-degree 1. The edge that closed the cycle is the culprit.
                    return edges[i];
                } else {
                    // Case 2: A node had two parents AND a cycle exists.
                    // Since we ignored cand2, and a cycle STILL exists, cand2 is innocent.
                    // The other edge pointing to that node (cand1) must be part of the cycle.
                    return edges[cand1];
                }
            }
            
            // Union: Child points to the parent's root
            parent[rootV] = rootU;
        }

        // Case 3: We finished checking, and NO cycle was found.
        // This means ignoring cand2 fixed the graph, so cand2 is the redundant edge.
        return edges[cand2];
    }
};