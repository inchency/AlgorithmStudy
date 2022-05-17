// https://programmers.co.kr/learn/courses/30/lessons/42626?language=cpp#

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct comp{
  bool operator()(const int &left, const int &right){
      return left > right;
  }  
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, comp>pq;
    for(int each : scoville)
        pq.push(each);
    bool answer_flag = false;
    while(!pq.empty()){
        int first = pq.top();
        pq.pop();
        if(first >= K){
            answer_flag = true;
            return answer;
        }
        if(pq.size() == 0)
            return -1;
        int second = pq.top();
        pq.pop();
        answer++;
        int make = first + second * 2;
        pq.push(make);
    }
    if(!answer_flag)
        return -1;
    return answer;
}
