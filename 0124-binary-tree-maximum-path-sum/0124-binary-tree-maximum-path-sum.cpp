class Solution {
public:
    
    int maxSum = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) return 0;

        int leftGain = max(helper(root->left), 0);
        int rightGain = max(helper(root->right), 0);

        
        int currentPathSum = root->val + leftGain + rightGain;

        
        maxSum = max(maxSum, currentPathSum);

        
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};