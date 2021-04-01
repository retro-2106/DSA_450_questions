
int findindex(string str,int si,int ei)
{
	if(si > ei)
		return -1;

	stack<char> s;
	for(int i=si;i<=ei;i++)
	{
		if(str[i] == '(')
		{
			s.push(str[i]);
		}
		else if(str[i] ==')')
		{
			if(s.top() == '(')
			{
				s.pop();

				if(s.empty())
					return i;
			}
		}
	}

	return -1;
}

Node *treefromString(string str,itn si,int ei)
{
	if(si > ei)
		return NULL;

	Node *root = newNode(str[si]-'0');
	int index = -1;

	if(si+1 <= ei && str[si+1] == '(')
		index = findindex(str,si+1,ei);

	if(index != -1)
	{
		root->left = treefromString(str,si+2,index-1);
		root->right = treefromString(str,index+2,ei-1);
	}
	return root;
}