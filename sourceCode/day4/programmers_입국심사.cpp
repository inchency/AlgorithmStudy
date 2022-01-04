#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long right = *(max_element(times.begin(), times.end())) * (long long)n;
    long long left = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long temp = 0;
        for (auto e : times) {
            temp += mid / e;
        }
        if (temp >= n) right = mid - 1;
        else left = mid + 1;
    }
    answer = right + 1;
    return answer;
}