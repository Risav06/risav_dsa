#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, end = 0;

        auto expand = [&](int l, int r) -> pair<int,int> {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--; r++;
            }
            return {l + 1, r - 1};
        };

        for (int i = 0; i < s.size(); i++) {
            // Odd-length
            auto [l1, r1] = expand(i, i);
            if (r1 - l1 > end - start) { start = l1; end = r1; }

            // Even-length
            auto [l2, r2] = expand(i, i + 1);
            if (r2 - l2 > end - start) { start = l2; end = r2; }
        }

        return s.substr(start, end - start + 1);
    }
};
