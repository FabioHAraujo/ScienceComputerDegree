def classifica(lista):
    # Ordena a lista pelo tempo em ordem crescente
    lista_ordenada = sorted(lista, key=lambda x: x[1])

    # Seleciona os três primeiros atletas da lista ordenada
    ouro, prata, bronze = lista_ordenada[:3]

    # Monta a mensagem de saída
    mensagem = f"Ouro: {ouro[0]} - Tempo: {ouro[1]}\n" \
               f"Prata: {prata[0]} - Tempo: {prata[1]}\n" \
               f"Bronze: {bronze[0]} - Tempo: {bronze[1]}"

    # Retorna a mensagem de saída
    return mensagem
resultado = classifica([('John', 9.2), ('Timoshenko', 9.8), ('Usain', 8.9), ('Ze', 9.5)])
print(resultado)
