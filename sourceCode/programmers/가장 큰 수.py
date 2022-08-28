# https://school.programmers.co.kr/learn/courses/9899/
# https://school.programmers.co.kr/learn/courses/9899/lessons/55825?language=python3

from functools import cmp_to_key

def comp(left, right):
    if left + right > right + left:
        return -1
    else:
        return 1
        
            

def solution(numbers):
    answer = ''
    numbers_str_list = []
    for num in numbers:
        numbers_str_list.append(str(num))
    numbers_str_list.sort(key=cmp_to_key(comp))
    for e in numbers_str_list:
        answer += e
    if answer[0] == '0':
        return "0"
    return answer
