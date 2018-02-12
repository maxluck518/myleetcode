class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int cnt = 1;
        for(int i = len - 1;i >= 0;i--){
            digits[i] = (digits[i] + cnt) % 10;
            if(digits[i] == 0 && cnt == 1){
                cnt = 1;
            }
            else
                cnt = 0;
        }
        if(cnt == 1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};

