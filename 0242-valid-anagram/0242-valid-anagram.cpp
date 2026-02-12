class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int size = s.size();
        vector<int> numOfChar(500, 0);
        for (int i = 0; i < size; i++) {
            numOfChar[s[i] - '0']++;
            numOfChar[t[i] - '0']--;
        }
        int j = 500;
        while(j--) {
            if (numOfChar[j] != 0) return false;
        }
        return true;
    }
};