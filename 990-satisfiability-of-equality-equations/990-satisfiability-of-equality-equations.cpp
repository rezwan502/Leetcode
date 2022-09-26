class Solution {
public:
    int par[26];
    
    void makeset() {
        for(int i=0; i<26; i++) {
            par[i] = i;
        }
    }
    
    int Find(int n) {
        if (par[n] == n) return n;
        return par[n] = Find(par[n]);
    }
    
    void Union(int a, int b) {
        int u = Find(a);
        int v = Find(b);
        
        par[u] = par[v];
    }
    
    bool equationsPossible(vector<string>& equations) {
        makeset();
        for(string eq: equations) {
            if(eq[1] == '=') {
                Union(eq[0]-'a',eq[3]-'a');
            }
        }
        
        for(string eq: equations) {
            if(eq[1] == '!') {
                if (Find(eq[0]-'a') == Find(eq[3]-'a')) {
                    return false;
                }
            }
        }
        
        return true;
    }
};