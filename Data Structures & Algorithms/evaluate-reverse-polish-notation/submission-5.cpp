class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values {};

        if(tokens.empty()) return 0;
        if(tokens.size() == 1) return stoi(tokens[0]);

        values.push(stoi(tokens[0]));
        values.push(stoi(tokens[1]));

        for(int i = 2; i < tokens.size(); ++i) {
            string curr = tokens[i];
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
                int second = values.top();
                values.pop();
                int first = values.top();
                values.pop();

                if(curr == "+") {
                    values.push(first + second);
                }
                else if(curr == "-") {
                    values.push(first - second);
                }
                else if(curr == "/") {
                    values.push(first / second);
                }
                else if(curr == "*") {
                    values.push(first * second);
                }
            }
            else{
                values.push(stoi(curr));
            }
        }
        return values.top();
    }
};
