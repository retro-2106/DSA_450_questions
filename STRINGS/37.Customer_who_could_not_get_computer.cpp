int runCustomerSimulation(int n, const char *seq) 
{ 
    char seen[MAX_CHAR] = {0}; 

    int res = 0; 
  
    int occupied = 0;

    for (int i=0; seq[i]; i++) 
    { 

        int ind = seq[i] - 'A'; 
        if (seen[ind] == 0) 
        { 

            seen[ind] = 1; 

            if (occupied < n) 
            { 
                occupied++; 
                seen[ind] = 2; 
            } 

            else
                res++; 
        } 

        else
        { 
           if (seen[ind] == 2) 
               occupied--; 
           seen[ind] = 0; 
        } 
    } 
    return res; 
}