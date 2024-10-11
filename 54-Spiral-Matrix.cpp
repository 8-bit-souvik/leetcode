class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int leftbound = 0;
        int upbound = 0;
        int rightbound = matrix[0].size()-1;
        int downbound = matrix.size()-1;
        vector<int> ans;

        while(leftbound<=rightbound || upbound <= downbound){
            for(int i=leftbound; i<=rightbound; i++ ){
                ans.push_back(matrix[upbound][i]);
                // cout << matrix[upbound][i] << " ";
            }
            upbound++;
            if(leftbound>rightbound || upbound > downbound){
                break;
            }
            for(int i=upbound; i<=downbound; i++ ){
                ans.push_back(matrix[i][rightbound]);
                // cout << matrix[i][rightbound] << " ";
            }
            rightbound--;
            if(leftbound>rightbound || upbound > downbound){
                break;
            }
            for(int i=rightbound; i>=leftbound; i-- ){
                ans.push_back(matrix[downbound][i]);
                // cout << matrix[downbound][i] << " ";
            }
            downbound--;
            if(leftbound>rightbound || upbound > downbound){
                break;
            }
            for(int i=downbound; i>=upbound; i-- ){
                ans.push_back(matrix[i][leftbound]);
                // cout << matrix[i][leftbound] << " ";
            }
            leftbound++;
        }

        return ans;
    }
};