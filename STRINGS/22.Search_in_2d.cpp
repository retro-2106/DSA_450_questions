#include <bits/stdc++.h>

using namespace std;

char mat[101][101];

//directions
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 

bool search(char mat[101][101],int r,int c,string key,int i,int j)
{
    if(mat[i][j] != key[0])
    {
        return false;
    }
    
    int n = key.length();
    
    for(int dir = 0;dir < 8;dir++)
    {
        int row = i + x[dir];
        int col = j + y[dir];
        
        int k=0;
        for(k=1;k < n;k++)
        {
            //checking that it is not out of bound
        if(row < 0 || row >= r|| col < 0|| col >= c)
        break;
        
        if(mat[row][col] != key[k])
        {
            break;
        }
        //we are doing this to fix a particular direction
        //as the word is valid if it is completely in any of 8 directions
        //if word is staring in horizontal then 
        //we cannot go to other direction
        row = row + x[dir];
        col = col + y[dir];
    }
    if(k == n)
        {
            return true;
        }
    }
    return false;
}
int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    int r,c;
	    cin>>r>>c;
	    
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin>>mat[i][j];
	        }
	    }
	    
	    string key;
	    cin>>key;
	    
	    //arguments
	    //matrix,row,column,key,curr_row,curr_col
	    bool flag =true;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            if(search(mat,r,c,key,i,j))
	            {
	                cout<<i<<" "<<j<<", ";
	                flag = false;
	            }
	        }
	    }
	    if(flag)
	    cout<<"-1";
	    cout<<endl;
	    
	}
	return 0;
}