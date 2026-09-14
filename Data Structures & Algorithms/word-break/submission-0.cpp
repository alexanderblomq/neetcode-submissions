class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string_view> wordsInDict(wordDict.begin(), wordDict.end());
        vector<bool> visited(s.length() + 1, false);

        string_view view(s);

        queue<int> startsToTest;
        startsToTest.push(0);

        while(startsToTest.size() > 0) {
            int index = startsToTest.front();
            startsToTest.pop();
            for(int i = index; i <= s.length(); i++) {
                if(!visited[i]) {
                    if(wordsInDict.contains(view.substr(index, i - index))) {
                        if(i == s.length()) return true;
                        visited[i] = true;
                        startsToTest.push(i);
                    }
                }
            }
        }
        return false;
   }
};