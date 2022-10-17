#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <windows.h>
//Definições de cores com base na documentação C++ da própria microsoft, todo o conteudo e os defines estão dentro do meu arquivo de cabeçalho.

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
    // Usarei do Handle da biblioteca windows.h para auxiliar na visualização das etapas do jogo e sentimentos dos personagens.
    HANDLE  pintarTexto;
	    int cor=7;
    pintarTexto = GetStdHandle(STD_OUTPUT_HANDLE);

    personagem status;

    SetConsoleTextAttribute(pintarTexto, cor);
    int auxiliar;
    cout << "Bem vindo, caro jogador, a um rapido mundo de fatasia, por ele, encontrara tres bosses, os quais devem ser enfrentados com bravura e valentia, durante o caminho, derrote inimigos e faca seu nome ser ouvido\n";
    cor = 2;
    SetConsoleTextAttribute(pintarTexto, cor);
    cout << "Por favor, me diga uma coisa, qual seu nome?\n";
    cout << "Eu me chamo > ";
    cin >> status.nome;
    cout << "SEJA MUITO BEM VINDO " << status.nome << endl;
    cout << "Agora, antes de mais nada, o que voce eh afinal? Um Humano, Elfo, Druida ou Anao? Parece ate uma geleia... E ate onde me lembro, ha apenas essas 4 racas no mundo...\n";
    cin >> status.classe;
    //infelizmente não consegui realizar switch case com strings, mas ainda vou conseguir, por ora, sorrie e acene com esse if gigante.
    if (status.classe == "humano" || status.classe == "Humano")
    {
        cout << "Humano, ata, agora vejo sua forma com mais clareza..." << endl;
        auxiliar = 1;
    }
    else if (status.classe == "elfo" || status.classe == "Elfo")
    {
        cout << "A famosa raca de guerreiros, guardioes das grandes florestas. Consigo identificar sua forma agora" << endl;
        auxiliar = 2;
    }
    else if (status.classe == "druida" || status.classe == "Druida")
    {
        cout << "Os famosos monges defensores da vida. Consigo identificar sua forma agora" << endl;
        auxiliar = 3;
    }
    else if (status.classe == "anao" || status.classe == "Anao")
    {
        cout << "A famosa raca de ferreiros, que maravilha! Agoarconsigo identificar sua forma" << endl;
        auxiliar = 4;
    }
    else if (status.classe == "secreta" || status.classe == "geleia?" || status.classe == "geleia" || status.classe == "slime?" || status.classe == "slime")
    {
        cout << "Geleia... Sim... Um slime, realmente nem lembrava da sua raca, mas pelo que sei sao os mais temidos seres vivos da face da terra, embora sejam... Fofos.";
    }

    

return 0;
}