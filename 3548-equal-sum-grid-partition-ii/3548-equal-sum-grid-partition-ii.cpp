class Solution {
public:
    typedef long long ll;
    bool helper(vector<vector<int>>&grid){
        int n=grid.size(),m=grid[0].size();
        ll bottom=0, top=0;
        vector<int>freq2(100001,0),freq1(100001,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bottom+=grid[i][j];
                freq2[grid[i][j]]++;
            }
        }
        for(int i=0;i<n-1;i++){
           for(int j=0;j<m;j++){
                bottom-=grid[i][j];
                freq2[grid[i][j]]--;
                top+=grid[i][j];
                freq1[grid[i][j]]++;
           }
           if(top==bottom)return true;
           ll diff=top-bottom;
           if(diff>0 && diff<=100000){
              int l=i+1,r=m;
              if(l>1 && r>1){
                if(freq1[diff])return true;
                }
                else if(l>1 && r==1){
                    if(grid[0][0]==diff || grid[i][0]==diff)return true;
                }else if(l==1 && r>1){
                    if(grid[0][0]==diff || grid[0][r-1]==diff)return true;
                }
           }
           diff=bottom-top;
           if(diff>0 && diff<=100000){
            int l=(n-i-1),r=m;
            if(l>1 && r>1){
                if(freq2[diff])return true;
            }else if(l>1 && r==1){
                if(grid[i+1][0]==diff || grid[n-1][0]==diff)return true;
            }else if(l==1 && r>1){
                if(grid[n-1][0]==diff || grid[n-1][r-1]==diff)return true;
            }
           }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {

        if(helper(grid))return true;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>v(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[j][i]=grid[i][j];
            }
        }
        return helper(v);
    }
};