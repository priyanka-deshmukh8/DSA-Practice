class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1) return 1;
        unordered_map<char,int>mp;
        int i =0,j=0,n= s.size();
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()==j-i+1)
            {
                ans = max(ans,j-i+1);
            }
            else{
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};