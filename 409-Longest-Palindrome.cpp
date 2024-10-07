class Solution {
public:
    int longestPalindrome(string s) {
        
        int ans = 0;
        map<char, int> chmap;
        for(char x : s){
            if(chmap[x]){
                chmap[x]++;
            }else{
                chmap[x] = 1;
            }
        }

        // auto itr = chmap.begin();
        bool mid = 0;
        for(auto itr : chmap){
            if(itr.second%2 == 0){
                ans += itr.second;
            }else {
                ans += itr.second-1;
                mid = 1;
            }
        }

        return ans+mid;
    }
};