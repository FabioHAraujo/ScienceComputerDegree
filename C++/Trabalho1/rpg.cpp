#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

#define NC "\e[0m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define RED "\e[0;31m"
#define YELLOW "\e[0;33m"

using namespace std;

struct personagem
{
    //info do personagem
    int idade;
    string nome, classe;
    //poderes
    int forca, destreza, velocidade, vitalidade, inteligencia;
};


int main()
{

    personagem status;
    cout << CYAN << "Bem vindo, caro mancebo, ao meu reino! Imagino que goste de jogos, nao?" << RED << " HAHAHAHA! " << CYAN << "NA VERDADE, SUA RESPOSTA EH IRRELEVANTE, DIVIRTA-SE!!!.\n";
    cout << GREEN << "Por favor, me diga uma coisa, qual seu nome?\n" << NC;
    cout << "Er... Eu me chamo ";
    cin >> status.nome;
    cout << "meu caro senhor.\n";
    cin >> status.classe;
    cout << status.classe << endl;
    cout << status.nome;

    cout << (rand() % 20 + 1) << endl;

return 0;
}