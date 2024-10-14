class Solution {
public:

    bool check(vector<vector<char>>& board, int row, int col, int c){
        int size = board.size();

        for(int i=0; i<size; i++){
            
            if(board[row][i] == board[row][col] && i != col){
               cout << "x " << endl;
                return false;
            }

            if(board[i][col] == board[row][col] && i != row){
               cout << "y " << endl;
               cout  << i << " " << row << " " << col << " : " << board[i][col] << " == " << board[row][col] << " == " << c << endl;
                return false;
            }

            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == board[row][col] && (3*(row/3)+i/3 != row || 3*(col/3)+i%3 != col)){
                cout << "z " << endl;
                return false;
            }
        }
        
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int h_size = board.size();
        bool validity = true;

        for(int i=0; i<h_size; i++){
            for(int j=0; j<h_size; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                cout << board[i][j] << endl;
                validity = check(board, i, j, board[i][j]);
                if(validity == false){
                    break;
                }
            }
            if(validity == false){
                break;
            }
        }

        return validity;
    }
};