class TaskManager {
public:

    map<int,int> m1;
    map<int,int> m2;
    priority_queue<pair<int,int>> pq;

    TaskManager(vector<vector<int>>& tasks) {

        for(int i=0;i<tasks.size();i++)
        {
            pq.push({tasks[i][2],tasks[i][1]});
            m1[tasks[i][1]]=tasks[i][2];
            m2[tasks[i][1]]=tasks[i][0];
        }
        
    }
    
    void add(int userId, int taskId, int priority) {

        pq.push({priority,taskId});
        m1[taskId]=priority;
        m2[taskId]=userId;
        
    }
    
    void edit(int taskId, int newPriority) {
        
        pq.push({newPriority,taskId});

        m1[taskId]=newPriority;

    }
    
    void rmv(int taskId) {
        m1[taskId]=-1;
    }
    
    int execTop() {

        while(!pq.empty())
        {
            const auto t=pq.top();
            pq.pop();

            if(t.first==m1[t.second])
            {
                m1[t.second]=-1;
                return m2[t.second];
            }
        }

        return -1;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */