#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Mine: Brute Force
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < (int)size(nums); i++) {
            for (int j = i + 1; j < (int)size(nums); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Leetcode: 2-pass Hash solution
// class Solution {
//    public:
//     vector<int> twoSum(vector<int> &nums, int target) {
//         unordered_map<int, int> hash;
//         for (int i = 0; i < nums.size(); i++) {
//             hash[nums[i]] = i;
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             int complement = target - nums[i];
//             if (hash.find(complement) != hash.end() && hash[complement] != i) {
//                 return {i, hash[complement]};
//             }
//         }
//         // If no valid pair is found, return an empty vector
//         return {};
//     }
// };

// Driver Code
int main() {
    // Test 1 - nums=[2,7,11,15]; target=9; expected=[0,1]
    {
        vector<int> nums = {2, 7, 11, 15}, expected = {0, 1};
        int target = 9;
        assert(Solution().twoSum(nums, target) == expected);
        cout << "Test 1 Passed" << endl;
    }

    // Test 2 - nums=[3,2,4]; target=6; expected=[1,2]
    {
        vector<int> nums = {3, 2, 4}, expected = {1, 2};
        int target = 6;
        assert(Solution().twoSum(nums, target) == expected);
        cout << "Test 2 Passed" << endl;
    }

    // Test 3 - nums=[3,3]; target=6; expected=[0,1]
    {
        vector<int> nums = {3, 3}, expected = {0, 1};
        int target = 6;
        assert(Solution().twoSum(nums, target) == expected);
        cout << "Test 3 Passed" << endl;
    }

    // Test 4 - nums=[3,2,3]; target=6, expected=[0,2]
    {
        vector<int> nums = {3, 2, 3}, expected = {0, 2};
        int target = 6;
        assert(Solution().twoSum(nums, target) == expected);
        cout << "Test 4 Passed" << endl;
    }
    return 0;
}