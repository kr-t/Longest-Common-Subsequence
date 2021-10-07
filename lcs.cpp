#include "lcs.hpp"

/* Returns LCS for comparetive and original patterns */
std::string longestCommonSubsequence(std::string X, std::string Y)
{
    int m = X.size();
    int n = Y.size();
    
    std::vector< std::vector<int> > L( ( m+1 ), std::vector<int> ( n+1 ) );

    /* Construct L[m+1][n+1] using Tabulation */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            /* Fill L[m][0] and L[n][0] with zeros */
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }

            else if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }

            else
            {
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    /* Traceback the LCS from cell L[m][n] to cell L[0][0] */
    int index = L[m][n];

    /* Array to store the lcs string */
    std::vector<char> lcs(index);

    while ((m > 0) && (n > 0))
    {
        if (X[m - 1] == Y[n - 1])
        {
            /* Current char is part of LCS */
            lcs[index - 1] = X[m - 1];
            /* Decrement values of m, n and index */
            m--;
            n--;
            index--;
        }

        /* Follow the direction of larger value */
        else if (L[m - 1][n] > L[m][n - 1])
        {
            m--;
        }
        else
        {
            n--;
        }
    }

    /* Copy char to string */
    std::string retValue(lcs.begin(), lcs.end());
    
    return retValue;
}
