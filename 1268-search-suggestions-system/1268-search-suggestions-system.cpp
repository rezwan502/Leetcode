class Solution {
public:
struct trieNode
{
	bool isWord;
	trieNode *nxt[26];

	trieNode(){
		for(int i=0; i<26; i++) nxt[i] = NULL;
		isWord = false;
	}
};

trieNode *root = NULL;

void insert_trie(string str){
	trieNode *cur = root;
	int len = str.length();
	
	for(int i=0; i<len; i++){
		int imap = str[i] - 'a';
		if(cur->nxt[imap] == NULL){
			cur -> nxt[imap] = new trieNode();
		}
		cur = cur -> nxt[imap];
	}
	cur -> isWord = true;
}

void dfs(trieNode *cur, string prefix, vector<string> &result){
	if(result.size() == 3){
		return;
	}

	if(cur->isWord){
		result.push_back(prefix);
	}

	for(int i=0; i<26; i++){
		if(cur->nxt[i]){
			dfs(cur->nxt[i], prefix + (char)(i + 'a'), result);
		}
	}
}

vector<string> search_trie(string str){
	trieNode *cur = root;
	vector<string>result;
    
	int len = str.length();
	for(int i=0; i<len; i++){
		int imap = str[i] - 'a';
		if(cur->nxt[imap] == NULL){
			return {};
		}
		cur = cur->nxt[imap];
	}
        
    //cout << "Search: " << str << endl;
	dfs(cur,str,result);

	return result;
}

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
	vector<vector<string>> suggestions;
	vector<string>ans;
	root = new trieNode();

	for(auto x: products) insert_trie(x);	

	string str = "";
	for(auto x: searchWord){
		str += x;
		suggestions.push_back(search_trie(str));
	}

	return suggestions;
}


};