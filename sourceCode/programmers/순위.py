# https://programmers.co.kr/learn/courses/30/lessons/49191?language=python3#

from queue import Queue

def solution(n, results):
    answer = 0
    win_dic = dict()
    lose_dic = dict()
    
    # make graph
    for result in results:
        win_num = result[0]
        lose_num = result[1]
        if win_num not in win_dic:
            win_dic[win_num] = [lose_num]
        else:
            win_dic[win_num].append(lose_num)
        if lose_num not in lose_dic:
            lose_dic[lose_num] = [win_num]
        else:
            lose_dic[lose_num].append(win_num)
    for i in range(1, n+1, 1):
        if bfs(win_dic, i) + bfs(lose_dic, i) == n-1:
            answer += 1
    return answer

def bfs(dic, start_node):
    queue = Queue()
    queue.put((start_node, 0))
    visited = set()
    visited.add(start_node)
    cnt = 0
    while queue.qsize() >= 1:
        top = queue.get()
        cur_node = top[0]
        cur_cnt = top[1]
        print(cur_node, cur_cnt)
        if cur_node in dic:
            for next_node in dic[cur_node]:
                if next_node not in visited:
                    visited.add(next_node)
                    cnt += 1
                    queue.put((next_node, cnt))
    return cnt
