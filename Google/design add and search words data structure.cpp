class TrieNode {
public:
    TrieNode* children[26];
    bool end;

    TrieNode(){
        end = false;
        for(auto &a: children) a = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(char c: word){
            if(temp->children[c-'a']){
                temp = temp->children[c-'a'];
            }else{
                TrieNode* newNode = new TrieNode();
                temp->children[c-'a'] = newNode;
                temp = newNode;
            }
        }
        temp->end = true;
    }
    
    bool search(string word) {
        return search2(root, word, 0);
    }

    bool search2(TrieNode* temp, string word, int idx){
        if(temp->end and idx == word.size()) return true;
        if(idx >= word.size()) return false;

        if(word[idx] == '.'){
            bool ans = false;
            for(int i=0; i<26; i++){
                if(temp->children[i]){
                    ans |= search2(temp->children[i], word, idx+1);
                    if(ans) return true;
                }
            }
            return ans;
        }
        if(temp->children[word[idx] - 'a'] == NULL) return false;
        return search2(temp->children[word[idx] - 'a'], word, idx+1);
    }
};

class WordDictionary {
    Trie* trie;
public:
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */