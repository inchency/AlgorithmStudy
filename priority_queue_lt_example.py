# 1. priority queue 쓸때 자동 소팅

from queue import PriorityQueue

class Person:
    def __init__(self, name, age, country):
        self.name = name
        self.age = age
        self.country = country
    
    # country 순으로 내림차순 정렬, 같을 때 age 순으로 오름차순 정렬
    def __lt__(self, other):
        if self.country > other.country:
            return True
        elif self.country < other.country:
            return False
        else:
            if self.age < other.age:
                return True
            else:
                return False

if __name__ == "__main__":
    person1 = Person(name="jack", age=10, country="aaa")
    person2 = Person(name="pig", age=15, country="aba")
    person3 = Person(name="bird", age=5, country="bac")
    person4 = Person(name="dog", age=20, country="zab")
    person5 = Person(name="dog", age=20, country="aaa")

    pq = PriorityQueue()
    pq.put(person1)
    pq.put(person2)
    pq.put(person3)
    pq.put(person4)
    pq.put(person5)

    while not pq.empty():
        p = pq.get()
        print(p.name, p.age, p.country)

"""
output
--------------------------------------

dog 20 zab
bird 5 bac
pig 15 aba
jack 10 aaa
dog 20 aaa
"""
