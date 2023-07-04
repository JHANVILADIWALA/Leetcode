class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        int k = (d + sum) / 2;
        if ((d + sum) % 2 != 0 || k<0) return 0; // decimal sum can't be found

        // counting subsets with the given sum k
        vector<vector<int>> t(arr.size() + 1, vector<int>(k + 1, 0));
        t[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                t[i][j] = t[i - 1][j];
                if (arr[i - 1] <= j) {
                    t[i][j] = (t[i][j] + t[i - 1][j - arr[i - 1]]) % 1000000007;
                }
            }
        }
        return t[n][k];
    }
};