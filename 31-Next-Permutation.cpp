class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = nums.size()-1;

        while(pivot > 0 && nums[pivot] <= nums[pivot-1]){
            pivot--;
        }

        if(pivot == 0){
            reverse(nums.begin(), nums.end());
            return;
        }else{
            int greaterpivot = pivot;
            pivot--;
            while(greaterpivot < nums.size()-1 && nums[pivot] < nums[greaterpivot+1]){
                greaterpivot++;
            }
            // cout << "pivot: " << pivot << ": " << nums[pivot] << endl;
            // cout << "greaterpivot: " << ": " << nums[greaterpivot] << endl;
            
            int temp = nums[pivot];
            nums[pivot] = nums[greaterpivot];
            nums[greaterpivot] = temp;
            sort(nums.begin()+pivot+1, nums.end());
        }

        return;

    }
};