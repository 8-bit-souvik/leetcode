class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0; i<nums.size()-2; i++){
            temp.clear();
            temp.push_back(i);
            temp.push_back(i+1);
            temp.push_back(nums.size()-1);

            if(nums[temp[0]] < 0 && nums[temp[2]] < 0){
                break;
            }else if(nums[temp[0]] > 0 && nums[temp[2]] > 0){
                break;
            }

            while(temp[1] < temp[2]){
                if(nums[temp[0]] + nums[temp[1]] + nums[temp[2]] < 0){
                    temp[1]++;
                }else if(nums[temp[0]] + nums[temp[1]] + nums[temp[2]] > 0){
                    temp[2]--;
                }else{
                    ans.push_back({nums[temp[0]], nums[temp[1]], nums[temp[2]]});
                  
                    while(temp[1]+1 < nums.size() && nums[temp[1]] == nums[temp[1]+1]){
                        temp[1]++;
                    }
                    while(temp[2]-1 > 0 && nums[temp[2]] == nums[temp[2]-1]){
                        temp[2]--;
                    }
                    temp[1]++;
                    
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