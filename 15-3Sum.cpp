class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<nums.size()-2; i++){
            
            int j = i+1;
            int k = nums.size()-1;

            if(nums[i] < 0 && nums[k] < 0){
                break;
            }else if(nums[i] > 0 && nums[k] > 0){
                break;
            }

            while(j < k){
                if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                  
                    while(j+1 < nums.size() && nums[j] == nums[j+1]){
                        j++;
                    }
                    while(k-1 > 0 && nums[k] == nums[k-1]){
                        k--;
                    }
                    j++;
                    
                }
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]){
                i++;
            }
        }

        return ans;

        // set<vector<int>> s(ans.begin(), ans.end());
        // ans.clear();
        // vector<vector<int>> filteredans(s.begin(), s.end());

        // return filteredans;
    }
};