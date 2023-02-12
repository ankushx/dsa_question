//combination of height and maximum diameter problem
class Solution {
public:
    int cal_sum(TreeNode* root,int & ans)
    {
        if(root==NULL)
            return 0;
        int left_sum=max(0,cal_sum(root->left,ans));
        int right_sum=max(0,cal_sum(root->right,ans));
        ans=max(ans,root->val+(left_sum+right_sum));
        return root->val+max(left_sum,right_sum);
        
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        cal_sum(root,ans);
        return ans;
    }
};
