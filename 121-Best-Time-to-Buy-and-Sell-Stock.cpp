class Solution {
public:

    // void subSeq(vector<int>& prices, vector<int>& temp, int & ans, int p){
    //     if(temp.size() == 2){
    //         if(temp[1]-temp[0] > ans){
    //             ans = temp[1]-temp[0];
    //         }
    //         return;
    //     }
    //     if(p >= prices.size()){
    //         return;
    //     }

    //     temp.push_back(prices[p]);
    //     subSeq(prices, temp, ans, p+1);
    //     temp.pop_back();
    //     subSeq(prices, temp, ans, p+1);
    // }

    int maxProfit(vector<int>& prices) {
        int buyP = prices[0];
        int ans = 0;    //profit

        for(int p: prices){
            buyP = min(buyP, p);
            ans = max(ans, p - buyP);
        }


//// Or using recusrion backtracking::::=>

        // vector<int> temp;
        // int ans = 0;
        // subSeq(prices, temp, ans, 0);

        return ans;
    }
};