class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //brute force: use another matrix. O(N^2) 
        
        //better approach: take transpose -> reverse every row then
        
        //transpose
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reverse rows
        for(int i=0; i<matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};