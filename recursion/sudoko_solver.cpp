//method 1
class Solution {
public:
    bool is_okay(vector<vector<char>>& board,int r,int c,char val)
    {
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==val)
                return 0;
            if(board[i][c]==val)
                return 0;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==val)
                return 0;
        }
        return 1;
    }
    bool solver(vector<vector<char>>& board,int r,int c)
    {
        if(r==board.size())
            return true;
        if(c==board[0].size())
            return solver(board,r+1,0);
        if(board[r][c]!='.')
            return solver(board,r,c+1);
        for(char i='1';i<='9';i++)
        {
            if(is_okay(board,r,c,i))
            {
                board[r][c]=i;
                if(solver(board,r,c+1))
                    return 1;
                board[r][c]='.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
       solver(board,0,0);
    }
};


//method 2
class Solution {
public:
    bool is_possible(vector<vector<char>>& board,int row,int col,char val)
    {
         int part_row=3*(row/3);
         int part_col=3*(col/3);
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==val)
                return 0;
            if(board[row][i]==val)
                return 0;
           
            if(board[part_row+i/3][part_col+i%3]==val)
                return 0;
        }
        return 1;
    }
    bool solver(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(is_possible(board,i,j,k))
                        {
                            board[i][j]=k;
                            if(solver(board))
                                return 1;
                                board[i][j]='.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};
