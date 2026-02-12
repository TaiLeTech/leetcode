class Solution {
public:
    bool thoiTien (int *saved, int n) {
        if (n == 10 && saved[0] < 1) return false;
        if (n == 10 && saved[0] > 0) {
            saved[0]--;
            return true;
        }
        if (n ==20) {
            if (saved[1] > 0 && saved[0] > 0) {
            saved[0]--;
            saved[1]--;
            return true;
            }
            if (saved[0] > 2) {
                saved[0] -= 3;
                return true;
            }
        } 
        return false;
    }

    bool lemonadeChange(vector<int>& bills) {
        int saved[2];
        if(bills[0] != 5) return false;
        for (int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) saved[0]++;
            else if(bills[i] == 10 && thoiTien(saved, bills[i])) saved[1]++;
            else if (!thoiTien(saved, bills[i])) return false;
        }
        return true;
    }
};