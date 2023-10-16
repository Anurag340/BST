
    bool inorder(TreeNode* root,long min ,long max){
        if(root==NULL)return true;

        if(root->val>min && root->val<max){
            bool left=inorder(root->left,min,root->val);
            bool right=inorder(root->right,root->val,max);

            return (left && right);

        }
        else{
            return false;
        }

        

    }

    bool isValidBST(TreeNode* root) {
       return inorder(root,LONG_MIN, LONG_MAX);
        
    }