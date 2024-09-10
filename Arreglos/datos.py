import random
i = 0
f = open("datos.txt", "x")
b = 2 #de que potencia de 10 sera el arreglo ordenado
f.write(str(10**b)+"\n")
while(i <(10**b)):
    a = random.randint(1,100000) #numeros random que lo rellenan
    f.write(str(a)+"\n")
    i+=1
f.close()

ff = open("semiorden.txt", "x")
b = 2 #de que potencia de 10 sera el arreglo semiordenado
ff.write(str(10**b)+"\n")
i = 0
while(i <(10**b)):
    if((i%10) == 0):
        a = random.randint(1,100000) #numeros random que lo rellenan
        ff.write(str(a)+"\n")
    else:
        ff.write(str(i)+"\n")
    i+=1
ff.close()
