#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.find(num) != end(seen)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

// Driver Code
int main() {
    // Test 1 - [1,2,3,1]
    {
        vector<int> arr = {1, 2, 3, 1};
        assert(Solution().containsDuplicate(arr) == true);
        cout << "Test 1 Passed" << endl;
    }

    // Test 2 - [1,2,3,4]
    {
        vector<int> arr = {1, 2, 3, 4};
        assert(Solution().containsDuplicate(arr) == false);
        cout << "Test 2 Passed" << endl;
    }

    // Test 3 - [1,1,1,3,3,4,3,2,4,2]
    {
        vector<int> arr = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        assert(Solution().containsDuplicate(arr) == true);
        cout << "Test 3 Passed" << endl;
    }
    return 0;
}