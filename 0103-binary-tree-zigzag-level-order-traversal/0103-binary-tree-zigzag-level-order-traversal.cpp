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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        deque<TreeNode*>q ;
        q.push_front(root);
        int i = 0 ;
        vector<vector<int>>result;
        
        if (root == NULL){
            return result ;
        }

        while ( !q.empty() ){
            vector<int>vec; 
            if (i%2 == 0){
                int size = q.size();
                for (int j=0 ;j<size;j++){
                TreeNode *front = q.front();
                vec.push_back(front->val);
                q.pop_front();    
                if(front->left!=NULL)q.push_back(front->left);
                if(front->right!=NULL)q.push_back(front->right);
                }


            }
            else{
                int size = q.size();
                for ( int j =0 ;j<size;j++){ 
                    
                    TreeNode *back = q.back();
                    vec.push_back(back->val);
                    q.pop_back();

                    if (back->right !=NULL)q.push_front(back->right);
                    if (back->left !=NULL)q.push_front(back->left);

                   

                }


        }



            result.push_back(vec);  
            i++;


        }
        return result;
        
    }
};