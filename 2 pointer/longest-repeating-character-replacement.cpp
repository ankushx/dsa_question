class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        int cnt=0;
        int ans=0;
        unordered_map<char,int> mp;
        while(j<n)
        {
                mp[s[j]]++;
                cnt=max(mp[s[j]],cnt);
            while((j-i+1)-cnt>k)
            {
                mp[s[i]]--;
               // cout<<" 2) "<<i<<" "<<j<<" "<<cnt<<" -"<<ans<<endl;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
