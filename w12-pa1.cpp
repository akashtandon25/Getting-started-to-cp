

#include <iostream>
#include <vector>
using namespace std;
 
int FindWays(int n, int m, vector<vector<int>>& blockedCell) {
    int mod = 1000000007;
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
 
    for (int i = 0; i < blockedCell.size(); i++) {
        matrix[blockedCell[i][0]][blockedCell[i][1]] = -1;
    }
 
    for (int i = 0; i <= n; i++) {
        if (matrix[i][1] != -1)
            matrix[i][1] = 1;
    }
    for (int j = 0; j <= m; j++) {
        if (matrix[1][j] != -1)
            matrix[1][j] = 1;
    }
 
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (matrix[i][j] == -1) {
                continue;
            }
            if (matrix[i - 1][j] != -1 && matrix[i][j - 1] != -1) {
                matrix[i][j] = (matrix[i - 1][j] + matrix[i][j - 1]) % mod;
            } else if (matrix[i - 1][j] != -1) {
                matrix[i][j] = matrix[i - 1][j];
            } else if (matrix[i][j - 1] != -1) {
                matrix[i][j] = matrix[i][j - 1];
            } else {
                matrix[i][j] = -1;
            }
        }
    }
 
    if (matrix[n][m] < 0) {
        return 0;
    } else {
        return matrix[n][m];
    }
}

int main() {
    int t,n,m;
    cin>>t>>n>>m;
    for(int i=0; i<t; i++){
        vector<vector<int>>grid (n, vector<int> (m));
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>grid[i][j];
            }
        }
        cout<<FindWays(n,m,grid)<<endl;
    }
    return 0;
}