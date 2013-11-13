#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <sstream>

using namespace std;

const int MAX_SPIELER=3;
int zs[MAX_SPIELER]={0};
int spieler=-1;
int gesamt[MAX_SPIELER]={0};

int menu2();
void programm();
void spiel_ende();
void spiel_starten(string msg);
int wuerfeln();
void zug();
string int_2_str(int val);
void spiel_verloren();
void spiel_abgebrochen();
void zug_gewonnen_und_weiter(int wurf);
void bildschirm_loeschen();


int main()
{
    programm();
    return 0;
}

int menu2(string titel, string befehle[],int anzahl){

    cout << "      " << titel << "\n\n\n";

    for ( int index=0; index < anzahl; index++){
        cout << index + 1 << "  " << befehle[index] << endl;
    }

    int result;
    cin >> result;
    return result;
}

void programm(){
    srand(time(0));
    string befehle[]={"Spiel","Ende"};
    int anzahl = sizeof(befehle) / sizeof(string);

    while(true){
        int result=menu2("Bitte waehlen Sie eine Option",befehle,anzahl);
        if (result == 2) spiel_ende();
        if (result == 1) {
            if(spieler < MAX_SPIELER - 1) spieler++; else spieler=0;
            zs[spieler]=0;
            spiel_starten("");
        }
     }
}

void spiel_ende(){
    exit(1);
}

void spiel_starten(string msg){
    bildschirm_loeschen();
    string spieler_num="Spieler: "+ int_2_str(spieler+1);
    string titel=msg + "Wollen Sie wirklich weitermachen ? "+spieler_num;
    string befehle[]={"Ja","Nein"};

    int result=menu2(titel,befehle,2);

    if(result==1) zug();
    if(result==2) spiel_abgebrochen();

}

void spiel_abgebrochen(){
    bildschirm_loeschen();
    cout << "spiel abgebrochen \n";
}

void zug(){
    int wurf=wuerfeln();
    if(wurf == 1) spiel_verloren(); else zug_gewonnen_und_weiter(wurf);
}

void zug_gewonnen_und_weiter(int wurf){
    string msg="Glück \n";
    zs[spieler] += wurf;
    gesamt[spieler] += wurf;
    string statistik="aktueller wurf: "+ int_2_str(wurf) + "\n";
    string statistik2="Zwischensumme: " + int_2_str(zs[spieler]) + "\n";
    string statistik3="Gesamt bisher: " + int_2_str(gesamt[spieler]) + "\n";
    spiel_starten(msg + statistik + statistik2+statistik3);
}

void spiel_verloren(){
    bildschirm_loeschen();
    gesamt[spieler] -= zs[spieler];
    zs[spieler]=0;
    cout << "spiel verloren \n";
}

int wuerfeln(){

    int rnd = rand();
    return rnd % 6 + 1;
}

void bildschirm_loeschen(){
    system("clear");  //linux,mac
    //system("cls");  //windows
}

string int_2_str(int val){

    std::stringstream ss;
    ss << val;
    return ss.str();
}
