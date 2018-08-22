class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> mp_substr;
        string findstr;
        if(s.length() <= 10) return res;
        
        for(int i=0; i<s.length()-9; i++) {
            findstr = s.substr(i, 10);
            if(mp_substr.find(findstr) != mp_substr.end()){
                mp_substr[findstr]++;
            } else {
                mp_substr[findstr] = 1;
            }
        }
        
        for(auto it: mp_substr) {
            if(it.second > 1)
                res.push_back(it.first);
        }
        return res;
    }
};
