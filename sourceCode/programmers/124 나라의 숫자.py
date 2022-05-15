# https://programmers.co.kr/learn/courses/30/lessons/12899#

def solution(n):
    answer = ''
    num_list = ["4", "1", "2"]
    while n > 0:
        mod_num = int(n % 3)
        add_str = num_list[mod_num]
        answer = add_str + answer
        if n % 3 == 0:
            n = n - 1
        n = n // 3
    return answer
