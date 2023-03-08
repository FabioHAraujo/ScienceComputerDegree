x = 5454545544
epsilon = 0.00000000001
palpites = 0
limiteinferior = 0.0
limitesuperior = x
resposta = (limitesuperior + limiteinferior)/2.0
while abs(resposta**2 - x) >= epsilon:
    print('limite inferior = ' + str(limiteinferior) + ' limite superior = ' + str(limitesuperior) + ' resposta = ' + str(resposta))
    palpites += 1
    if resposta**2 < x:
        limiteinferior = resposta
    else:
        limitesuperior = resposta
    resposta = (limitesuperior + limiteinferior)/2.0
print('Palpites = ' + str(palpites))
print(str(resposta) + ' e proximo a raiz quadrada de ' + str(x))
