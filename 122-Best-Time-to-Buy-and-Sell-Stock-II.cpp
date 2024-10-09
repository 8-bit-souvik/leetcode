class Solution {
public:
    int maxProfit(vector<int>& prices) {
//// Using two pointer::::==>
        int ans = 0;
        for(int i=0; i<prices.size(); i++){
            if(i+1<prices.size() && prices[i] < prices[i+1]){
                int j = i+1;
                while(j+1<prices.size() && prices[j]<prices[j+1]){
                    // cout << j << " : " << prices[j] << endl;
                    j++;
                }
                ans += prices[j]-prices[i];
                i=j;
            }
        }
        return ans;
    }
};