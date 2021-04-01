
#include<bits/stdc++.h>

using namespace std;
#define d 256

void kmp(char pat[],char txt[],int q)
{
	// q is prime number;

	int M = strlen(pat);
	int N = strlen(txt);

	int i,j;
	int p=0; // for hash of pattern
	int t = 0;// for hash of text

	int h = 1;// this will be used for left shift operation

	for(i=0;i< M-1;i++)
	{
		h = (h * d)%q;
	}

	//calculating hash for pattern and first window
	for(i=0;i<M;i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	for(i = 0;i <= N - M;i++)
	{
		if(p == t)
		{
			for(j=0;j < M;j++)
			{
				if(txt[i + j] != pat[j])
					break;
			}

			if(j == M)
			{
				cout<<"found at index: "<<i<<endl;
			}
		}

		if(i < N - M)
		{
			t = (d *(t - txt[i] * h) + txt[i + M]) % q;

			if(t < 0)
				t = t + q;
		}
	}
}


int main()
{

}