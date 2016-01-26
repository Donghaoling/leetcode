class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> m;
        generate(m, "", n, n);
        return m;
    }
    void generate(vector<string> &m, string s, int l, int r) {
        if(l == 0 && r == 0) {
            m.push_back(s);
            return;
        }
        if(l > 0) generate(m, s+'(', l-1, r);
        if(r > l) generate(m, s+')', l, r-1);
    }
};
