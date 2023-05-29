numero = int(input('Digite um número: '))
base = int(input('Digite a base: '))

strr = ''
while numero >= base:
    resto = numero % base
    strr = str(resto) + strr
    numero = numero // base

strr = str(numero) + strr

print(strr)
