#include <iomanip>  // Inclui a biblioteca iomanip, que é usada para formatar a saída
#include <iostream> // Inclui a biblioteca iostream, que é usada para entrada e saída de dados

using namespace std;

int main ()
{
    int vetor[10], num, auxMaior=0, auxMenor=0; // Declaração de variáveis, incluindo um vetor "vetor" de tamanho 10 para armazenar as notas dos alunos
    cout << "por favor, insira as nota de seus 10 alunos para a prova" << endl; // Solicita ao usuário as notas dos alunos
    for (int i=0; i<10; i++)
    {
        cin >> vetor[i]; // Lê a nota do aluno e a armazena no vetor
    }
    cout << "qual sera a media para essa prova?" << endl; // Solicita ao usuário a média para a prova
    cin >> num; // Lê a média para a prova
    for (int i=0; i<10; i++)
    {
        if (vetor[i]<num)
        {
            auxMenor++; // Conta o número de notas abaixo da média
        }
        else if (vetor[i]>=num)
        {
            auxMaior++; // Conta o número de notas acima ou iguais à média
        }
    }
    int menores[auxMenor], maiores[auxMaior]; // Declara dois novos vetores para armazenar as notas abaixo e acima da média, com tamanhos definidos pelos contadores "auxMenor" e "auxMaior"
    int posiMenor[auxMenor], posiMaior[auxMaior]; // Declara dois novos vetores para armazenar as posições dos alunos, com tamanhos definidos pelos contadores "auxMenor" e "auxMaior"
    auxMenor = 0;
    auxMaior = 0;
    for (int i=0; i<10; i++)
    {
        if (vetor[i]<num)
        {
            menores[auxMenor] = vetor[i]; // Armazena a nota abaixo da média no vetor "menores"
            posiMenor[auxMenor] = i; // Armazena a posição do aluno no vetor "posiMenor"
            auxMenor++; // Incrementa o contador "auxMenor"
        }
        else if (vetor[i]>=num)
        {
            maiores[auxMaior] = vetor[i]; // Armazena a nota acima ou igual à média no vetor "maiores"
            posiMaior[auxMaior] = i; // Armazena a posição do aluno no vetor "posiMaior"
            auxMaior++; // Incrementa o contador "auxMaior"
        }
    cout << "As notas na media de " << num << " ou acima sao: " << endl; // Exibe uma mensagem indicando as notas acima ou iguais à média
    for (int i=0; i<auxMaior; i++)
    {
        cout << "Aluno Numero [" << posiMaior[i] << "] "  << maiores[i] << endl; // Exibe a posição do aluno e sua nota, para aqueles que tiveram notas acima ou iguais à média
    }
    cout << "As notas abaixo de " << num << " sao: " << endl; // Exibe uma mensagem indicando as notas abaixo da média
    for (int i=0; i<auxMenor; i++)
    {
        cout << "Aluno Numero [" << posiMenor[i] << "] " << menores[i] << endl; // Exibe a posição do aluno e sua nota, para aqueles que tiveram notas abaixo da média
    }
return 0; // Encerra o programa
}