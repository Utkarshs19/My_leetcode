class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {

        if(source==target)return 0;
        if(abs(target[0]-source[0]) == abs(target[1]-source[1]))return 1;
        if(target[0]==source[0])return 1;
        if(target[1]==source[1])return 1;
        return 2;
        
    }
};