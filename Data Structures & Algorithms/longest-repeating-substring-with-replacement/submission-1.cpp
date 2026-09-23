class Solution {
  public:
    int characterReplacement(string s, int k) {
      int left = 0;
      
      vector<int> counts(26, 0);
      
      int maxLength = 0;

      for(int right = 0; right < s.length(); ++right) {
        counts[s[right] - 'A']++;
        while((right - left + 1) - mostFrequent(counts) > k) {
          counts[s[left] - 'A']--;
          ++left;
        }
        maxLength = max(maxLength, right - left + 1);
      }

      return maxLength;
    }

    int mostFrequent(vector<int> counts) {
      int mostFreq { 0 };
      for(int count : counts) {
        mostFreq = max(mostFreq, count); 
      }
      return mostFreq;
    }
};
