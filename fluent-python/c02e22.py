import numpy as np
from random import random
from array import array
from time import perf_counter as pc

a = np.arange(12)
print(a)
type(a)
print(a.shape)
a.shape = 3, 4
print(a)
print(a[2])
print(a[2, 1])
print(a[:, 1])
print(a.transpose())

floats = array('d', (random() for i in range(10**7)))
np.save('floats-10M', floats)
floats = np.load('floats-10M.npy')
print(floats[-3:])
floats *= .5
print(floats[-3:])
t0 = pc()
floats /= 3
print(pc() - t0)
np.save('floats-10M', floats)
floats2 = np.load('floats-10M.npy', 'r+')
floats2 *= 6
print(floats2[-3:])
