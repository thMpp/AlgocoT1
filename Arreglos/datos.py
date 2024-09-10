import random
i = 0
f = open("datos.txt", "x")
b = 5
f.write(str(10**b)+"\n")
while(i <(10**b)):
    a = random.randint(1,100000)
    f.write(str(a)+"\n")
    i+=1
f.close()

ff = open("semiorden.txt", "x")
b = 5
ff.write(str(10**b)+"\n")
i = 0
while(i <(10**b)):
    if((i%10) == 0):
        a = random.randint(1,100000)
        ff.write(str(a)+"\n")
    else:
        ff.write(str(i)+"\n")
    i+=1
ff.close()
