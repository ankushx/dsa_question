class Solution {
public:
    vector<vector<string>> ans;
    bool is_palindrome(string s,int st,int e)
    {
        while(st<=e)
        {
            if(s[st++]!=s[e--])
                return 0;
        }
        return 1;
    }
 void solver(string s,vector<string> output,int idx)
 {
     if(idx==s.size())
     {
         ans.push_back(output);
     }
     for(int i=idx;i<s.size();i++)
     {
         if(is_palindrome(s,idx,i))
        { output.push_back(s.substr(idx,i-idx+1));
         solver(s,output,i+1);
         output.pop_back();}
     }
 }
    vector<vector<string>> partition(string s) {
        vector<string> output;
          solver(s,output,0);
        return ans;
    }
};
