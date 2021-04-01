void find_duplicates(string s)
{
	unordered_map<char,int> mapp;

	for(int i=0;i< s.length();i++)
	{
		mapp[s[i]]++;
	}


	for(auto it = mapp.begin();it != mapp.end();it++)
	{
		if(it->second == 1)
			cout<<it->first<<" ";
	}

}