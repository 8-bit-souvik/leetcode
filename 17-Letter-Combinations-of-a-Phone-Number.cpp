class Solution {
public:
    int overflowNum(string maxN, string currN){
        for(int i=0; i<maxN.size(); i++){
            if(maxN[i] < currN[i]){
                return i;
            }
        }
        return -1;
    }

    string nextLexNum(string maxN, string currN){
        currN[currN.size()-1] += 1;
        int overflowIdx = overflowNum(maxN, currN);
        while(overflowIdx > -1){
            if(overflowIdx == 0){
                return "";
            }else{
                currN[overflowIdx-1] += 1;
                currN[overflowIdx] = '0';
            }
            overflowIdx = overflowNum(maxN, currN);
        }
        return currN;
    }

    void reComb(string digits, vector<string> idx, vector<string> & ans, string current, string maxv, int p){
        string temp = "";
        for(int i=0; i<digits.size(); i++){
            temp += (idx[int(digits[i])-int('0')][int(current[i])-int('0')]);
        }
        ans.push_back(temp);

        for(int i=0; i<digits.size(); i++){
            if(current[i] < maxv[i]){
                current[i] += 1;
                reComb(digits, idx, ans, current, maxv, p+1);
                current[i] -= 1;
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if("" == digits){
            return ans;
        }

        vector<string> idx = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string current(digits.size(), '0');
        string maxv;
        for(char x: digits){
            maxv += to_string(idx[int(x)-int('0')].size())[0]-1;
        }



        // reComb(digits, idx, ans, current, maxv, 0);
        // set<string> s(ans.begin(), ans.end());
        // ans.assign(s.begin(), s.end());


        while(current != ""){
            string temp;
            for(int i=0; i<digits.size(); i++){
                temp += idx[digits[i]-'0'][current[i]-'0'];
            }
            ans.push_back(temp);

            current = nextLexNum(maxv, current);
        }

        return ans;
    }
};