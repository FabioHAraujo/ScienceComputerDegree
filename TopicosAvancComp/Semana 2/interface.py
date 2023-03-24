import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QTextEdit
from io import StringIO



resultados = ([('John', 9.2), ('Timoshenko', 9.8), ('Usain', 8.9), ('Ze', 9.5)])
ordenada = sorted(resultados, key=lambda ordenada: ordenada[1])
ouro, prata, bronze = ordenada[:3]
class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # Cria um widget de texto para exibir a saída
        self.text_edit = QTextEdit(self)
        self.text_edit.setReadOnly(True)
        self.setCentralWidget(self.text_edit)

        # Cria um buffer de saída para redirecionar a saída padrão
        self.buffer = StringIO()

        # Redireciona a saída padrão para o buffer de saída
        sys.stdout = self.buffer

        # Exibe a saída usando o comando print
        print('A Medalha de Ouro vai para:', ouro[0], 'Pelo Tempo de:', ouro[1],'segundos')
        print('A Medalha de Prata vai para:', prata[0], 'Pelo Tempo de:', prata[1],'segundos')
        print('A Medalha de Bronze vai para:', bronze[0], 'Pelo Tempo de:', bronze[1],'segundos')

        # Copia o conteúdo do buffer de saída para o widget de texto
        self.text_edit.setText(self.buffer.getvalue())

        # Restaura a saída padrão original
        sys.stdout = sys.__stdout__

if __name__ == '__main__':
    app = QApplication(sys.argv)
    main_window = MainWindow()
    main_window.show()
    sys.exit(app.exec_())
