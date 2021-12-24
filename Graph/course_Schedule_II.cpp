#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Graph coloring : 0 -> not visited 1 -> visited , 2 -> visited and processed
    bool detectCycle_util(vector<vector<int>> &adj, vector<int> &visited, int vertex)
    {
        if (visited[vertex] == 1)
            return true;
        if (visited[vertex] == 2)
            return false;

        visited[vertex] = 1; // mark current as visited
        for (int i = 0; i < adj[vertex].size(); i++)
        {
            if (detectCycle_util(adj, visited, adj[vertex][i]))
                return true;
        }

        visited[vertex] = 2; // mark as processed
        return false;
    }
    // cycle detection

    bool detectCycle(vector<vector<int>> &adj, int n)
    {
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
            if (!visited[i])
                if (detectCycle_util(adj, visited, i))
                    return true;
        return false;
    }

    //topoligical sort
    void dfs(vector<vector<int>> &adj, int vertex, vector<bool> &visited, stack<int> &st)
    {
        visited[vertex] = true;
        for (int i = 0; i < adj[vertex].size(); i++)
        {
            if (!visited[adj[vertex][i]])
                dfs(adj, adj[vertex][i], visited, st);
        }
        st.push(vertex);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prereq)
    {
        int n = prereq.size();
        vector<vector<int>> adj(numCourses);
        // make adjancecncy list

        for (int i = 0; i < n; i++)
        {
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }

        // Detect cycle If present then return empty array

        vector<int> ans;
        if (detectCycle(adj, numCourses))
            return ans;

        // Find toposort and store it int stack
        stack<int> st;
        vector<bool> visited(numCourses, false);

        // apply DFS and find topological sort
        for (int i = 0; i < numCourses; ++i)
        {
            if (!visited[i])
                dfs(adj, i, visited, st);
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
int main()
{

    return 0;
}