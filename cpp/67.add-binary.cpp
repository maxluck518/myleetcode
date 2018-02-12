class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.length();
        int b_len = b.length();
        if(a_len == 0) return b;
        if(b_len == 0) return a;
        if(a[a_len-1] == '1' && b[b_len-1] == '1')
            // return addBinary(a.substr(0,a_len-1),b.substr(0,b_len-1)) + '0';
            return addBinary(addBinary(a.substr(0,a_len-1),b.substr(0,b_len-1)),"1") + '0';
        else if(a[a_len-1] == '0' && b[b_len-1] == '0')
            return addBinary(a.substr(0,a_len-1),b.substr(0,b_len-1)) + '0';
        else
            return addBinary(a.substr(0,a_len-1),b.substr(0,b_len-1)) + '1';
    }
};
