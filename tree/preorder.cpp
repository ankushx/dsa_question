class Solution {
public:
    
    void helper(TreeNode* root, vector<int> &ans)
    {
        if(root!=NULL)
           // return 0;
        {   ans.push_back(root->val);
        helper(root->left,ans);
        helper(root->right,ans);
        }
    }
 
    vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
      helper(root,ans);
        return ans;
    }
};

*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
     vector<int> ans;
        if(root==NULL )
            return ans;
        stack<TreeNode*> st;
        TreeNode*curr=root;
        st.push(curr);
        while(!st.empty())
        {
            curr=st.top();
            st.pop();
            ans.push_back(curr->val);
            if(curr->right)
                st.push(curr->right);
             if(curr->left)
                st.push(curr->left);
        }
        return ans;
    }
};
