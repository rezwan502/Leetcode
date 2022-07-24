class Solution {
public:
    
    bool isExist(vector<vector<int>>& matrix, int target, int curRow, int col){
        int left = 0;
        int right = col-1;
        
        while(left<=right){
            //cout << "Left: " << left << " "<< "Right: " << right << endl;
            int mid = (left + right)/2;
            
            //cout << "CurRow: " << curRow << " " << "Mid: " << mid << " " << matrix[curRow][mid] << endl;
            
            if(matrix[curRow][mid] == target){
                return true;
            }
            
            if(matrix[curRow][mid] > target){
                right = mid - 1;
            }else if(matrix[curRow][mid] < target){
                left = mid + 1;
            }
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        /*
        for(auto x: matrix){
            for(auto y: x){
                cout << y << " ";
            }
            cout << endl;
        }*/
        
        for(int i=0; i<row; i++){
            if(isExist(matrix,target,i,col)){
                return true;
            }
        }
        
        return false;
    }
};