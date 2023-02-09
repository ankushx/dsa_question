class Solution {
public:
     void helper(TreeNode* root, vector<int> &ans)
    {
           if(root==NULL)
            return ;
        helper(root->left,ans);
         helper(root->right,ans);
        ans.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        helper(root,ans);
        return ans;
    }
};

*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> st1;
        st1.push(root);
          stack<TreeNode*> st2;
        TreeNode* curr=root;
        while(!st1.empty())
        {
            curr=st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left)
                st1.push(curr->left);
             if(curr->right)
                st1.push(curr->right);
        }
        while(!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
            
        }
        return ans;
    }
};
