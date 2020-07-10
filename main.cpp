class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> lucky;
        
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> &row = matrix[i];
            int min = 0;
            int index = -1;
            
            if (row.size() > 0) {
                min = row[0];
                index = 0;
            }
            
            for (int j = 1; j < row.size(); ++j) {
                if (row[j] < min) {
                    min = row[j];
                    index = j;
                }
            }
            
            if (index > -1) {
                bool isMax = true;
                
                for (int j = 0; j < matrix.size(); ++j) {
                    if (matrix[j][index] > min) {
                        isMax = false;
                        break;
                    }
                }
                
                if (isMax) {
                    lucky.push_back(min);
                }
            }
        }
        
        return lucky;
    }
};
