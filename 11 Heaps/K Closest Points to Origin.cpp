// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).


class Solution {
public:
    class mycomp{
        public:
        bool operator()(pair<int,int>&a, pair<int,int>&b){
            int distA = a.first*a.first + a.second*a.second;
            int distB = b.first*b.first + b.second*b.second;
            return distA > distB;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycomp>pq;
        //min heap based priority queue, giving more priority to the point closer to origin

        for(auto p:points){
            pq.push({p[0], p[1]});
        }
        while(!pq.empty() && k--){
            auto&top = pq.top();
            ans.push_back({top.first, top.second});
            pq.pop();
        }
        return ans;
    }
};