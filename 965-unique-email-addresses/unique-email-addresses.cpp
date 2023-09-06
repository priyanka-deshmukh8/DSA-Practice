class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        for(auto i: emails){
            auto atpos = find(i.begin(),i.end(),'@');
            auto dotpos = remove(i.begin(),atpos,'.');
            auto plus = find(i.begin(),dotpos,'+');
            i.erase(plus,atpos);
            st.insert(i);
        }
        return st.size();
    }
};