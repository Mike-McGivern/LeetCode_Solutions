class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for(int r = 0; r < 4; r++) {
            if(mat == target) return true;
            rotate90(mat);

        }
        return false;
    }
private:
    void rotate90(vector<vector<int>>& m) {
        int n = m.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(m[i][j], m[j][i]);
            }
        }

        for(int i = 0; i < n; i++) {
            reverse(m[i].begin(), m[i].end());
        }
    }    
};
