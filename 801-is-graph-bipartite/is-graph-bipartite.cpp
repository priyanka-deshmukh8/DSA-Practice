class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n,-1);

        for(int i =0;i<n;++i)
        {
            if(color[i] == -1){
                if(helper(color,i,graph,0)==false)
                return false;
            }
        }
        return true;
    }
    bool helper(vector<int>& color,int m,vector<vector<int>>&graph,int n){
            color[m]= n;
            for(auto it:graph[m])
            {
                if(color[it]==-1)
                {
                    if(helper(color,it,graph,!n)== false) return false;
                }else if(color[it] == n){
                    return  false;
                }
            }
            return true;
    }
    
};

