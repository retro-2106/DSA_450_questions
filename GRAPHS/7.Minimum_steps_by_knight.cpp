class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
    {
        int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
        
        queue<pair<int,pair<int,int>>> q;
        
        q.push(make_pair(KnightPos[0],make_pair(KnightPos[1],0)));
        
        pair<int,pair<int,int>> t;
        int x,y;
        bool visited[N+1][N+1];
        
        memset(visited,0,sizeof(visited));
        
        visited[KnightPos[0]][KnightPos[1]] = true;
        
        while(!q.empty())
        {
            t = q.front();
            
            q.pop();
            
            if(t.first == TargetPos[0] && t.second.first == TargetPos[1])
            return t.second.second;
            
            for(int i=0;i<8;i++)
            {
                x = t.first + dx[i];
                y = t.second.first + dy[i];
                
                if(x >= 1 && x <= N && y >= 1 && y <= N && !visited[x][y])
                {
                    visited[x][y] = 1;
                    q.push(make_pair(x,make_pair(y,t.second.second + 1)));
                }
            }
        }
    }
};
