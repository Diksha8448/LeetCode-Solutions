/*
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
*/
class Solution {
public:
    int d(vector<int> a)
    {return a[0]*a[0]+a[1]*a[1];}
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> pq;
        int p=0;
        for(auto v: points)
        {
            if(pq.size()<K)
                pq.push({d(v),p});
            else if(d(v)<pq.top().first)
            {pq.pop();pq.push({d(v),p});}
               p++;
        }
        while(pq.size())
        {ans.push_back(points[pq.top().second]);pq.pop();}
        return ans;
    }
};