#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int s, d, t;
    bool operator==(const Packet &o) const {
        return s==o.s && d==o.d && t==o.t;
    }
};

// custom hash for Packet
struct PacketHash {
    size_t operator()(const Packet &p) const {
        return ((size_t)p.s * 1315423911u) ^ ((size_t)p.d * 2654435761u) ^ (size_t)p.t;
    }
};

class Router {
public:
    queue<Packet> q;
    unordered_set<Packet, PacketHash> st;  
    unordered_map<int, vector<int>> mp;    // dest -> sorted timestamps
    int maxLimit;

    Router(int memoryLimit) {
        maxLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        if (st.find(p) != st.end()) return false;

        if (q.size() == maxLimit) {
            Packet old = q.front();
            q.pop();
            st.erase(old);

            auto &vec = mp[old.d];
            auto it = lower_bound(vec.begin(), vec.end(), old.t);
            if (it != vec.end() && *it == old.t) vec.erase(it);
        }

        st.insert(p);
        q.push(p);

        auto &vec = mp[destination];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(it, timestamp); // keeps sorted
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};

        Packet p = q.front();
        q.pop();
        st.erase(p);

        auto &vec = mp[p.d];
        auto it = lower_bound(vec.begin(), vec.end(), p.t);
        if (it != vec.end() && *it == p.t) vec.erase(it);

        return {p.s, p.d, p.t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &vec = mp[destination];
        int l = lower_bound(vec.begin(), vec.end(), startTime) - vec.begin();
        int r = upper_bound(vec.begin(), vec.end(), endTime) - vec.begin();
        return r - l;
    }
};
