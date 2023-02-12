/*
class Solution {
public:
    int maxi=0;
    int hgt(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l=hgt(root->left);
        int r=hgt(root->right);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
         if(root==NULL)
            return 0;
        int lt=hgt(root->left);
        int rt=hgt(root->right);
        maxi=max(maxi,lt+rt);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;
    }
};

*/

class Solution {
public:
    int hgt(TreeNode* root,int& maxi)
    {
        if(root==NULL)
            return 0;
        int l=hgt(root->left,maxi);
        int r=hgt(root->right,maxi);
        maxi=max(maxi,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        hgt(root,maxi);
        return maxi;
    }
};
