class Solution {
public:
    bool isPalindrome(string s) {
        // for(int i=s.size()-1; i>=0; i--){
        //     if(s[i] >= '0' && s[i] <= '9'){
                
        //     }else if(s[i] >= 'A' && s[i] <= 'Z'){
        //         s[i] = s[i]+'z'-'Z';
        //     }else if(s[i] < 'a' || s[i] > 'z'){
        //         s.erase(s.begin()+i);
        //     }
        // }

        string s1;
        for(char i:s){
            if((i >= '0' && i <= '9') || (i >= 'a' && i <= 'z')){
                s1.push_back(i);
            }else if(i >= 'A' && i <= 'Z'){
                s1.push_back(i+'z'-'Z');
            }
        }


        // cout << s1 <<endl;

        int l = 0;
        int r = s1.size()-1;
        while(l<=r){
            if(s1[l] != s1[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};