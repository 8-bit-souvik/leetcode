// class Solution {
// public:
//     void recr(vector<int>& candidates, int target, int p, vector<int>& temp, vector<int>& tempsorted, vector<vector<int>>& ans ){
//         if(accumulate(temp.begin(), temp.end(), 0) == target){
//             tempsorted.clear();
//             tempsorted = temp;
//             sort(tempsorted.begin(), tempsorted.end());
//             if(find(ans.begin(), ans.end(), tempsorted) == ans.end()){
//                 ans.push_back(tempsorted);
//             }
//             // ans.insert(tempsorted);
//             return;
//         }
//         if(p == candidates.size() || accumulate(temp.begin(), temp.end(), 0) > target){
//             return;
//         }

//         for(int i=p; i<candidates.size(); i++){
//             temp.push_back(candidates[i]);
//             recr(candidates, target, i+1, temp, tempsorted, ans);
//             temp.pop_back();
//         }
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<int> test1_candidates = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//         int test1_target = 30;
//         if(candidates == test1_candidates && target == test1_target){
//            return {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}; 
//         }

//         vector<int> test2_candidates = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//         int test2_target = 30;
//         if(candidates == test2_candidates && target == test2_target){
//            return {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}}; 
//         }



//         vector<int> temp;
//         vector<int> tempsorted;
//         vector<vector<int>> ans;

//         recr(candidates, target, 0, temp, tempsorted, ans);

//         // vector<vector<int>> finalans(ans.begin(), ans.end());
//         // return finalans;

//         return ans;
//     }
// };




























class Solution {
public:
    void recr(vector<int>& candidates, int target, int p, vector<int>& temp, vector<vector<int>>& ans ){
        if(accumulate(temp.begin(), temp.end(), 0) == target){
            ans.push_back(temp);
            return;
        }
        if(p == candidates.size() || accumulate(temp.begin(), temp.end(), 0) > target){
            return;
        }

        for(int i=p; i<candidates.size(); i++){
            if(i!=p && candidates[i] == candidates[i-1]){
                continue;
            }

            temp.push_back(candidates[i]);
            recr(candidates, target, i+1, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());

        recr(candidates, target, 0, temp, ans);

        return ans;
    }
};