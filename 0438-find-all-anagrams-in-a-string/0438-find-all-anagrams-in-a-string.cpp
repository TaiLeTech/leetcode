class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        vector<int> result;
        for (int i = 0; i <= s.size() - p.size(); i++) {
            string compared = s.substr(i, p.size());
            if (isAnagram(compared, p)) result.push_back(i);
        }
        return result;
    }

    bool isAnagram(string compared, string t) {
        vector<int> numOfChar(26, 0); 
        int n = compared.size();
        for (int i = 0; i < n; i++) {
            numOfChar[compared[i] - 'a']++;
            numOfChar[t[i] - 'a']--;
        }
        for (int count : numOfChar) {
            if (count != 0) return false;
        }
        return true;
    }
};