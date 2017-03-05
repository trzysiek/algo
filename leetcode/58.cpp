class Solution {
public:
    int lengthOfLastWord(string s) {
        int tmp = (int)s.size() - 1;
        while (tmp >= 0 && s[tmp] == ' ') tmp--;
        
        int result = 0;
        while (tmp >= 0 && s[tmp] != ' ') tmp--, result++;
        return result;
    }
};
