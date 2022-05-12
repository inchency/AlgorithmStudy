// https://programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct comp{
  bool operator()(const pair<int, int> &a, const pair<int, int> &b){
      return a.second > b.second;
  }  
};


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>>v(n+1);
    for(vector<int> e : edge){
        int start_node = e[0];
        int dest_node = e[1];
        v[start_node].push_back(dest_node);
        v[dest_node].push_back(start_node);
    }
    vector<int>dist(n+1, INT_MAX);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp>pq;
    pq.push({1, 0});
    while(!pq.empty()){
        int cur_node = pq.top().first;
        int cur_cost = pq.top().second;
        pq.pop();
        for(int next_node : v[cur_node]){
            int next_cost = cur_cost + 1;
            if(dist[next_node] > next_cost){
                dist[next_node] = next_cost;
                pq.push({next_node, next_cost});
            }
        }
    }
    int max_num = 0;
    for(int i=1; i<=n; i++) max_num = max(max_num, dist[i]);
    for(int i=1; i<=n; i++) if(max_num == dist[i]) answer++;
    return answer;
}
