class Solution {
public:
    string foreignDictionary(vector<string>& words)
    {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegree;

        // Initialize graph
        for (const string& word : words) {
            for (char c : word) {
                graph[c];
                inDegree[c] = 0;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; ++i) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            int len = min(w1.size(), w2.size());

            if (w1.substr(0, len) == w2.substr(0, len) && w1.size() > w2.size())
                return "";  // invalid case

            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    if (graph[w1[j]].insert(w2[j]).second)
                        inDegree[w2[j]]++;
                    break;
                }
            }
        }

        // Topological Sort (BFS)
        queue<char> q;
        for (auto& [ch, deg] : inDegree)
            if (deg == 0) q.push(ch);

        string result;
        while (!q.empty()) {
            char curr = q.front(); q.pop();
            result += curr;
            for (char next : graph[curr]) {
                if (--inDegree[next] == 0)
                    q.push(next);
            }
        }

        return result.size() == graph.size() ? result : "";
    }
};
