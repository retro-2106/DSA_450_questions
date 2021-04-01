#define HeapNode pair<int,pair<int,int>> 
#define row hr.second.first
#define col hr.second.second
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // pair<int,pair<int,int>> HeapNode;
  priority_queue<HeapNode,vector<HeapNode>,
  greater<pair<int,pair<int,int>>>> pq;
  
  if(k <= 0 || k > n*n)
  return INT_MAX;
  
  for(int j=0;j<n;j++)
  {
      pq.push(make_pair(mat[0][j],make_pair(0,j)));
  }
  
  HeapNode hr;
  
  for(int i=0;i<k;i++)
  {
      hr = pq.top();
      int next = (row < n-1)?mat[row+1][col]:INT_MAX;
      
      HeapNode t;
      t.first = next;
      t.second.first = row+1;
      t.second.second = col;
      
      pq.pop();
      pq.push(t);
  }
  return hr.first;
}