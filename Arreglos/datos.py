import random
i = 0
f = open("datos.txt", "x")
b = 4 #de que potencia de 10 sera el arreglo ordenado
c = 10**b
d = int(c/2)
f.write(str(c)+"\n") #c si es potencia de 10, d si es la mitad de eso
while(i <(c)):
    a = random.randint(1,100000) #numeros random que lo rellenan
    f.write(str(a)+"\n")
    i+=1
f.close()

ff = open("semiorden.txt", "x")
b = 4 #de que potencia de 10 sera el arreglo semiordenado
c = 10**b
d = int(c/2)
i = 0
ff.write(str(c)+"\n") #c si es potencia de 10, d si es la mitad de eso
while(i <(c)):
    if((i%10) == 0):
        a = random.randint(1,100000) #numeros random que lo rellenan
        ff.write(str(a)+"\n")
    else:
        ff.write(str(i)+"\n")
    i+=1
ff.close()
