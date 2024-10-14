class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> tempVec;
        set<int> tempSet;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    tempVec.push_back(board[i][j]);
                    tempSet.insert(board[i][j]);
                }
            }

            if(tempVec.size() != tempSet.size()){
                return false;
            }
            tempVec.clear();
            tempSet.clear();
        }

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[j][i] != '.'){
                    tempVec.push_back(board[j][i]);
                    tempSet.insert(board[j][i]);
                }
            }

            if(tempVec.size() != tempSet.size()){
                return false;
            }
            tempVec.clear();
            tempSet.clear();
        }

        for(int i=0; i<=6; i=i+3){
            for(int j=0; j<=6; j=j+3){
                for(int k=0; k<9; k++){
                    if(board[k/3+i][k%3+j] != '.'){
                        tempVec.push_back(board[k/3+i][k%3+j]);
                        tempSet.insert(board[k/3+i][k%3+j]);
                    }
                }

                if(tempVec.size() != tempSet.size()){
                    return false;
                }
                tempVec.clear();
                tempSet.clear();
            }
        }

        return true;
    }
};