import random

n = 64 #tamaño n de la matriz 1
m = 64 #tamaño m de la matriz 1
i = 0
j = 0
f = open("matriz.txt", "x")
f.write(str(n)+" ")
f.write(str(m)+"\n")
while(i < n):
    j = 0
    while(j < m):
        a = random.randint(1,100) #se rellena con numeros random entre 1-100
        f.write(str(a)+" ")
        j += 1
    f.write("\n")
    i+=1
f.close()

n = 64 #tamaño n de la matriz 2
m = 64 #tamaño m de la matriz 2
i = 0
j = 0
f = open("matriz2.txt", "x")
f.write(str(n)+" ")
f.write(str(m)+"\n")
while(i < n):
    j = 0
    while(j < m):
        a = random.randint(1,100) #se rellena con numeros random entre 1-100
        f.write(str(a)+" ")
        j += 1
    f.write("\n")
    i+=1
f.close()
f.close()