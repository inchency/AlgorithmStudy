# https://programmers.co.kr/learn/courses/30/lessons/62048?language=python3

def gcd(a, b):
    while(b != 0):
        c = a % b;
        a = b;
        b = c;
    
    return a;


def solution(w,h):
    gcd_n = gcd(w, h);
    batch_row = h / gcd_n;
    batch_col = w / gcd_n;
    batch_total_square = batch_row * batch_col;
    batch_del_square = batch_row + batch_col - 1;
    total_batch = h / batch_row;
    total_del_square = batch_del_square * total_batch;
    whole = w * h;
    return whole - total_del_square;
