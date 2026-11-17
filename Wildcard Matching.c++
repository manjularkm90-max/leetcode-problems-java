class Solution {
public:
    bool isMatch(string s, string p) {
        return solve(s.size() - 1, p.size() - 1, s, p);
    }

private:
    bool solve(int i, int j, string &s, string &p) {
        if (i < 0 && j < 0)
            return true;

        if (i >= 0 && j < 0)
            return false;

        if (i < 0 && j >= 0)
            return isAllStars(p, j);

        if (s[i] == p[j] || p[j] == '?')
            return solve(i - 1, j - 1, s, p);

        if (p[j] == '*')
            return solve(i - 1, j, s, p) ||
                   solve(i, j - 1, s, p);

        return false;
    }

    bool isAllStars(string &p, int j) {
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*')
                return false;
        }
        return true;
    }
};
