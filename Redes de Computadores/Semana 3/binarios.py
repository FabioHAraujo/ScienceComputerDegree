numero = int(input('Digite um numero: '))
base = int(input('Digite a base: '))
strr = "1"
while (numero - base) > base:
    multiplo = base * base
    numero = numero - multiplo
    strr += "0"
    print(numero)
    print(strr)
