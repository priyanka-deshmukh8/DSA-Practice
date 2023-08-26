class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m =-1;
        int n = accounts.size();
        for(int i =0;i<n;i++)
        {
            int s =0;
            for(int j =0;j<accounts[i].size();j++)
            {
                s+= accounts[i][j];
            }
            if(s>m){
                m=s;
            }
        }
        return m;
    }
};