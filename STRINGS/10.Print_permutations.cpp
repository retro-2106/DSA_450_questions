#include <bits/stdc++.h>
using namespace std;

void permute(string a, int l, int r) 
{ 
    if (l == r) 
        cout<<a<<" "; 
    else
    { 
        for (int i = l; i <= r; i++) 
        { 

            swap(a[l], a[i]); 
  
            permute(a, l+1, r); 

            swap(a[l], a[i]); 
        } 
    } 
} 
int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    string input;
	    cin>>input;
	    
	    permute(input,0,input.size()-1);
	    cout<<endl;
	}
	return 0;
}
