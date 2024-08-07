// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

// Constraints:

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        
        // Sort the intervals based on their start times
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // If the answer list is empty or the current interval does not overlap with the last one in ans
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                // If there is overlap, merge the intervals
                ans.back()[1] = std::max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example 1
    std::vector<std::vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> merged1 = solution.merge(intervals1);

    std::cout << "Merged intervals for example 1: ";
    for (const auto& interval : merged1) {
        std::cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    std::cout << std::endl;

    // Example 2
    std::vector<std::vector<int>> intervals2 = {{1, 4}, {4, 5}};
    std::vector<std::vector<int>> merged2 = solution.merge(intervals2);

    std::cout << "Merged intervals for example 2: ";
    for (const auto& interval : merged2) {
        std::cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
