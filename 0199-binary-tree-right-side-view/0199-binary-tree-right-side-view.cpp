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
    vector<int> rightSideView(TreeNode* root) {


        
        TreeNode *p ;
        queue <TreeNode *> q ;
        q.push(root);
        vector<int>ans ;
        if(root == NULL){
            return ans ;
        }
        while ( !q.empty() ) {
        
        int level = q.size();

        for (int i =0 ; i < level ; i++){

            p = q.front();
            q.pop();

            if(i == level-1){
                ans.push_back(p->val);
            }

            if(p->left !=NULL){
                q.push(p->left);
            }
            if(p->right != NULL){
                q.push(p->right);
            }

        }
        
        
        }
        return ans;
        
    }
};