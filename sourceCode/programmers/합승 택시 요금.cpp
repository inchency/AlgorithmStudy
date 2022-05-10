// https://programmers.co.kr/learn/courses/30/lessons/72413

#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

vector<int> ret_dist(int n, int node, vector<vector<pair<int, int>>>new_fares) {
    vector<int>dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    pq.push({ node, 0 });
    dist[node] = 0;
    while (!pq.empty()) {
        int cur_node = pq.top().first;
        int cur_cost = pq.top().second;
        pq.pop();
        for (auto e : new_fares[cur_node]) {
            int next_node = e.first;
            int next_cost = e.second;
            int total_cost = cur_cost + next_cost;
            if (total_cost < dist[next_node]) {
                dist[next_node] = total_cost;
                pq.push({ next_node, total_cost });
            }
        }
    }
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    vector<vector<pair<int, int>>>new_fares(n + 1);
    for (auto e : fares) {
        int start = e[0];
        int dest = e[1];
        int cost = e[2];
        new_fares[start].push_back({ dest, cost });
        new_fares[dest].push_back({ start, cost });
    }
    vector<int>s_dist = ret_dist(n, s, new_fares);
    vector<int>a_dist = ret_dist(n, a, new_fares);
    vector<int>b_dist = ret_dist(n, b, new_fares);

    for (int i = 1; i <= n; i++) {
        int temp = s_dist[i] + a_dist[i] + b_dist[i];
        answer = min(answer, temp);
    }

    return answer;
}
