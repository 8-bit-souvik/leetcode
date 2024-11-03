class Solution {
public:

    bool check(vector<string> & board, int row, int col){
        int board_size = board.size();
        for(int i=0; i<board_size; i++){
            if(board[row][i] == 'Q'){
                return false;
            }
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        int i, j;

        i = row;
        j = col;
        while((i >= 0 && i < board_size) && (j >= 0 && j < board_size)){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }

        i = row;
        j = col;
        while((i >= 0 && i < board_size) && (j >= 0 && j < board_size)){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++;
            j++;
        }

        i = row;
        j = col;
        while((i >= 0 && i < board_size) && (j >= 0 && j < board_size)){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }

        i = row;
        j = col;
        while((i >= 0 && i < board_size) && (j >= 0 && j < board_size)){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void nqueen(vector<string> & board, int p, int & ans){
        if(p == board.size()){
            ans++;
            return;
        }

        for(int i=0; i<board.size(); i++){
            if(check(board, p, i)){
                board[p][i] = 'Q';
                nqueen(board, p+1, ans);
                board[p][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int ans;

        nqueen(board, 0, ans);

        return ans;
    }
};