a = input("Por favor, digite um numero: ")
if a
b = input("Por favor, digite outro numero: ")

print("Por favor, escolha a operação que deseja fazer: ")

oper = input("Soma '+', multiplicação '*', divisão '/', subtração '-': ")

if '+' in oper:
    print(f'O resultado é: {int(a)+int(b)}')
elif '*' in oper:
    print(f'O resultado é: {int(a)*int(b)}')
elif '-' in oper:
    print(f'O resultado é: {int(a)-int(b)}')
elif '/' in oper:
    print(f'O resultado é: {int(a)/int(b)}')
else:
    print("Você não digitou um operador corretamente. Encerrando programa!")