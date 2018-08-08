class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(): isKey(false) {
        memset(children, NULL, sizeof(TrieNode*) * 26);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * run = root;
        int n = word.length();
        for(int i = 0;i<n;i++) {
            if(!run->children[word[i] - 'a']){
                run ->children[word[i] - 'a'] = new TrieNode();
            }
            run = run -> children[word[i] - 'a'];
        }
        run -> isKey = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.length();
        TrieNode* run = root;
        for(int i = 0;i<n;i++){
            if(run && run->children[word[i] - 'a']){
                run = run->children[word[i] - 'a'];
            }
            else {
                return false;
            }
        }
        return run && run->isKey;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.length();
        TrieNode* run = root;
        for(int i = 0;i<n;i++){
            if(run && run->children[prefix[i] - 'a']){
                run = run->children[prefix[i] - 'a'];
            }
            else {
                return false;
            }
        }
        return true;
        
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
