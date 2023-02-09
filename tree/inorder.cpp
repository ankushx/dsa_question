 class Solution {
public:
    void helper(TreeNode* root, vector<int> &ans)
    {
           if(root ==NULL)
            return ;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
        helper(root,ans);
        return ans;
    
    }
};
 
 
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr= root;
        while(true)
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                if(st.empty()==true)
                    break;
                curr=st.top();
                st.pop();
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
        
        
    }
};








