// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Example 1:

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = n > 0 ? matrix[0].size() : 0;
        int col0 = 1;

        // First pass to mark the rows and columns to be zeroed
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j == 0) col0 = 0;
                    else matrix[0][j] = 0;
                }
            }
        }

        // Second pass to set the zeroes based on the markers
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set the first row to zero if needed
        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Set the first column to zero if needed
        if(col0 == 0) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

// Utility function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    cout << "Original matrix 1:" << endl;
    printMatrix(matrix1);

    sol.setZeroes(matrix1);
    
    cout << "Modified matrix 1:" << endl;
    printMatrix(matrix1);

    // Example 2
    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    cout << "Original matrix 2:" << endl;
    printMatrix(matrix2);

    sol.setZeroes(matrix2);
    
    cout << "Modified matrix 2:" << endl;
    printMatrix(matrix2);

    return 0;
}