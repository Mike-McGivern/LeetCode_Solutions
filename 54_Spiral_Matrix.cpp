class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1;
        int up = 0, down = matrix.size() - 1;
        vector<int> result;

        while (left <= right && up <= down) {
            // Traverse the top row
            for (int i = left; i <= right; ++i)
                result.push_back(matrix[up][i]);
            up++;

            // Traverse the rightmost column
            for (int i = up; i <= down; ++i)
                result.push_back(matrix[i][right]);
            right--;

            // Traverse the bottom row
            if (up <= down) {
                for (int i = right; i >= left; --i)
                    result.push_back(matrix[down][i]);
                down--;
            }

            // Traverse the leftmost column
            if (left <= right) {
                for (int i = down; i >= up; --i)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }

        return result;
    }
};
