#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

int find_root(vector<int>& parent_v, int node) {
    if (parent_v[node] == node)
        return node;
    else {
        parent_v[node] = find_root(parent_v, parent_v[node]);
        return parent_v[node];
    }
}

void do_union(vector<int>& parent_v, vector<int>& rank_v, int start, int dest) {
    int start_root = find_root(parent_v, start);
    int dest_root = find_root(parent_v, dest);
    if (rank_v[start_root] > rank_v[dest_root]) {
        parent_v[dest_root] = start_root;
    }
    else if (rank_v[start_root] < rank_v[dest_root]) {
        parent_v[start_root] = dest_root;
    }
    else {
        rank_v[start_root] += 1;
        parent_v[dest_root] = start_root;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), comp);
    // √ ±‚»≠
    vector<int>parent_v(n);
    for (int i = 0; i < n; i++) parent_v[i] = i;
    vector<int>rank_v(n, 0);

    for (auto e : costs) {
        int start = e[0];
        int dest = e[1];
        int start_root = find_root(parent_v, start);
        int dest_root = find_root(parent_v, dest);
        if (start_root != dest_root) {
            do_union(parent_v, rank_v, start, dest);
            answer += e[2];
        }
    }
    cout << answer;
    return answer;
}