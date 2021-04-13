class Solution{
    public:
    static int cmp(int a,int b)
    {
        int count1 = __builtin_popcount(a);
        int count2 = __builtin_popcount(b);

        if (count1 <= count2)
            return false;
        return true;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, cmp);
    }
};
