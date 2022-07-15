class Trie {
public:
    
    struct Node{
        Node *nxt[26];
        bool isWord;
        bool pre;
        Node(){
            isWord = false;
            pre = false;
            for(int i=0; i<26; i++){
                nxt[i] = NULL; 
            }
        }
    };
    
    Node *root;
    
    Trie() {
         root = new Node();
    }
    
    void insert(string word) {
        Node *cur = root;
        for(int i=0; i<word.length(); i++){
            int imap = word[i] - 'a';
            if(cur->nxt[imap] == NULL){
                cur -> nxt[imap] = new Node();
            }
            cur -> pre = true;
            cur = cur -> nxt[imap];
        }
        cur -> pre = true;
        cur->isWord = true;
    }
    
    bool search(string word) {
        Node *cur = root;
        for(int i=0; i<word.length(); i++){
            int imap = word[i] - 'a';
            if(cur->nxt[imap] == NULL){
                return false;
            }
            cur = cur -> nxt[imap];
        }
        
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Node *cur = root;
        for(int i=0; i<prefix.length(); i++){
            int imap = prefix[i] - 'a';
            if(cur->nxt[imap] == NULL){
                return false;
            }
            cur = cur -> nxt[imap];
        }
        
        return cur->pre;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */