class Solution {
public:
    int strStr(string haystack, string needle) {
        int h_len = haystack.length();
        int n_len = needle.length();
        for(int i = 0;i< h_len - n_len + 1;i++) {
            string s = haystack.substr(i,n_len);
            if(s == needle)
                return i;
        }
        return -1;
    }
};
