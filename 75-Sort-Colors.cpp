class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());

// // Bubble Sort:
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size()-i; j++){
                if(j+1 < nums.size() && nums[j+1] < nums[j]){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
                
            }
        }



// // Using Map:
    //     map<int, int> colormap;
    //     for(int x:nums){
    //         if(colormap[x]){
    //             colormap[x]++;
    //         }else{
    //             colormap[x] = 1;
    //         }
    //     }

    //     fill(nums.begin(), nums.begin()+colormap[0], 0);
    //     fill(nums.begin()+colormap[0], nums.begin()+colormap[0]+colormap[1], 1);
    //     fill(nums.begin()+colormap[0]+colormap[1], nums.end(), 2);

    }
};