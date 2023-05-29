num=42
tentativa=0
while tentativa != num:
    tentativa = int(input('Qual o numero? '))
    if tentativa < num:
        print('Muito baixo')
    elif tentativa > num:
        print('Muito alto')
    else:
        print('Acertou')