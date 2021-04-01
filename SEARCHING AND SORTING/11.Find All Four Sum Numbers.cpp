vector<vector<int> > fourSum(vector<int> &arr, int k) 
{
    map<int,pair<int,int>> mapp;
    int n = arr.size();
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j < n;j++)
        {
            mapp[arr[i] + arr[j]] = {i,j};
        }
    }
    
    vector<vector<int>> ans;
    
    vector<bool> visited(n,0);
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum = arr[i] + arr[j];
            if(mapp.find(k - sum) != mapp.end())
            {
                pair<int,int> p = mapp[k - sum];
                
                if(p.first != i && p.second != i
                && p.first != j && p.second != j
                && visited[i] == 0 &&visited[j] ==0
                && visited[p.first] ==0 && visited[p.second]==0 )
                {
                    vector<int> a;
                    a.push_back(arr[i]);
                    a.push_back(arr[j]);
                    a.push_back(arr[p.first]);
                    a.push_back(arr[p.second]);
                    
                    ans.push_back(a);
                    visited[i] = 1;
                    visited[j] = 1;
                    //visited[p.first] = 1;
                    visited[p.second] = 1;
                    break;vector<vector<int>> fourSum(vector<int> &a, int k) {
    if (a.size() < 4) return {};
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 3; ++i) {
        if (a[i] > 0 && a[i] > k) break;

        if (i > 0 && a[i] == a[i - 1]) continue;
        for (int j = i + 1; j < a.size() - 2; ++j) {

            if (j > i + 1 && a[j] == a[j - 1]) continue;

            int left = j + 1;
            int right = a.size() - 1;
            while (left < right) {
                int old_l = left;
                int old_r = right;

                int sum = a[i] + a[j] + a[left] + a[right];
                if (sum == k) {

                    ans.push_back({a[i], a[j], a[left], a[right]});

                    while (left < right && a[left] == a[old_l]) left++;
                    while (left < right && a[right] == a[old_r]) right--;
                } else if (sum > k) {
                    right--;
                } else {
                    left++;
                }
            }
        }
    }
    return ans;
}
                }
            }
        }
        
    }
    return ans;
}


///////////////////////////////////////////////////////
