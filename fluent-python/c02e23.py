from collections import deque

dq = deque(range(10), maxlen=10)
print(dq, id(dq))
dq.rotate(3)
print(dq, id(dq))
dq.rotate(-4)
print(dq, id(dq))
dq.appendleft(-1)
print(dq, id(dq))
dq.extend([11, 22, 33])
print(dq, id(dq))
dq.extendleft([10, 20, 30, 40])
print(dq, id(dq))
