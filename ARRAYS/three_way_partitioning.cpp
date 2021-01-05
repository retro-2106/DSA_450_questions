vector<int> threeWayPartition(vector<int> A, int a, int b)
{
     int i=0,j=i,k=A.size()-1;
     
     while(j <= k)
     {
         if(A[j] < a)
         {
             swap(A[i++],A[j++]);
         }
         else if(A[j] > b)
         {
             swap(A[j],A[k--]);
         }
         else
         {
             j++;
         }
     }
     return A;
}