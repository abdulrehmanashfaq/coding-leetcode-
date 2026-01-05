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

    vector<int>value;
    void inorder(TreeNode* root){

        if (root == NULL){
            return ;
        }

        inorder(root->left);
        value.push_back(root->val);
        inorder(root->right);
    }        
    int getMinimumDifference(TreeNode* root) {


        if(root == NULL){
            return INT_MAX;
        }
            inorder(root) ;
            int min = INT_MAX;
        for (int i=0 ;i<value.size() - 1;i++){

            int val = value[i+1] - value[i];
            if( min > val ){
                min = val ;
            }

        }

        return min ;

        
    }
};