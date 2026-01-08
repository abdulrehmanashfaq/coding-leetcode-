class Solution {
public:
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }

    TreeNode* fun(vector<int>& preorder, vector<int>& inorder, int& preind, int left, int right) {
        // Base case: if the range is invalid
        if (left > right) return NULL;

        // 1. Pick the current element from preorder using preind and increment it
        int currentVal = preorder[preind];
        TreeNode* root = new TreeNode(currentVal);
        preind++;

        // 2. Find the index of this element in Inorder
        int ind = search(inorder, left, right, currentVal);

        // 3. Elements to the left of 'ind' form the left subtree
        root->left = fun(preorder, inorder, preind, left, ind - 1);
        
        // 4. Elements to the right of 'ind' form the right subtree
        root->right = fun(preorder, inorder, preind, ind + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preind = 0;
        return fun(preorder, inorder, preind, 0, inorder.size() - 1);
    }
};