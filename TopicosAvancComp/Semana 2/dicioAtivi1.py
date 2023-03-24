texto = "Proerd, é o programa, proerd, é solução, lutando contra as drogas, ensinando a dizer não!"
contagem = {}

for letra in texto:
    if letra in contagem:
        contagem[letra] += 1
    else:
        contagem[letra] = 1

for letra in contagem:
    print(letra,contagem[letra])

print(contagem)