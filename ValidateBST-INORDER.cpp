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

    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL)return;

        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);

    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);

        bool ans=true;
        int min=v[0];
        int i=0;
        while(i<v.size()){
            for(int j=i+1;j<v.size();j++){
                if(v[j]<=v[i])ans=false;
            }
            i++;
        }
        

        if(ans)return true;
        else return false;
        
    }
};