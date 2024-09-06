// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// .....
// .....
// ....

// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicates for the first number
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // Skip duplicates for the second number
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++; // Skip duplicates for the third number
                        while (k < l && nums[l] == nums[l + 1])
                            l--; // Skip duplicates for the fourth number
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> results = sol.fourSum(nums, target);

    cout << "Quadruplets forming the sum " << target << ":" << endl;
    for (const auto &quad : results)
    {
        cout << "[";
        for (int i = 0; i < quad.size(); ++i)
        {
            cout << quad[i] << (i < quad.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }

    return 0;
}
