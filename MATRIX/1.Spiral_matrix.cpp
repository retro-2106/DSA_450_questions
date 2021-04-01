#include<bits/stdc++.h>

using namespace std;

    
    vector<int> spirallyTraverse(vector<vector<int> > &matrix, int r, int c) 
    {
       int sr=0,sc=0,er=r,ec=c;
       vector<int> ans;
       while(sr < er && sc < ec)
       {
           for(int j=sc;j < ec;j++)
           {
               ans.push_back(matrix[sr][j]);
           }
           
           sr++;
           
           for(int i=sr;i < er;i++)
           {
               ans.push_back(matrix[i][ec-1]);
           }
           
           ec--;
           
           if(sr < er)
           {
           	for(int j=ec-1;j>=sc;j--)
           {
               ans.push_back(matrix[er-1][j]);
           }
           er--;
		   }
           
           if(sc < ec)
           {
           	for(int i=er-1;i >= sr;i--)
           {
               ans.push_back(matrix[i][sc]);
           }
           
           sc++;
		   }
           
       }
       
       return ans;
    }
int main()
{
  vector<vector<int>> matrix(10);
int k=1;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
        matrix[i].push_back(k++);
    }
  }

  vector<int> ans = spirallyTraverse(matrix,4,4);

  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }
}
