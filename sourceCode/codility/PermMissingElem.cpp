// https://app.codility.com/programmers/lessons/3-time_complexity/  

#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int solution(vector<int>& A) {
    if(A.empty()) return 1;
    int max = *max_element(A.begin(), A.end()) + 1;
    vector<bool>check(max, false);
    check[0] = true;
    for(int e : A) check[e] = true;
    int answer = -1;
    for(int i=1; i<=max; i++){
        if(!check[i]){
            answer = i;
            break;
        }
    }
    return answer;
}
