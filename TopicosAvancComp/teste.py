import pyautogui

# Obtém a posição do mouse no canto superior esquerdo do quadrado
print("Posicione o mouse no canto superior esquerdo do quadrado e aguarde 3 segundos...")
pyautogui.sleep(3)  # Espera 3 segundos
top_left = pyautogui.position()
print("Posição do canto superior esquerdo:", top_left)

# Obtém a posição do mouse no canto inferior direito do quadrado
print("Posicione o mouse no canto inferior direito do quadrado e aguarde 3 segundos...")
pyautogui.sleep(3)  # Espera 3 segundos
bottom_right = pyautogui.position()
print("Posição do canto inferior direito:", bottom_right)

# Calcula as coordenadas do quadrado
x = top_left.x
y = top_left.y
width = bottom_right.x - top_left.x
height = bottom_right.y - top_left.y

print("Coordenadas do quadrado:")
print("x:", x)
print("y:", y)
print("width:", width)
print("height:", height)

text = pyautogui.screenshot(region=(x, y, width, height)).text

# Escreve o texto em um arquivo de bloco de notas
filename = 'notepad.txt'
with open(filename, 'w') as file:
    file.write(text)

print(f"Os itens foram salvos em '{filename}'.")
