#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct player{
    int vida, forca, loucura;
    string tempDoDia;
};


bool ordena(player ordem, player ordem2){
    return ordem.vida < ordem2.vida;
}

int main(){
    vector<player> recruta; //Mesma coisa que colocar player recruta[tamanho]
    player davi, rafael, felipe, fabio;
    davi.vida = 100;
    rafael.vida = 60;
    fabio.vida = 180;
    felipe.vida = 120;
    recruta.push_back(davi);
    recruta.push_back(fabio);
    recruta.push_back(rafael);
    recruta.push_back(felipe);
    for (player &pessoa : recruta){
        cout << pessoa.vida << endl;
    }
    cout << "==============" << endl;
    /*recruta.erase(recruta.begin()+2);
    for (player &pessoa : recruta){
        cout << pessoa.vida << endl;
    }*/
    cout << "==============" << endl;
    sort(recruta.begin(), recruta.end(), ordena);

    for (player &pessoa : recruta){
        cout << pessoa.vida << endl;
    }


    return 0;
}