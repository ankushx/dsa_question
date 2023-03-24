int helper(int idx,int prev,vector<vector<int>> &points,vector<vector<int>>& dp)
{
    if(idx<0)
    return 0;
    if(idx==0)
    {
       if(prev==0)
       return max(points[0][1],points[0][2]);
       else if(prev==1)
       return max(points[0][0],points[0][2]); 
       else
       return max(points[0][1],points[0][0]);
    }
    if(dp[idx][prev]!=-1)
    return dp[idx][prev];
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        int all_path=0;
        if(prev!=i)
         all_path=points[idx][i]+helper(idx-1,  i, points,dp);
        maxi=max(maxi,all_path);
    }
    return dp[idx][prev]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int> (4,-1));
    return helper(n-1,3,points,dp);
    // Write your code here.
}
