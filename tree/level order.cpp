class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans;
    if(root ==NULL)
        return ans;
        queue<TreeNode*> st;
        st.push(root);
       
        while(!st.empty())
        {
            int n=st.size();
            vector<int> level;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=st.front();
                st.pop();
                level.push_back(curr->val);
                if(curr->left)
                    st.push(curr->left);
                if(curr->right)
                    st.push(curr->right);
               // cout<<curr->val<<" - ";
            }
          //  cout<<endl;
            ans.push_back(level);
           
        }
        return ans;
    }
};

//simple level order
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
    

         vector<int> ans;
    if(root ==NULL)
        return ans;
        queue<Node*> st;
        st.push(root);
       
        while(!st.empty())
        {
    
                Node* curr=st.front();
                st.pop();
                ans.push_back(curr->data);
                if(curr->left)
                    st.push(curr->left);
                if(curr->right)
                    st.push(curr->right);
               // cout<<curr->val<<" - ";
           
        }
        return ans;


      //Your code here
    }
};
