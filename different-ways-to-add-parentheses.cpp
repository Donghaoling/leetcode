class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if(input.length() == 0) {
            return res;
        }
        if(input.find("+") == -1 && input.find("-") == -1 && input.find("*") == -1) {
            res.push_back(stoi(input));
            return res;
        }
        for(int i = 0; i < input.length(); ++i) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> leftVec = diffWaysToCompute(input.substr(0, i));
                vector<int> rightVec = diffWaysToCompute(input.substr(i+1, input.length() - i - 1));
                for(auto it1 = leftVec.begin(); it1 != leftVec.end(); ++it1) {
                    for(auto it2 = rightVec.begin(); it2 != rightVec.end(); ++it2) {
                        if(input[i] == '+') {
                            res.push_back(*it1 + *it2);
                        }
                        else if(input[i] == '-') {
                            res.push_back(*it1 - *it2);
                        }
                        else {
                            res.push_back(*it1 * *it2);
                        }
                    }
                }
            }
        }
        return res;
    }
};
