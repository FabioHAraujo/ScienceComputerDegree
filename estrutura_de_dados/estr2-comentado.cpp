#include <iostream> // Inclui a biblioteca iostream, que é usada para entrada e saída de dados
#include <iomanip>  // Inclui a biblioteca iomanip, que é usada para formatar a saída
#include <string>   // Inclui a biblioteca string, que é usada para manipular strings

using namespace std;

// Define uma estrutura para armazenar os dados do aluno
struct Aluno{
    string nome;  // Nome do aluno
    float nota1, nota2, media; // Notas e média do aluno
};

// Programa principal
int main(){
    Aluno aln; // Cria uma instância da estrutura Aluno
    cout << "Ola, seja bem vindo, vamos calcular sua media. Primeiramente, qual seu nome?\n";
    cin >> aln.nome; // Lê o nome do aluno
    cout << "Certo, vou te chamar de " << aln.nome << ". Agora digite suas 2 notas\n";
    cin >> aln.nota1 >> aln.nota2; // Lê as notas do aluno
    aln.media = (aln.nota1+aln.nota2)/2; // Calcula a média do aluno
    cout << "Certo, sua media foi: " << fixed << setprecision(2) << aln.media; // Exibe a média do aluno, formatada com 2 casas decimais
}
