#pragma GCC optimize ("O2")
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// Fast I/O optimization
auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution { // Note: LeetCode expects capital 'S' Solution
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> last_seen(128, -1);
        int max_len = 0;
        int left = 0; 
        
        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];
            
            // If the character was seen before and is inside the current window
            if (last_seen[current_char] >= left) {
                left = last_seen[current_char] + 1; // Direct jump logic
            }
            
            // Update the last seen position of the character
            last_seen[current_char] = right;
            
            // Calculate the window size and update max_len
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
}; // Ensure this semicolon and brace close the class cleanly