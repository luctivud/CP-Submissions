from collections import deque
from collections import defaultdict
import typing

S:str = input()
N:int = int(input())
assert 0 < len(S) < 11
interactions: dict = defaultdict(list)
totalPeopleInTown = set()
for _ in range(N):
    a, b = input().split()
    totalPeopleInTown.update(set([a, b]))
    assert 0 < len(a) < 11
    assert 0 < len(b) < 11
    interactions[a].append(b)
    interactions[b].append(a)
queue:list = deque()
infected: set = set()
queue.append(S)
infected.add(S)
while len(queue):
    suspect = queue.popleft()
    personsInteracted = interactions[suspect]
    for person in personsInteracted:
        if person not in infected:
            infected.add(person)
            queue.append(person)
assert(len(infected) <= len(totalPeopleInTown))
print(len(infected))
