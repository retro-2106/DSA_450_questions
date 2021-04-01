#include<bits/stdc++.h>

using namespace std;


vector<int> getlps(string pattern)
{
	vector<int> lps(pattern.length(),0);

	int i=1;
	int j=0;

	while(i < pattern.length())
	{
		if(pattern[i] == pattern[j])
		{
		    lps[i] = j+1;
			i++;
			j++;
		}
		else
		{
			if(j != 0)
			{
				j = lps[j-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps;
}


void kmp(string text,string pattern)
{
	int n = text.size();
	int m = pattern.size();

	vector<int> lps = getlps(pattern);

	int i=0;
	int j=0;

	while(i < n)
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j != 0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}

		if(j == m)
		{
			cout<<"pattern found at: "<<i-j<<endl;
			j = lps[j-1];
		}
	}
}

int main()
{
	string text = "AAAAABAAAAA";
	string pattern = "AAAA";

	kmp(text, pattern);
}