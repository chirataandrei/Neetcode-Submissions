class Solution {
public:
    struct Task {
        int enqueue, time, idx;
        bool operator<(const Task& other) const {
            if (enqueue == other.enqueue) {
                if (time == other.time) {
                    return idx < other.idx;
                }
                return time < other.time;
            }
            return enqueue < other.enqueue;
        }
        bool operator>(const Task& other) const {
            if (time == other.time) {
                return idx > other.idx;
            }
            return time > other.time;
        }   
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<Task> sorted_tasks;
        int num = tasks.size();
        for (int i = 0; i < num; i++) {
            sorted_tasks.emplace_back(tasks[i][0], tasks[i][1], i);
        }

        sort(sorted_tasks.begin(), sorted_tasks.end());

        priority_queue<Task, vector<Task>, greater<Task>> pq;
        vector<int> res;
        int task_idx = 0, current_time = 0;

        while (task_idx < num || !pq.empty()) {
            if (pq.empty()) {
                current_time = max(current_time, sorted_tasks[task_idx].enqueue);
            }
            while (task_idx < num && sorted_tasks[task_idx].enqueue <= current_time) {
                pq.push(sorted_tasks[task_idx]);
                task_idx++;
            }
            if (!pq.empty()) {
                Task curr = pq.top();
                pq.pop();
                res.push_back(curr.idx);
                current_time += curr.time;
            }
        }
    
        return res;
    }
};