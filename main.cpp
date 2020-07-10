class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> lucky;
        
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> &row = matrix[i];            
            int min = row[0];
            int index = 0;
            int rowSize = row.size();
            
            for (int j = 1; j < rowSize; ++j) {
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
