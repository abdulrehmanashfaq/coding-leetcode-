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
    int ans = 0;
    int height(TreeNode *root){

        if(root == NULL ){
            return 0 ;
        }

        int a = height(root->left);
        int b = height(root->right);

       if(a+b > ans){
        ans = a+b; 
       }
       return max(a,b)+1;



    }
    int diameterOfBinaryTree(TreeNode* root) {

        height(root);
        return ans ;
       
        


        
    }
};