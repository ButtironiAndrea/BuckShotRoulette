#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unistd.h>



using namespace std;

struct Gioco{
    int numero1;
    int numero2;
    int numero3;
    string nome;
    int vitaplayer;
    int vitadealer;
    bool turno=false;
};


void Lente(Gioco a){

cout<<"stai utilizzando la lente..."<<endl;
sleep(2);
if(a.numero3==1)
    cout<<"...il proiettile e' VERO!";
else
    cout<<"...il proiettile e' FALSO!";

};

void tabellone(Gioco v){
    cout<<endl<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"          Dealer        | |         "<<v.nome<<"        "<<endl;
    cout<<"------------------------------------------------"<<endl;
    if(v.vitadealer>0){
        for(int i=0; i<v.vitadealer; i++){
            cout <<"<3";
        }
        cout<<"                       ";
    }
    if(v.vitaplayer>0){
        for(int i=0; i<v.vitaplayer; i++){
          cout <<"<3";
        }
    }
    cout<<endl<<endl;
}

Gioco AIdealer(Gioco v){
    cout<<"vediamo un po..."<<endl;
    sleep(1);
    int sceltadealer=0;
    if(v.numero1>v.numero2)
       sceltadealer=1;
    if(v.numero1<v.numero2)
        sceltadealer=2;
    if(v.numero1==v.numero2)
        sceltadealer=rand()%2+1;
if (v.numero3==1 && sceltadealer==1 && v.vitaplayer>1) {
            cout << "*sparo* oh scusami" << endl;
            v.numero1 = max(0, v.numero1 - 1);
            v.vitaplayer--;
            return v;
            sleep(2);
        } else if(v.numero3==1 && sceltadealer==1){
            cout << "AHAHAHAHA..." << endl;
            v.vitaplayer--;
            return v;
            sleep(2);
        } else if(v.numero3==2 && sceltadealer==1){
            cout << "Dannazzione... prego tutta tua" << endl;
            v.numero2 = max(0, v.numero2 - 1);
            v.turno=false;
            return v;
            sleep(2);
        } else if(v.numero3==2 && sceltadealer==2){
            cout << "uff" << endl;
            v.numero2 = max(0, v.numero2 - 1);
            v.turno=true;
            return v;
            sleep(2);
        } else if(v.numero3==1 && sceltadealer==2){
            cout << "*si spara in bocca* aia ahahah"<< endl;
            v.numero1 = max(0, v.numero1 - 1);
            v.vitadealer--;
            v.turno=false;
            return v;
            sleep(2);
        }
        tabellone(v);
}


int main() {

    srand(time(NULL));
        Gioco stat;
    bool continua = true;
     stat.numero1 = rand() % 9 + 1;
     stat.numero2 = rand() % (10 - stat.numero1) + 1;
     stat.numero3 = 0;
     stat.vitaplayer = 3;
     stat.vitadealer = 3;

    cout << "__________               __      _________.__            __    __________             .__          __    __          " << endl;
    cout << "\\______   \\__ __   ____ |  | __ /   _____/|  |__   _____/  |_  \\______   \\ ____  __ __|  |   _____/  |__/  |_  ____  " << endl;
    cout << " |    |  _/  |  \\_/ ___\\|  |/ / \\_____  \\ |  |  \\ /  _ \\   __\\  |       _//  _ \\|  |  \\  | _/ __ \\   __\\   __\\/ __ \\ " << endl;
    cout << " |    |   \\  |  /\\  \\___|    <  /        \\|   Y  (  <_> )  |    |    |   (  <_> )  |  /  |_\\  ___/|  |  |  | \\  ___/ " << endl;
    cout << " |______  /____/  \\___  >__|_ \\/_______  /|___|  /\\____/|__|    |____|_  /\\____/|____/|____/\\___  >__|  |__|  \\___  >" << endl;
    cout << "        \\/            \\/     \\/        \\/      \\/                      \\/                       \\/                \\/ " << endl;
    cout<<endl;
    cout<<"Benvenuto, Prego inserisci il tuo nome: ";
    cin>>stat.nome;

    while (continua) {
        tabellone(stat);
        if(stat.turno==true)
            stat=AIdealer(stat);
        cout << "Proiettili veri: " << stat.numero1 << endl;
        cout << "Proiettili falsi: " << stat.numero2 << endl;

        int somma = stat.numero1 + stat.numero2;

        if (somma > 10) {
            cout << "Attenzione! La somma supera 10. Riavvia il programma per ottenere numeri validi." << endl;
            break;
        }

        int sceltaGiocatore;

    if(stat.numero1>0 && stat.numero2>0){
            stat.numero3 = rand() % 2 + 1;
}else if(stat.numero1==0 && stat.numero2>0){
        stat.numero3 = 2;
}else if(stat.numero1 >0 && stat.numero2==0)
        stat.numero3=1;

        cout <<endl<< "Scegli spara all'avversario[1] o spara a te [2]: ";
        cin >> sceltaGiocatore;

        if (stat.numero3==1 && sceltaGiocatore==1 && stat.vitadealer>1) {
            cout << "*sparo* mi hai fatto male... ma ci vorra ben altro per abbattermi" << endl;
            stat.numero1 = max(0, stat.numero1 - 1);
            stat.vitadealer--;
            stat.turno=true;
            sleep(2);
        } else if(stat.numero3==1 && sceltaGiocatore==1){
            cout << "Ough.... *il dealer si accascia a terra*" << endl;
            stat.vitadealer--;
            sleep(2);
        } else if(stat.numero3==2 && sceltaGiocatore==1){
            cout << "Era a salve, ora e' il mio turno" << endl;
            stat.numero2 = max(0, stat.numero2 - 1);
            stat.turno=true;
            sleep(2);
        } else if(stat.numero3==2 && sceltaGiocatore==2){
            cout << "Ti e' andata bene, prego tocca a ancora a te" << endl;
            stat.numero2 = max(0, stat.numero2 - 1);
            stat.turno=false;
            sleep(2);
        } else if(stat.numero3==1 && sceltaGiocatore==2){
            cout << "*ti spari in bocca* aia... deve fare parecchio male"<< endl;
            stat.numero1 = max(0, stat.numero1 - 1);
            stat.turno=true;
            stat.vitaplayer--;
            sleep(2);
        }

        if(stat.vitaplayer==0){
            cout<<"mi dispiace hai perso...";
            continua = false;
        }


        if (stat.numero1 == 0 && stat.numero2 == 0 || stat.vitadealer==0) {
            cout << "Hai vinto il gioco. Complimenti" << endl;
            continua = false;
        }
    }


    return 0;
}
