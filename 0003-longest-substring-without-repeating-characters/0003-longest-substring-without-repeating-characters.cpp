class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        
        {
    unordered_set<char> seen;  // Stores unique characters in current window
    int left = 0, maxLen = 0;  // left pointer starts the window, maxLen tracks longest substring

    // Right pointer expands the window
    for (int right = 0; right < s.length(); right++) {
        while (seen.find(s[right]) != seen.end()) {  // If duplicate is found in window
            seen.erase(s[left]);  // Remove leftmost character to restore uniqueness
            left++;  // Shrink the window from the left side
        }
        seen.insert(s[right]);  // Add new character to window
        maxLen = max(maxLen, right - left + 1);  // Update max length found so far
    }

    return maxLen;
}
    }
};