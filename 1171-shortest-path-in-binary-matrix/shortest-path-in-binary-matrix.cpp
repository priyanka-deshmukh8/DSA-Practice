class Solution {
public:

    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        if(!grid[0][0])
        q.push({0,0});
        int ans=2;
        grid[0][0]=2;
        while(q.size())
        {
            int sz=q.size();
            ans++;
            while(sz--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==(n-1)&&y==(n-1))
                    return (grid[x][y]-1);
                for(int i=0;i<8;i++)
                {
                    int x1=x+dir[i][0];
                    int y1=y+dir[i][1];
                    if(x1<0||y1<0||x1>=n||y1>=n||grid[x1][y1])
                        continue;
                    grid[x1][y1]=ans;
                    q.push({x1,y1});
                }
            }
        }
        return -1;
    }
};