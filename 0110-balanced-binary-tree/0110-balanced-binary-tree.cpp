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
    int height(TreeNode *root){
        if (root == NULL ){
            return 0;
        }

        int a = height(root->left);
        if (a == -1){
            return -1;
        }
        int b =height(root->right);
        if ( b == -1 ){
            return -1; 
        }

        if ( abs(a-b) > 1 ){ return -1;}
        return max(a,b)+1;


    }
    
    bool isBalanced(TreeNode* root) {

        if (height(root)!=-1)
            {
                return true;
            }
            return false;



        
    }
};