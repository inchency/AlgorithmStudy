// https://app.codility.com/programmers/lessons/2-arrays/

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    if(A.size() == 0) return A;
    for(int i=0; i<K; i++){
        int last = *(A.end() - 1);
        A.pop_back();
        A.insert(A.begin(), last);
    }
    return A;
}
