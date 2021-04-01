#include<bits/stdc++.h>

using namespace std;

void diagonal_helper(Node *root,int d,map<<vector<int>> &diagonal)
{
	if(!root)
	return;
	diagonal[d].push_back(root->data);

	diagonal_helper(root-left,d+1,diagonal);
	diagonal_helper(root->right,d,diagonal);
}

void diagonal_traversal(Node *root)
{
	if(!root)
		return;

	map<int,vector<int>> diagonal;

	diagonal_helper(root,0,diagonal);

	for(auto it:diagonal)
	{
		vector<int> v = it.second;
		for(auto a : v)
		{
			cout<<a<<" ";
		}
		cout<<endl;
	}
}