// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

void dsp(int s, int cur_ind, vector<int> &numbers, int target, int &answer, int numbers_len){
    if(cur_ind >= numbers_len){
        if(s == target)
            answer++;
        return;
    }
    dsp(s + numbers[cur_ind], cur_ind + 1, numbers, target, answer, numbers_len);
    dsp(s - numbers[cur_ind], cur_ind + 1, numbers, target, answer, numbers_len);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dsp(0, 0, numbers, target, answer, numbers.size());
    return answer;
}
