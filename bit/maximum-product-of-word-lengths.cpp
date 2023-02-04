class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=words.size();
        vector<int> bits(n,0);
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(auto it:words[i])
                bits[i]=bits[i]|(1<<(it-'a'));
            for(int j=0;j<i;j++)
            {
                if((bits[i]&bits[j])==0)
                {
                    temp=words[i].size()*words[j].size();
                    ans=max(temp,ans);
                }  
            }
        }
        return ans;
    }
};
