
resultados = ([('John', 9.2), ('Timoshenko', 9.8), ('Usain', 8.9), ('Ze', 9.5)])
ordenada = sorted(resultados, key=lambda ordenada: ordenada[1])
ouro, prata, bronze = ordenada[:3]
print('A Medalha de',"\033[33m", 'Ouro',"\033[0m", 'vai para:', ouro[0], 'Pelo Tempo de:', ouro[1])
print('A Medalha de',"\033[37m", 'Prata',"\033[0m", 'vai para:', prata[0], 'Pelo Tempo de:', prata[1])
print('A Medalha de',"\033[38;5;130m", 'Bronze',"\033[0m", 'vai para:', bronze[0], 'Pelo Tempo de:', bronze[1])