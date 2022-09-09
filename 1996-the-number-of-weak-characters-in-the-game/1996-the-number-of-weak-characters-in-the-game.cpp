class Solution {
public:
    
    struct state{
        int attack;
        int defense;
    };
    
  
    static bool cmp(state a, state b) {
        if (a.attack == b.attack) {
            return a.defense > b.defense;
        }
        return a.attack < b.attack;
    }
    
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        state temp;
        vector<state> sortedList;
        
        for(int i=0; i<properties.size(); i++) {
            temp.attack = properties[i][0];
            temp.defense = properties[i][1];
            sortedList.push_back(temp);
        }
        
        sort(sortedList.begin(), sortedList.end(), cmp);
        
        /*
        for(auto x: sortedList) {
            cout << x.attack << " " << x.defense << endl;
        }
        cout << endl;
        */
        
        int miniDef = -1e9;
        int miniAtt = -1e9;
        
        int ans = 0;
        int len = sortedList.size();
        
        for(int i = len -1 ; i>=0; i--) {
            if(sortedList[i].defense < miniDef && sortedList[i].attack < miniAtt) {
               ans++;
            }
            
           if(miniDef < sortedList[i].defense) {
               miniDef = sortedList[i].defense;
               miniAtt = sortedList[i].attack;
           }
        }
        
        return ans;
    }
};