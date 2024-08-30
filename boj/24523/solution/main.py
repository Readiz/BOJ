import random
print(1000000)
ret = ''
for _ in range(1000000):
    ret += str(random.randint(-1000000000,1000000000)) + ' '
print(ret)
