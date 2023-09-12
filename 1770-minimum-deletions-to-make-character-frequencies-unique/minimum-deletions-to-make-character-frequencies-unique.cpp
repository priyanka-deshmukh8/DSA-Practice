class Solution {
public:
    int minDeletions(string k) {
        int freq[26] = {0};

        for(char &ch : k){
            freq[ch - 'a']++;

        }

        int result =0;
        unordered_set<int>s;

        for(int i =0;i<26;i++){
            while(freq[i]>0 && s.find(freq[i]) != s.end()){
                 freq[i] -= 1;
                 result++;
            }
            s.insert(freq[i]);
        }
        return result;
    }
};