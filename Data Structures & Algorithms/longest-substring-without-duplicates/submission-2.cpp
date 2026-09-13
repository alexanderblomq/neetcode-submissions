class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int left = 0;
        unordered_set<char> seen;
        seen.reserve(s.length());

        int longest = 0;

        for(int right = 0; right < s.length(); ++right) {
            while(seen.contains(s[right]) && left < right) {
                seen.erase(s[left]);
                ++left;
            }

            seen.insert(s[right]);
            if(longest < right - left) longest = right - left;
        }

        return longest + 1;
    }
};