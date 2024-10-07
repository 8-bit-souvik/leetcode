class Solution {
public:
    int trap(vector<int>& height) {
        int left_max_h = 0;
        int right_max_h = 0;
        vector<int> water(height.size(), '_');

        int n = height.size()-1;
        for(int i=0; i<=n; i++){
            if(left_max_h >= height[i]){
                if(water[i] == '_'){
                    water[i] = (left_max_h - height[i]);
                }else{
                    water[i] = min(water[i], (left_max_h - height[i]));
                }
            }else{
                water[i] = (0);
                left_max_h = height[i]; 
            }

            if(right_max_h >= height[n-i]){
                if(water[n-i] == '_'){
                    water[n-i] = (right_max_h - height[n-i]);
                }else{
                    water[n-i] = min(water[n-i], (right_max_h - height[n-i]));
                }
            }else{
                water[n-i] = (0);
                right_max_h = height[n-i]; 
            }
        }

        return accumulate(water.begin(), water.end(), 0);
    }
};