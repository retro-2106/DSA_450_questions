void printKMax(int arr[], int n, int k) 
{ 
    int j, max; 
  
    for (int i = 0; i <= n - k; i++) 
    { 
        max = arr[i]; 
  
        for (j = 1; j < k; j++) 
        { 
            if (arr[i + j] > max) 
                max = arr[i + j]; 
        } 
        cout << max << " "; 
    } 
} 
  
