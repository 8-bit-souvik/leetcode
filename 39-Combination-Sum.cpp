class Solution {
public:
    void recursion(vector<int>& candidates, int target, int p, vector<int> & temp, vector<vector<int>> & ans){
        // cout << "ptr: " << p << " - ";
        // for(int x:temp){
        //     cout << x << " ";
        // }
        // cout << ": " << accumulate(temp.begin(), temp.end(), 0) << endl;

        if(accumulate(temp.begin(), temp.end(), 0) == target){
            ans.push_back(temp);
            return;
        }
        if(p > candidates.size() || accumulate(temp.begin(), temp.end(), 0) > target || p == 0){
            return;
        }

        for(int i=p-1; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            recursion(candidates, target, i+1, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        recursion(candidates, target, 1, temp, ans);

        return ans;
    }
};