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
public:
    // This map acts as our "Database" to store cloned nodes
    unordered_map<Node*, Node*> copies;

    Node* cloneGraph(Node* node) {
        // Step 1: Handle the null case
        if (!node) return nullptr;

        // Step 2: Check if we have already cloned this node
        if (copies.find(node) == copies.end()) {
            // Create a new instance (Blueprint to Object)
            copies[node] = new Node(node->val);
            
            // Step 3: Recursively clone all neighbors
            for (Node* neighbor : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        
        // Return the clone of the current node
        return copies[node];
    }
};