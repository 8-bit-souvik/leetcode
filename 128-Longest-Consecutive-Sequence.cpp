class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        int tempMax =1;

        if(nums.size() == 0){
            return 0;
        }

        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++){
            cout << nums[i-1] << " " << nums[i] << endl;
            if(nums[i-1]+1 == nums[i]){
                tempMax++;
            }else if(nums[i-1] == nums[i]){
                continue;
            }else{
                tempMax = 1;
            }
            ans = max(ans, tempMax);
        }

        return ans;
        
    }
};