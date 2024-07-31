// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:

// Input: numRows = 1
// Output: [[1]]

// Constraints:

// 1 <= numRows <= 30

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++) {
            long long el = 1;
            vector<int> ansRow;
            ansRow.push_back(1);
            for (int col = 1; col < row; col++) {
                el = el * (row - col);
                el = el / col;
                ansRow.push_back(el);
            }
            ans.push_back(ansRow);
        }
        return ans;
    }
};

void printPascalsTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    int numRows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    vector<vector<int>> result = solution.generate(numRows);

    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    printPascalsTriangle(result);

    return 0;
}
