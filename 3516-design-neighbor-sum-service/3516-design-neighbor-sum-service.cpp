class NeighborSum {
public:
    vector<vector<int>> v;
    NeighborSum(vector<vector<int>>& grid) {
        v=grid;
    }
    
    int adjacentSum(int value) {

       int i = -1, j = -1;

        // Find position of the value
        for (int x = 0; x < v.size(); x++) {
            for (int y = 0; y < v[0].size(); y++) {
                if (v[x][y] == value) {
                    i = x;
                    j = y;
                    break;
                }
            }
            if (i != -1) break; // break outer loop too
        }

        if (i == -1) return 0;
        int sum=0;

        if(i-1>=0)sum+=v[i-1][j];
        if(i+1<v.size())sum+=v[i+1][j];
        if(j-1>=0)sum+=v[i][j-1];
        if(j+1<v[0].size())sum+=v[i][j+1];

        return sum;
        
    }
    
    int diagonalSum(int value) {

        int i = -1, j = -1;

        // Find position of the value
        for (int x = 0; x < v.size(); x++) {
            for (int y = 0; y < v[0].size(); y++) {
                if (v[x][y] == value) {
                    i = x;
                    j = y;
                    break;
                }
            }
            if (i != -1) break; // break outer loop too
        }

        if (i == -1) return 0;
        int sum=0;

        if(i-1>=0 && j-1>=0)sum+=v[i-1][j-1];
        if(i-1>=0 && j+1<v[0].size())sum+=v[i-1][j+1];
        if(i+1<v.size() && j-1>=0)sum+=v[i+1][j-1];
        if(i+1<v.size()&& j+1<v[0].size())sum+=v[i+1][j+1];

        return sum;
        
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */