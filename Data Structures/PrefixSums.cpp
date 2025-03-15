#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getPrefixSums(vector<int> &arr) {
    vector<int> prefixSums;
    prefixSums.push_back(arr[0]);

    auto it1 = begin(arr), it2 = begin(prefixSums);

    int prevSum = 0;
    while (it1 != end(arr)) {
        prevSum = *it2;
        it1++;
        it2++;

        *it2 = prevSum + *it1;
    }

    return prefixSums;
}

int main() {
    vector<int> arr = {3, 2, 4, 5, 1}, expected = {3, 5, 9, 14, 15};
    vector<int> prefixSums = getPrefixSums(arr);

    for (auto i = 0; i < (int)arr.size(); i++) {
        if (prefixSums[i] != expected[i]) {
            cout << "[ERROR] PrefixSums[" << i << "]: " << prefixSums[i] << ", Expected = = " << expected[i] << endl;
            return 1;
        }
    }

    cout << "Successfully calculated prefix sums." << endl;
    return 0;
}