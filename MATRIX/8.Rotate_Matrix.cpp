void rotate90Clockwise(int arr[N][N])
{
    for (int j = 0; j < N; j++) 
    {
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}