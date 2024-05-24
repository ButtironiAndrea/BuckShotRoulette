#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unistd.h>



using namespace std;

void Lente(int a){

cout<<"stai utilizzando la lente..."<<endl;
sleep(2);
if(a==1)
    cout<<"...il proiettile e' VERO!";
else
    cout<<"...il proiettile e' FALSO!";

};

int main() {
    cout << "Benvenuto alla roulette russa" << endl;

    srand(static_cast<unsigned int>(time(0)));

    int round = 1;
    bool continua = true;
    int numero1 = rand() % 9 + 1;
    int numero2 = rand() % (10 - numero1) + 1;
    int numero3 = 0;

    while (continua) {
        cout << "\nRound " << round << endl;
        cout << "Proiettili veri: " << numero1 << endl;
        cout << "Proiettili falsi: " << numero2 << endl;

        int somma = numero1 + numero2;

        if (somma > 10) {
            cout << "Attenzione! La somma supera 10. Riavvia il programma per ottenere numeri validi." << endl;
            break;
        }

        int sceltaGiocatore;

    if(numero1>0 && numero2>0){
            numero3 = rand() % 2 + 1;
}else if(numero1==0 && numero2>0){
        numero3 = 2;
}else if(numero1 >0 && numero2==0)
        numero3=1;

        cout <<endl<< "Scegli spara all'avversario[1] o spara a te [2]: ";
        cin >> sceltaGiocatore;

        if (sceltaGiocatore == numero3) {
            cout << "Hai vinto il round!" << endl;
            round++;
        } else {
            cout << "Hai perso. Il gioco finisce." << endl;
            continua = false;
        }


        if (sceltaGiocatore == 1) {
            numero1 = max(0, numero1 - 1);
        } else if (sceltaGiocatore == 2) {
            numero2 = max(0, numero2 - 1);
        }


        if (numero1 == 0 && numero2 == 0) {
            cout << "Hai vinto il gioco. Complimenti" << endl;
            continua = false;
        }
    }

    cout << "Il gioco è terminato. Hai completato " << round - 1 << " round." << endl;

    return 0;
}
