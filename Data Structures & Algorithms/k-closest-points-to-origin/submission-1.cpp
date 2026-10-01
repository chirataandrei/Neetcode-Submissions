class Solution {
public:
    struct Point {
        int x, y;
        int dist;
        bool operator<(const Point& other) const {
            return dist < other.dist;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, less<Point>> pq;
        int num = points.size();
        vector<vector<int>> res;

        for (int i = 0; i < k; i++) {
            int x = points[i][0], y = points[i][1];
            pq.push({x, y, x * x + y * y});
        }
        
        for (int i = k; i < num; i++) {
            int x = points[i][0], y = points[i][1];
            int curr_dist = x * x + y * y;
            if (curr_dist < pq.top().dist) {
                pq.pop();
                pq.push({x, y, curr_dist});
            }
        }

        for (int i = 0; i < k; i++) {
            Point curr = pq.top();
            pq.pop();
            res.push_back({curr.x, curr.y});
        }

        return res;
    }
};
