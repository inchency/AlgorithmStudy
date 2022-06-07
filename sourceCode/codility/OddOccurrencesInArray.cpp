//https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/start/

#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int>& A) {
    unordered_map<int, int>m; // index, cnt
    for (int e : A) {
        if (m.find(e) == m.end()) {
            m[e] = 1;
        }
        else {
            m[e] += 1;
        }
    }
    int answer = -1;
    for (pair<int, int>p : m) {
        if (p.second % 2 == 1) {
            answer = p.first;
            return answer;
        }
    }
    return answer;
}
