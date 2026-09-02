class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramLists;
        
        for(const string& input : strs) {
            string key { input };
            sort(key.begin(), key.end());
            anagramLists[key].push_back(input);
        }

        vector<vector<string>> output;
        for(auto &[key, val] : anagramLists) {
            output.push_back(std::move(val));
        }
        return output;
    }
};
