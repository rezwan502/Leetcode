class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int first = 0;
        int last = 0;
        int n = cardPoints.size();
        
        for(int i=0; i<n; i++){
            if(i<k){
                first += cardPoints[i];
            }
            
            if(i >= (n-k)){
                last += cardPoints[i];
            }
            
        }
        
        bool taken[n+1];
        
        int maxi = max(first,last);
        int fr = first;
        int lr = 0;
        int m = n;
       // cout << "M: "<< maxi << endl;
        
        if(n != k){
            for(int i=0; i<n; i++){
                if(k>0){
                    fr = fr - cardPoints[k-1];
                    lr = lr + cardPoints[m-1];
                    int t = fr + lr;
                    
                  //  cout << fr << " " << lr <<" " << t << endl;
                    
                    maxi = max(maxi,t);
                    
                    k--;
                    m--;
                }
            }    
        }
        
        return maxi;
    }
};