# https://www.acmicpc.net/problem/2292

def bn(n):
    return 6 * n

def solve(target_num):
    if target_num == 1:
        return 1
    s = 1
    i = 1
    while True:
        an = bn(i)
        s += an
        i += 1
        # print(i, an, s)
        if s >= target_num:
            return i


if __name__ == '__main__':
    target_num = int(input())
    print(solve(target_num))

