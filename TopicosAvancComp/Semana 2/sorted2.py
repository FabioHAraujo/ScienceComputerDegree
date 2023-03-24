#Esse foi feito pelo professor
def classifica(lista):
    ouro = ('ouro', 200)
    prata = ('prata', 210)
    bronze = ('bronze', 220)
    for i in lista:
        if i[1] < ouro[1]:
            bronze = prata
            prata = ouro
            ouro = i
        elif i[1] < prata[1]:
            bronze = prata
            prata = i
        elif i[1] < bronze[1]:
            bronze = i
    return (ouro, prata, bronze)
resp = classifica([('John', 9.2), ('Timoshenko', 9.8), ('Usain', 8.9), ('Ze', 9.5)])
print(resp)