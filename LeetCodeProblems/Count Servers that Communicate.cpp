// Problem Link
// https://leetcode.com/problems/count-servers-that-communicate/description/


// Source Code

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        vector<int> row(m, 0), col(n, 0);


        for(int i = 0;i < m;i++){
            int c = 0;
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    c++;
                }
            }
            row[i] = c;
            cout << row[i] << " ";
        }

        for(int i = 0;i < n;i++){
            int c = 0;

            for(int j = 0;j < m;j++){
                if(grid[j][i] == 1){
                    c++;
                }
            }
            col[i] = c;
        }

        for(int i = 0;i < m;i++){
            if(row[i] > 1){
                for(int j = 0;j < n;j++){
                    grid[i][j] = 0;
                    // col[j]--;
                }
                res += row[i];
            }
        }

        for(int i = 0;i < n;i++){
            if(col[i] > 1){
                for(int j = 0;j < m;j++){
                    if(grid[j][i] == 1){
                        res++;
                    }
                }

                // res += col[i];
            }
        }

        return res;
    }
};