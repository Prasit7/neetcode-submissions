class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) 
    {
        int n = intervals.size(), q = queries.size();
        // sort intervals by left endpoint
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b){ return a[0] < b[0]; });

        // pair queries with original indices and sort by query value
        vector<pair<int,int>> Q(q);
        for(int i = 0; i < q; ++i)
            Q[i] = {queries[i], i};
        sort(Q.begin(), Q.end());

        // min-heap of {length, right}, so smallest length is on top
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> heap;

        vector<int> ans(q);
        int i = 0;  // pointer into intervals

        // process queries in ascending order
        for(auto &qi : Q) {
            int x = qi.first, idx = qi.second;

            // add all intervals whose left <= x
            while(i < n && intervals[i][0] <= x) {
                int L = intervals[i][0];
                int R = intervals[i][1];
                heap.emplace(R - L + 1, R);
                ++i;
            }

            // drop intervals that end before x
            while(!heap.empty() && heap.top().second < x)
                heap.pop();

            // answer for this query
            ans[idx] = heap.empty() ? -1 : heap.top().first;
        }

        return ans;
    }
};
