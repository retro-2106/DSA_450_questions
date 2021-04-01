bool shuffle(string str1,string str2,string ans)
{
	if(str1.length()+str2.length() != ans.length())
		return false;

	int i=0,j=0,k=0;

	while(k != ans.length())
	{
		if(i < str1.length() && ans[k] == str1[i])
			i++;
		else if(j < str2.length() && ans[k] == str2[j])
			j++;
		else
			return false;

		k++;
	}

	if(i < str1.length() || j < str2.length())
		return false;

	return true;
}