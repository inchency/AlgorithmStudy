# https://www.acmicpc.net/problem/17182

import copy
from queue import PriorityQueue
import sys

INF = sys.maxsize
answer = INF

def ploid_washall(N, arr):
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if arr[i][k] + arr[k][j] < arr[i][j]:
                    arr[i][j] = arr[i][k] + arr[k][j]
    return arr

def solve(N, cur_node, cur_dist, visited_cnt, arr, visited):
    global answer
    if N == visited_cnt:
        answer = min(answer, cur_dist)
    for next_node, next_dist in enumerate(arr[cur_node]):
        if not visited[next_node]:
            visited[next_node] = True
            solve(N, next_node, cur_dist + next_dist, visited_cnt + 1, arr, visited)
            visited[next_node] = False

if __name__ == "__main__":
    N, start_node = map(int, input().split(" "))
    arr = [[0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        s = map(int, input().split(" "))
        for j, e in enumerate(s):
            arr[i][j] = e
    arr = ploid_washall(N, arr)
    visited = [False] * N
    visited[start_node] = True
    solve(N, start_node, 0, 1, arr, visited)
    print(answer)
