class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        char dir = 'N';
        int ans = 0;
        set<pair<int, int>> s;

        for (auto& o : obstacles)
            s.insert({o[0], o[1]});

        int x = 0, y = 0;

        for (int cmd : commands) {
            if (cmd == -1) { // turn right
                if (dir == 'N') dir = 'E';
                else if (dir == 'E') dir = 'S';
                else if (dir == 'S') dir = 'W';
                else dir = 'N';
            }
            else if (cmd == -2) { // turn left
                if (dir == 'N') dir = 'W';
                else if (dir == 'W') dir = 'S';
                else if (dir == 'S') dir = 'E';
                else dir = 'N';
            }
            else {
                for (int step = 0; step < cmd; ++step) {
                    int nx = x, ny = y;
                    if (dir == 'N') ny++;
                    else if (dir == 'S') ny--;
                    else if (dir == 'E') nx++;
                    else nx--;

                    if (s.find({nx, ny}) != s.end()) break; // obstacle found

                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};
