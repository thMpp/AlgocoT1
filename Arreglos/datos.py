import random
i = 0
f = open("aleatorios.txt", "x")
b = 1 #de que potencia de 10 sera el arreglo ordenado
c = 10**b
f.write(str(c)+"\n") 
while(i <(c)):        
    a = random.randint(1,100000) #numeros random que lo rellenan
    f.write(str(a)+"\n")
    i+=1
f.close()

ff = open("semiorden.txt", "x")
b = 1 #de que potencia de 10 sera el arreglo semiordenado
c = 10**b
i = 0
ff.write(str(c)+"\n") 
while(i <(c)):       
    if((i%10) == 0):
        a = random.randint(1,100000) #numeros random que lo rellenan
        ff.write(str(a)+"\n")
    else:
        ff.write(str(i)+"\n")
    i+=1
ff.close()

fff = open("orden.txt", "x")
b = 6 #de que potencia de 10 sera el arreglo ordenado
c = 10**b
i = 0 
fff.write(str(c)+"\n")
while(i < c):        
    fff.write(str(i)+"\n")
    i+=1
fff.close()
