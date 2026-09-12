class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        

        vector<string> subset(n, string(n, '.'));
        vector<vector<string>>board;

        

        set<int>cols;
        set<int> posDiag;
        set<int> negDiag;
        dfs(n,subset,board,0, cols, posDiag,negDiag);
        return board;
    }

    void dfs(int n,vector<string> &subset, vector<vector<string>> &board, int r, set<int>&cols,set<int> &posDiag,set<int> &negDiag)
    {
        if( r==n)
        {
            board.push_back(subset);
            return;
        }

        for( int c = 0; c<n; c++)
        {
            if(cols.contains(c) || posDiag.contains(r+c) || negDiag.contains(r-c))
            continue;
         
         cols.insert(c);
         posDiag.insert(r+c);
         negDiag.insert(r-c);
         subset[r][c] = 'Q';

         dfs(n,subset,board,r+1, cols,posDiag,negDiag);

         cols.erase(c);
         posDiag.erase(r+c);
         negDiag.erase(r-c);
         subset[r][c] ='.';

        }
        
    }



    
};
