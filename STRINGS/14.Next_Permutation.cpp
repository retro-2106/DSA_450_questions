class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        int i = arr.size() - 2;
        
        while(i >= 0 && arr[i+1] <= arr[i])
        i--;
        
        if(i >= 0)
        {
            int j = arr.size() - 1;
            while(j >=0 && arr[i] >= arr[j])
            j--;
            
            swap(arr[i],arr[j]);
        }
        
        reverse(arr.begin()+i+1,arr.end());
        
        return arr;
    }
};
