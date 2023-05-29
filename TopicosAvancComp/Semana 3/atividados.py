import math
import random

resultado =0
passa = 0
while resultado != 7:
    resultado = int((math.ceil(random.random()*6))+(math.ceil(random.random()*6)))
    print(resultado)
    if resultado == 7 or resultado == 11:
        print('Pass')
        passa += 1
    else:
        print('Errou')