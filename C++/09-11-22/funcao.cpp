#include <iostream>
#include <iomanip>
#include <string>

struct bagagem
{
    int numBagagem;
    std::string tipoMala;
};
// struct é utilizado para determinar variáveis que posteriormente serão atribuídas a outras variáveis, 
// podendo então ser utilizado .nomeDasVar para chamar essa variável após um array por exemplo.
// é como criar um tipo de variávle, como int, double ou float, o tipo aqui seria bagagem.
// neste caso foi criado um struct bagagem

void getBagagemInfo (bagagem issoehumarray[], int selectBag)
{
    std::cout << "Numeracao da Bagagem: " << issoehumarray[selectBag].numBagagem << std::endl;
    std::cout << "Tipo da mala: " << issoehumarray[selectBag].tipoMala << std::endl;

    return;
}
// void é utilizado para retornar nada ao fim de uma operação. O Void tem prioridade inforior à uma função int, por isso sempre será executado após a função inteira.


int main ()
{
    int selectBag, qtdBagagem, count=0, tipo;
    std::cout << "Ola senhor, quantas bagagens esta trazendo? ";
    std::cin >> qtdBagagem;
    bagagem arrayBagagem[qtdBagagem];
    //aqui criamos uma variável arrayBagagem do "tipo bagagem", o qual contém uma var int e uma var string.
    while (count<qtdBagagem)
    {
        std::cout << "O senhor esta inserindo os dados de sua bagagem numero: " << count+1 << std::endl;
        std::cout << "Qual o tipo desta bagagem? \n" << "1 - De mao\n" << "2 - De Carga\n";
        std::cin >> tipo;
        if (tipo==1)
        {
            arrayBagagem[count].tipoMala = "De Mao";
        }
        else if (tipo==2)
        {
            arrayBagagem[count].tipoMala = "De Carga";
        }
        arrayBagagem[count].numBagagem=count+1;
        count++;
    }

    std::cout << "Agora que inseriu os dados, qual bagagem gostaria de levar consigo? (eh permitido carregar apenas uma pelo hotel)" << std::endl;
    std::cin >> selectBag;
    selectBag-=1;

    getBagagemInfo(arrayBagagem, selectBag);

    return 0;
}