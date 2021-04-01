void commonelements(int mat[M][N])
{
	unordered_map<int,int>  mapp;

	for(int j=0;j<N;i++)
	{
		mapp[mat[0][j]] = 1;
	}

	for(int i=1;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(mapp[mat[i][j]] == i)
			{
				mapp[mat[i][j]]++;

				if(i == M-1)
				{
					cout<<mat[i][j];
				}
			}
		}
	}
}