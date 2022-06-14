// https://app.codility.com/programmers/lessons/5-prefix_sums/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;
    int cur_zero_cnt = 0;
    for(int n : A){
        if(n == 0) cur_zero_cnt++;
        else{
            answer += cur_zero_cnt;
            if(answer > 1000000000) return -1;
        }
    }
    return answer;
}
