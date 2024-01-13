
class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode*children[26];

    TrieNode(char ch):data(ch), isTerminal(false){
        for(int i=0;i<26;++i){
            children[i] = 0;
        }
    }
};

class Trie {
    TrieNode*root;

    void insertUtil(TrieNode*root, string&word, int i){
        if(i >= word.size()){
            root->isTerminal = 1;
            return;
        }

        int index = word[i] - 'a';
        if(!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode*root, string&word, int i){
        if(i >= word.size())
            return root->isTerminal;

        int index = word[i] - 'a';
        if(root->children[index])
            return searchUtil(root->children[index], word, i + 1);

        return false;
    }

    bool startsWithUtil(TrieNode*root, string&word, int i){
        if(i >= word.size())
            return true; // prefix found;

        int index = word[i] - 'a';
        if(root->children[index])
            return startsWithUtil(root->children[index], word, i + 1);

        return false;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertUtil(this->root, word, 0);
    }
    
    bool search(string word) {
        return searchUtil(this->root, word, 0);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(this->root, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

