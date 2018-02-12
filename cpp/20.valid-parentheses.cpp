class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        int len = s.length();
        for(int i = 0;i < len;i++){
            if(isLeft(s[i]))
                left.push(s[i]);
            else if(isRight[s[i]]){
                char top = left.top();
                if(!match(top,s[i]))
                    return false;
                left.pop();
            }
            else
                return false;
        }
        return true;
    }
    bool isLeft(char a) {
        if(a == "(" || a == "{" || a == "[")
            return true;
        else
            return false;
    }
    bool isRight(char a) {
        if(a == ")" || a == "}" || a == "]")
            return true;
        else
            return false;
    }
    bool match(char left,char right){
        if(left == "(" && right == ")")
            return true;
        else if(left == "[" && right == "]")
            return true;
        else if(left == "{" && right == "}")
            return true;
        else
            return false;
    }
};
