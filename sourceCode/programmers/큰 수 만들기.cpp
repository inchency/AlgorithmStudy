// part 4
// https://school.programmers.co.kr/learn/courses/9899
// https://school.programmers.co.kr/learn/courses/9899/lessons/55829?language=cpp

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm> 

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char>st;
    for (char c : number) {
        if (st.empty())
            st.push(c);
        else {
            while (!st.empty() && st.top() - '0' < c - '0' && k > 0) {
                st.pop();
                k--;
            }
            st.push(c);
        }
    }
    while (k > 0) {
        st.pop();
        k--;
    }
    while (!st.empty()) {
        answer.push_back(st.top());
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
