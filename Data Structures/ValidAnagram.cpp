#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (size(s) != size(t)) {
            return false;
        }

        sort(begin(s), end(s));
        sort(begin(t), end(t));

        for (int i = 0; i < (int)size(s); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};

// Driver Code
int main() {
    // Test 1 - s="anagram"; t="nagaram"
    {
        string s = "anagram", t = "nagaram";
        assert(Solution().isAnagram(s, t) == true);
        cout << "Test 1 Passed" << endl;
    }

    // Test 2 - s="rat"; t="car"
    {
        string s = "rat", t = "car";
        assert(Solution().isAnagram(s, t) == false);
        cout << "Test 2 Passed" << endl;
    }

    return 0;
}