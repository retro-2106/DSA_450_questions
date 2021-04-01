#inlcude<bits/stdc++.h>

using namespace std;

char flip(char ch)
{
	return ((ch == '0')? '1' : '0');
}

int getflip(string str,char expected)
{
	int count=0;

	for(int i=0;i<str.length();i++)
	{
		if(str[i] != expected)
			count++;

		expected = flip(expected);
	}

	return count;
}

int minflip(string str)
{
	return min(getflip(str,'0'),,getflip(str,'1'));

}