class Solution {
public:
    vector<vector<string>> res;
    vector<string> ans ;
    vector<vector<string>> solveNQueens(int n) {
        ans.resize(n);
        for(int i = 0 ; i < n ; i++)
        {
            ans[i] = string(n, '.');
        }
        nQueens(0,n);
        return res;
    }

    void nQueens(int k , int n)
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(place(k,i,n))
            {
                ans[k][i] = 'Q';
                if(k == n-1 )
                {
                    res.push_back(ans);
                }
                else
                {
                    nQueens(k+1 , n);
                }
                ans[k][i] = '.';
            }
        }
    }

   bool place(int k, int i, int n) 
   {
    for (int row = 0; row < k; row++) {
        if (ans[row][i] == 'Q') return false;
    }
    for (int row = k - 1, col = i - 1; row >= 0 && col >= 0; row--, col--) {
        if (ans[row][col] == 'Q') return false;
    }
    for (int row = k - 1, col = i + 1; row >= 0 && col < n; row--, col++) {
        if (ans[row][col] == 'Q') return false;
    }
    return true;

    }

    
    bool isdiagonal(int m , int  o ,int n)
    {
        int i = m-1 , j = o-1;
        while(i >= 0 && j >= 0)
        {
            if(ans[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j--;
        }
        i = m-1 ;
        j = o+1 ;
        while(i >= 0 && j < n)
        {
            if(ans[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j++;
        }
        i = m+1 ;
        j = o+1 ;
        while(i < n && j < n)
        {
            if(ans[i][j] == 'Q')
            {
                return false;
            }
            i++;
            j++;
        }
        i = m+1 ;
        j = o-1 ;
        while(i < n && j >= 0)
        {
            if(ans[i][j] == 'Q')
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};