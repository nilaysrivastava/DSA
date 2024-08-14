// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

// ...

// Constraints:

// 1 <= nums.length <= 5 * 104
// -231 <= nums[i] <= 231 - 1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        vector<int> temp(nums.size());
        return mergeSortAndCount(nums, temp, 0, nums.size() - 1);
    }

private:
    int mergeSortAndCount(vector<int> &nums, vector<int> &temp, int left, int right)
    {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        int count = 0;

        count += mergeSortAndCount(nums, temp, left, mid);
        count += mergeSortAndCount(nums, temp, mid + 1, right);
        count += mergeAndCount(nums, temp, left, mid, right);

        return count;
    }

    int mergeAndCount(vector<int> &nums, vector<int> &temp, int left, int mid, int right)
    {
        int i = left;
        int j = mid + 1;
        int k = left;
        int count = 0;
        while (i <= mid && j <= right)
        {
            if ((long long)nums[i] > 2 * (long long)nums[j])
            {
                count += (mid - i + 1);
                j++;
            }
            else
            {
                i++;
            }
        }
        i = left;
        j = mid + 1;
        k = left;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid)
        {
            temp[k++] = nums[i++];
        }

        while (j <= right)
        {
            temp[k++] = nums[j++];
        }

        for (int i = left; i <= right; ++i)
        {
            nums[i] = temp[i];
        }

        return count;
    }
};

int main()
{
    vector<int> nums = {1, 3, 2, 3, 1};

    Solution solution;
    int result = solution.reversePairs(nums);

    cout << "Number of important reverse pairs: " << result << endl;

    return 0;
}
