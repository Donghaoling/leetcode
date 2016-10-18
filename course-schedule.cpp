class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, int> Indegree;
        map<int, vector<int>> neighbors;
        for(int i = 0;i < numCourses; i ++) {
            Indegree[i] = 0;
        }
        for(auto it = prerequisites.begin(); it != prerequisites.end(); it ++) {
            Indegree[it->first] ++;
            if(neighbors.find(it->second) == neighbors.end()) {
                vector<int> temp;
                temp.push_back(it->first);
                neighbors[it->second] = temp;
            }
            else {
                neighbors[it->second].push_back(it->first);
            }
        }
        int num = 0;
        queue<int> q;
        for(auto it = Indegree.begin(); it != Indegree.end(); it ++) {
            if(it->second == 0) {
                q.push(it->first);
            }
        }
        vector<int> result;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            num ++;
            for(auto it = neighbors[node].begin(); it != neighbors[node].end(); it++) {
                Indegree[*it] --;
                if(Indegree[*it] == 0) {
                    q.push(*it);
                }
            }
        }
        vector<int> temp;
        if(num == numCourses) {
            return result;
        }
        else {
            return temp;
        }
    }
};
