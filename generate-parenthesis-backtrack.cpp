//模仿装载问题的回溯解法
class Solution {
public:
    void parenthesis(vector<string> &m, string s, int l, int r) {
        if(l == 0 && r == 0) {
            m.push_back(s);
            return;
        }
        if(l > 0) {//加左括号
      		s = s + '(';
      		parenthesis(m, s, l-1, r);
      		s = s.substr(0, s.length()-1);
      	}
      	if(r > l) { //加右括号
      		s = s + ')';
      		parenthesis(m, s, l, r-1);
      		s = s.substr(0, s.length()-1);
      	}
    }
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        parenthesis(results, "", n, n);
        return results;
    }
};
