# 2. cmp_to_key 쓸 때

from functools import cmp_to_key

class Person:
    def __init__(self, name, age, country):
        self.name = name
        self.age = age
        self.country = country

# country 순으로 내림차순 정렬, 같을 때 age 순으로 오름차순 정렬
def compare(left, right):
    if left.country > right.country:
        return -1
    elif left.country < right.country:
        return 1
    else:
        if left.age < right.age:
            return -1
        else:
            return 1

if __name__ == "__main__":
    person1 = Person(name="jack", age=10, country="aaa")
    person2 = Person(name="pig", age=15, country="aba")
    person3 = Person(name="bird", age=5, country="bac")
    person4 = Person(name="dog", age=20, country="zab")
    person5 = Person(name="dog", age=20, country="aaa")

    l = [person1, person2, person3, person4, person5]
    l.sort(key=cmp_to_key(compare))
    for p in l:
        print(p.name, p.age, p.country)

"""
output
------------------------------------------------------------------------------
dog 20 zab
bird 5 bac
pig 15 aba
jack 10 aaa
dog 20 aaa
"""
