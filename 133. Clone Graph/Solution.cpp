/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    // Maps the original node to its cloned counterpart
    unordered_map<Node*, Node*> cloned;

public:
    Node* cloneGraph(Node* node) {
        // Base case: If the input node is null, return null
        if (node == nullptr) {
            return nullptr;
        }
        
        // If the node was already cloned, return the cloned reference (handles cycles)
        if (cloned.find(node) != cloned.end()) {
            return cloned[node];
        }
        
        // Create a new clone for the current node
        Node* newNode = new Node(node->val);
        cloned[node] = newNode;
        
        // Iterate through all neighbors of the original node
        for (Node* neighbor : node->neighbors) {
            // Recursively clone neighbors and add them to the new node's neighbor list
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return newNode;
    }
};