class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_set <char> st;
        int count =0;
        for(int i =0;i+2<s.size();i++)
        {
            for(int j = i;j<=i+2;j++)  st.insert(s[j]);
            if(st.size() == 3) count++;
            st.clear();
        }
        return count;
    }
};