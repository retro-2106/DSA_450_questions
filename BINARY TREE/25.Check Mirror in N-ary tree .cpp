#include <bits/stdc++.h>
using namespace std;

bool helper(vector<stack<int> >& tree1,
                      vector<queue<int> >& tree2)
{
    for (int i = 1; i < tree1.size(); ++i) {
        stack<int>& s = tree1[i];
        queue<int>& q = tree2[i];

        while (!s.empty() && !q.empty()) {

            if (s.top() != q.front())
                return false;
 
            s.pop();
            q.pop();
        }

        if (!s.empty() || !q.empty())
            return false;
    }
 
    return true;
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,e;
	    cin>>n>>e;
	    
	    vector<stack<int> > tree1(n + 1);
    vector<queue<int> > tree2(n + 1);
 
    for (int i = 0; i < e; i++) 
    {
        int a,b;
        cin>>a>>b;
        tree1[a].push(b);
    }
            

    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        tree2[a].push(b);
    }
        
	    cout<<helper(tree1,tree2)<<endl;
	}
	return 0;
}