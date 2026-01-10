/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        queue<pair<TreeNode*,unsigned long long>> q; // Use long long to prevent overflow
        q.push({root, 0});
        
        int maxwidth = 0;
        
        while (!q.empty()) {
            unsigned long long first = q.front().second;
            unsigned  long long last = q.back().second;
            maxwidth = max(maxwidth, (int)(last - first + 1));
            
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                
                TreeNode* node = temp.first;
                unsigned  long long idx = temp.second;
                
                if (node->left != NULL) {
                    q.push({node->left, idx * 2 + 1});
                }
                
                if (node->right != NULL) {
                    q.push({node->right, idx * 2 + 2});
                }
            }
        }
        
        return maxwidth;
    }
};