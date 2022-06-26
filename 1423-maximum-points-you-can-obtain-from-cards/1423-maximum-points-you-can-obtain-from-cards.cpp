class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
        
        int n = cardPoints.size();
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum += cardPoints[i];
        }
        
        int ans = 0, window = 0;
        
        for(int i=0; i<=n-k-1; i++){
            window += cardPoints[i];
        }
        
        //cout << "Sum: " << sum << endl;
       // cout << "Window: " << window << endl;
        
        for(int i=n-k; i<n; i++){
           // cout << "Diff: " << sum - window << endl; 
            ans = max(ans, sum - window);
            window -= cardPoints[i-(n-k)];
            window += cardPoints[i];
          //  cout << "Window: " << window << endl;
        }
        
        ans = max(ans, sum - window);
       
        return ans;
    }
};