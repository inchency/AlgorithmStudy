// https://programmers.co.kr/learn/courses/30/lessons/43162?language=cpp

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool>visited(n, false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            answer++;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int cur_node = q.front();
                q.pop();
                for(int next_node=0; next_node<n; next_node++){
                    if(computers[cur_node][next_node] == 1 && !visited[next_node]){
                        visited[next_node] = true;
                        q.push(next_node);
                    }
                }
            }
        }
    }
    return answer;
}
