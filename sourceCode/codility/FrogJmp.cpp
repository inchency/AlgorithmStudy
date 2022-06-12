// https://app.codility.com/programmers/lessons/3-time_complexity/
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    int cha = Y - X;
    int answer = cha / D;
    if(Y != X && cha % D != 0) answer++;
    return answer;
}
