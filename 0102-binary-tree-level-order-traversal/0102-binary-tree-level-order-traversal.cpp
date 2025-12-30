class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        // 1. Queue must store pointers, not just ints
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // 2. Get the number of nodes at the current level
            int levelSize = q.size();
            vector<int> currentLevel;

            // 3. Process exactly 'levelSize' nodes
            for (int i = 0; i < levelSize; i++) {
                TreeNode* p = q.front();
                q.pop();

                currentLevel.push_back(p->val);

                // 4. Push children of the current node for the NEXT level
                if (p->left != nullptr) q.push(p->left);
                if (p->right != nullptr) q.push(p->right);
            }

            // 5. Add the finished level to our result
            res.push_back(currentLevel);
        }

        return res;
    }
};