//https://app.codility.com/programmers/lessons/5-prefix_sums/

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int min_num = min(A / K, B / K);
    int max_num = max(A / K, B / K);
    int min_AB = min(A, B);
    if(min_AB % K == 0){
        return max_num - min_num + 1;
    }
    else return max_num - min_num;
}
