class Solution {
public:
    vector<string> letterCombinations(string digits) {
        init();
        if(digits.length() == 0)
            return result;
        string trace;
        int pos = 0;
        dfs(digits,pos,trace);
        return result;
    }
    void dfs(string digits,int pos,string &trace){
        if(pos == digits.length()) {
            result.push_back(trace);
            return;
        }
        int num = digits[pos] - '0';

        string sub = keyboard[num];
        for(int i = 0;i<sub.length();i++){
            trace.push_back(sub[i]);
            dfs(digits,pos+1,trace);
            trace.pop_back();
        }
    }
private:
    map<int,string> keyboard;
    vector<string> result;
    void init(){
        keyboard[0] = "";
        keyboard[1] = "";
        keyboard[2] = "abc";
        keyboard[3] = "def";
        keyboard[4] = "ghi";
        keyboard[5] = "jkl";
        keyboard[6] = "mno";
        keyboard[7] = "pqrs";
        keyboard[8] = "tuv";
        keyboard[9] = "wxyz";
    }
};
