class Solution {
public:
    int myAtoi(string s) {
        int dau = 1;
        int idx = 0;
        int result = 0;
        while (s[idx] == ' ') idx++;
        while (s[idx] == '0') {
            idx++;
            if (!isdigit(s[idx])) return 0;
            }

        if(s[idx] == '-') {
            dau = -1;
            idx++;
        }
        else if (s[idx] == '+') idx++;
        while (isdigit(s[idx]) && idx < s.size()) {
            if (dau*result > INT_MAX/10|| dau*result == INT_MAX/10 && s[idx] - '0' > INT_MAX%10) return INT_MAX;
            if (dau*result < INT_MIN/10 || dau*result == INT_MIN/10 && s[idx] - '0' > 7) return INT_MIN; 
            result = result*10 + (s[idx] - '0');
            idx++;
        }
        return (dau > 0 ? result : -result);
 
    }
};