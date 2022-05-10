// https://programmers.co.kr/learn/courses/30/lessons/12978

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<vector<pair<int, int>>>new_road(N + 1);
    for (vector<int> e : road) {
        int start = e[0];
        int dest = e[1];
        int cost = e[2];
        new_road[start].push_back({ dest, cost });
        new_road[dest].push_back({ start, cost });
    }
    vector<int>dist(N + 1, INT_MAX);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp>pq;
    pq.push(make_pair(1, 0));
    while (!pq.empty()) {
        int cur_node = pq.top().first;
        int cur_cost = pq.top().second;
        pq.pop();
        for (pair<int, int> p : new_road[cur_node]) {
            int next_node = p.first;
            int next_cost = p.second;
            if (dist[next_node] > cur_cost + next_cost) {
                dist[next_node] = cur_cost + next_cost;
                pq.push({ next_node, cur_cost + next_cost});
            }
        }
    }
    for(int i=1; i<= N; i++){
        cout << dist[i] << " ";
        if(dist[i] <= K) answer++;
    }
    return answer;
}
