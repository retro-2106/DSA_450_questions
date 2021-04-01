#include <bits/stdc++.h> 
using namespace std; 
  
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))  
  
int internalSearch(string needle, int row,  
                   int col, string hay[],  
                   int row_max, int col_max, int xx)  
{  
    int found = 0;  
  
    if (row >= 0 && row <= row_max && col >= 0 &&  
        col <= col_max && needle[xx] == hay[row][col])  
    {  
        char match = needle[xx]; 
        xx += 1; 
  
        hay[row][col] = 0;  
  
        if (needle[xx] == 0)  
        {  
            found = 1;  
        }  
        else
        {  
            found += internalSearch(needle, row,  
                                    col + 1, hay,  
                                    row_max, col_max,xx);  
            found += internalSearch(needle, row, col - 1,  
                                    hay, row_max, col_max,xx);  
            found += internalSearch(needle, row + 1, col,  
                                    hay, row_max, col_max,xx);  
            found += internalSearch(needle, row - 1, col,  
                                    hay, row_max, col_max,xx);  
        }  
        hay[row][col] = match;  
    }  
    return found;  
}  
 
int searchString(string needle, int row, int col,  
                  string str[], int row_count,  
                                int col_count)  
{  
    int found = 0;  
    int r, c;  
  
    for (r = 0; r < row_count; ++r) 
    {  
        for (c = 0; c < col_count; ++c)  
        {  
            found += internalSearch(needle, r, c, str,  
                                    row_count - 1,  
                                    col_count - 1, 0);  
        }  
    }  
    return found;  
} 