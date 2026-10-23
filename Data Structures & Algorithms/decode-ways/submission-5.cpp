class Solution {
public:
    int numDecodings(string s) {
      if(s[0] == '0') return 0;
      vector<int> dp(s.length(), 0);

      int last_digit = -1;
      for(size_t i { 0 }; i < s.length(); ++i) {
        const char& letter = s[i];
        int digit = letter - '0';

        int two_digit_sol = 0;
        int one_digit_sol = 0;

        if(last_digit == 1 || (last_digit == 2 && digit <= 6)) {
            if(i == 1) {
                two_digit_sol = 1;
            }
            else two_digit_sol = dp[i - 2];
        }
        if(digit > 0) {
            if(i > 0) {
                one_digit_sol = dp[i - 1];
            }
            else one_digit_sol = 1;
        }

        dp[i] = one_digit_sol + two_digit_sol;
        last_digit = digit;
      }

      return dp[s.length() - 1];
    }
};
