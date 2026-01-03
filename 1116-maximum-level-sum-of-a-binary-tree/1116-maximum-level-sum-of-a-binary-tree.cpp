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
    int maxLevelSum(TreeNode* root) {

        if (root == NULL ){
            return 0 ;
        }

        TreeNode *p = root ;
        queue<TreeNode*>q ;
        q.push(p);
        pair <int , int > result= { INT_MIN,1 } ;
        int sum = 0;
        int level = 1;

        while ( !q.empty() ){

            int size = q.size();
            sum = 0 ;
            
            for ( int i=0 ; i <size ; i++ ){

                p = q.front() ;

                sum += p->val ;
                q.pop();

                 if( p->left != NULL ){
                
                q.push( p->left ) ;
    
            }

            if( p->right != NULL ){
                
                q.push( p->right ) ;
    
            }


            }

                if ( sum > result.first ){
                    result.first = sum ;
                    result.second = level ;
                }

                level++ ;

                

        }


        return result.second ;

        
    }
};