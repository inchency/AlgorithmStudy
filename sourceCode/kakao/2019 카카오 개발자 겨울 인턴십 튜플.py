def solution(s):
    answer = []
    new_s = s.replace("{{", "{").replace("}}", "}").replace("},{", "}_{")
    split_s = new_s.split("_")
    temp_list = []
    for e_s in split_s:
        e_list = e_s.replace("{", "").replace("}", "").split(",")
        temp_list.append(e_list)
    list_size = len(temp_list)
    cur_cnt = 1
    while(len(answer) != list_size):
        for e_l in temp_list:
            if(cur_cnt == len(e_l)):
                complement = list(set(e_l) - set(answer))
                answer.append(complement[0])
                cur_cnt += 1
    for i, num in enumerate(answer):
        answer[i] = int(num)
    return answer
