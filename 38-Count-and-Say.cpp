class Solution {
public:
    string encode(string s){
        string ens = "";
        int count;
        for(int i=0; i<s.size(); i++){
            count = 1;
            while(i+1 < s.size() && s[i] == s[i+1]){
                i++;
                count++;
            }
            ens += to_string(count);
            ens += s[i];
        }
        return ens;
    }

    string countAndSay(int n) {
        string ans = "1";
        for(int i=1; i<n; i++){
            ans = encode(ans);
        }
        return ans;
    }
};