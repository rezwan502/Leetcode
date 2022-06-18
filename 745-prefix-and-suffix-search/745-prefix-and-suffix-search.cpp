class WordFilter {
public:
    
    struct trie{
        trie *nxt[28];
        int index;
        
        trie(){
            for(int i=0; i<28; i++){
                nxt[i] = NULL;
            }
            index = 0;
        }
    };
    
    trie *Trieroot;
    
    void insert_trie(trie* root, string str, int idx){
        
        for(auto x: str){
            
            if(root->nxt[x-'a'] == NULL){
                root->nxt[x-'a'] = new trie();
            }
            
            root = root -> nxt[x-'a'];
            root -> index = idx;
        }
    }
    
    int search(trie* root, string str){
        for(auto x: str){
            if(root->nxt[x-'a'] == NULL){
                return -1;
            }
            root = root -> nxt[x-'a'];
        }
        return root->index;
    }
    
    
    WordFilter(vector<string>& words) {
        Trieroot = new trie();
        
        int idx = 0;
        for (string word: words) {
            insert_trie(Trieroot, word, idx);
            string tmp = "{" + word;
            for (int i = word.length() - 1; i >= 0; i--) {
                string newword = word[i] + tmp;
                tmp = newword;
                insert_trie(Trieroot, newword, idx);
            }
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
       return search(Trieroot, suffix + "{" + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */