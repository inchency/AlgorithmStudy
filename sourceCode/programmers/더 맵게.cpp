// https://school.programmers.co.kr/learn/courses/9899
// https://school.programmers.co.kr/learn/courses/9899/lessons/55833?language=cpp

#include <string>
#include <vector>
#include <climits>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct comp {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }

};
int solution(vector<int> scoville, int K) {
    int answer = 0;
    bool flag = true;
    for (int e : scoville) {
        if (e < K) {
            flag = false;
            break;
        }
    }
    if (flag) return answer;

    priority_queue<int, vector<int>, comp>pq;
    for (int e : scoville)
        pq.push(e);
    while (!pq.empty()) {
        answer++;
        int min1 = pq.top();
        pq.pop();
        if(pq.empty()) break;
        int min2 = pq.top();
        pq.pop();
        int new_score = min1 + (min2 * 2);
        pq.push(new_score);
        if (pq.top() >= K){
            flag = true;
            break;
        }
    }
    if(!flag) answer = -1;
    return answer;
}
