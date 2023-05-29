texto = "lorem ipsum dolor sit amet, consectetur adipiscing elit. sed non risus. "
texto2 = "suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. "

lista = texto.split()
lista2 = texto2.split()

dicio = {}
dicio2 = {}

for i in lista:
    if i in dicio:
        dicio[i] += 1
    else:
        dicio[i] = 1

for i in lista2:
    if i in dicio:
        dicio2[i] = 1
        print(i, ' = ', dicio2[i])
