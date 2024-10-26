class Solution {
public:

    void solve(int o, int c, string& tempString, vector<string> & result){

        if(o == 0 && c == 0){
            result.push_back(tempString);
            return;
        }

        if(o>0){
            tempString.push_back('(');
            solve(o-1, c, tempString, result);
            tempString.pop_back();
        }
        
        if(c>o){
            tempString.push_back(')');
            solve(o, c-1, tempString, result);
            tempString.pop_back();
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        string tempString;
        vector<string> result;

        solve(n, n, tempString, result);

        return result;
    }
};