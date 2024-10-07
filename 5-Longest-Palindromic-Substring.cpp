class Solution {
public:
    string longestPalindrome(string s) {
        string psubstr = "";

   
        int itr = 0;
        for(int i=0; i<s.size(); i++){
            
            while(i-itr >= 0 && i+itr<s.size() && s[i-itr] == s[i+itr]){
                itr++;
            }
            psubstr = psubstr.size() < 2*itr-1 ? s.substr(i-itr+1, 2*itr-1) : psubstr;
            itr = 0; 
            
            if(i+1 < s.size() && s[i] == s[i+1]){
                while(i-itr >= 0 && i+itr+1<s.size() && s[i-itr] == s[i+itr+1]){
                    itr++;
                }
                psubstr = psubstr.size() < 2*itr ? s.substr(i-itr+1, 2*itr) : psubstr;
                itr = 0; 
            }

        }

        return psubstr;
    }
};