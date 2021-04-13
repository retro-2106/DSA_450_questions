class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {
        if( n == 1)
        return true;
        
        return n && (!(n & (n-1)));
    }
};
