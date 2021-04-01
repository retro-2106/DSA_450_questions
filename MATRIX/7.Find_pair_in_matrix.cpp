int findapirs(int mat[][N])
{
	int matrix[N]{N};

	matrix[N-2][N-1] = mat[N-1][N-1];//as the value will remain same

	//filling the last row

	int max_value = INT_MIN;
	for(int j=N-2;j>=0;j--)
	{
		if(max_value > mat[N-1][j])
		{
			max_value = mat[N-1][j];
		}

		matrix = max_value;
	}

	//filling the last column
	for(int i=N-2;i>=0;i--)
	{
		if(max_value > mat[i][N-1])
		{
			max_value = mat[i][N-1];
		}

		matrix = max_value;
	}

	//filling the rest of the matrix

	for(int i=N-2;ii>=0;i--)
	{
		for(int j=N-2;j>=0;j--)
		{
			if(matrix[i+1][j+1] - mat[i][j] > max_value)
			{
				max_value = matrix[i+1][j+1] - mat[i][j];
			}

			matrix[i][j] = max(mat[i][j],max(martix[i][j+1],matrix[i+1][j]));
		}
	}

	return max_value;
}