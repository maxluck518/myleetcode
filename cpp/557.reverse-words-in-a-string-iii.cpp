class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        stack<char> tmp;
        string new_s;
        for(int i = 0;i<len;i++){
            if(s[i] != ' '){
                tmp.push(s[i]);
            }
            else{
                while(!tmp.empty()){
                    new_s.push_back(tmp.top());
                    tmp.pop();
                }
                new_s.push_back(' ');
            }
        }
        while(!tmp.empty()){
            new_s.push_back(tmp.top());
            tmp.pop();
        }
       return new_s; 
    }
};
