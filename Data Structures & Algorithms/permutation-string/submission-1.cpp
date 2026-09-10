class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length()) return false;
        vector<int> s1_counts(26);

        for(char c : s1) {
            ++s1_counts[c - 'a'];
        }

        int left = 0;
        int right = s1.length() - 1;

        vector<int> window_counts(26);

        for(int i = 0; i <= right; i++) {
            ++window_counts[s2[i] - 'a'];
        }

        while(right < s2.length()) {
            bool perm = true;
            for(int i = 0; i < 26; ++i) {
                if(window_counts[i] != s1_counts[i]) {
                    perm = false;
                }
            }

            if(perm) return true;
            
            ++right;
            if(right < s2.length()) {
                --window_counts[s2[left] - 'a'];
                ++window_counts[s2[right] - 'a'];
                ++left;
            }
        }

        return false;
    }
};
