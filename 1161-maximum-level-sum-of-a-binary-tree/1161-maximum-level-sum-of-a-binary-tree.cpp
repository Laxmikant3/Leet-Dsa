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
        if (!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int max=INT_MIN;
        int lev=1;
        int clev=1;

        while(!q.empty()){
            int s=q.size();
            int csum=0;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                csum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            if(csum>max){
                max=csum;
                lev=clev;
            }
            clev++;

        }
        return lev;
    }
};