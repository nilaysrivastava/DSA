// Given an array arr of n positive integers, your task is to find all the leaders in the array. An element of the array is considered a leader if it is greater than all the elements on its right side or if it is equal to the maximum element on its right side. The rightmost element is always a leader.

// Examples

// Input: n = 6, arr[] = {16,17,4,3,5,2}
// Output: 17 5 2
// Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.

// Input: n = 5, arr[] = {10,4,2,4,1}
// Output: 10 4 4 1
// Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side

// Input: n = 4, arr[] = {5, 10, 20, 40} 
// Output: 40
// Explanation: When an array is sorted in increasing order, only the rightmost element is leader.

// Input: n = 4, arr[] = {30, 10, 10, 5} 
// Output: 30 10 10 5
// Explanation: When an array is sorted in non-increasing order, all elements are leaders.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n <= 107
// 0 <= arr[i] <= 107

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
