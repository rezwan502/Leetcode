class Solution {
public:
    
    int grid[51][51][51];
    int mod = 1e9+7;
    int dfs(int m, int n, int maxMove, int startRow, int startColumn){
        if(startRow >= m || startColumn >= n || startRow < 0 || startColumn < 0){
            return 1;
        }
        
        if(maxMove <=0 ){
            return 0;
        }
        
        if(grid[startRow][startColumn][maxMove] != -1){
            return grid[startRow][startColumn][maxMove];
        }
        
        long res = 0;
        res += dfs(m,n,maxMove-1,startRow+1,startColumn);
        res += dfs(m,n,maxMove-1,startRow-1,startColumn);
        res += dfs(m,n,maxMove-1,startRow,startColumn+1);
        res += dfs(m,n,maxMove-1,startRow,startColumn-1);
        
        return grid[startRow][startColumn][maxMove] = res % mod; 
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(grid,-1,sizeof grid);
        return dfs(m,n,maxMove,startRow,startColumn);
    }
};