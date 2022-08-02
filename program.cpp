#include "program.h"
#include <string>
#include <iostream>

#include "hely.h"
#include "kocsi.h"
#include <exception>
using namespace std;


/*
 *
 * Start függvény, meghívja a elkészített függvényeket
 * Swtich case menu
*/
void Program::program_start() {

    file_beolvas();


    int button;

    do {
        cout << "***********************Vonatjegy kiado rendszer***********************\n\n\n" << "Valasszon menupontot:"
             << endl;
        cout << "(1) Jegy kiadas\n" << "(2) Jegy torles\n" << "(3) Vonat kereses\n" << "(4) Osszes vonat listazas\n"
             << "(5) Vonat felvetele\n" << "(6) Vonat torlese\n" << "(42) Kilepes" << endl;
        cin >> button;
        switch (button) {
            case 1: {
                int vonat, kocsi, hely;
                bool err = true;
                while (err != false) {
                    cout << "Jegy vetel\n\nAdja meg: vonat - kocsi - hely" << endl;
                    err = false;
                    cin >> vonat >> kocsi >> hely;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        err = true;
                        cout << "Rossz bemenet, adja meg ujra" << endl;
                    }
                }
                bool res = jegy_vetel(vonat, kocsi, hely);
                if (res == true) {
                    cout << "\n\n A jegy elkeszult txt dokumentumként";
                }
                break;
            }
            case 2: {
                int vonat_t, kocsi_t, hely_t;
                bool err = true;
                while (err != false) {
                    err = false;
                    cout << "Jegy torlese\n\nAdja meg: vonat - kocsi - hely" << endl;
                    cin >> vonat_t >> kocsi_t >> hely_t;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        err = true;
                        cout << "Rossz bemenet, adja meg ujra" << endl;
                    }
                }
                jegy_torles(vonat_t, kocsi_t, hely_t);
                break;
            }
            case 3: {
                string ind_k, erk_k, control;
                int ev_ind, ho_ind, nap_ind, ora_ind, perc_ind;

                int butt;
                cout << "##Vonat kereses##\nCsak az indulo allomas megadasa :\t(1)" << endl;
                cout << "Indulo es erkezo allomas megadasa :  \t(2)" << endl;
                cout << "Indulo, erkezo allomas es datum megadasa: \t(3)" << endl;
                cin >> butt;
                switch (butt) {
                    case 1: {
                        cout << "\nAdja meg az indulo allomast:\t" << endl;
                        cin >> ind_k;
                        if(cin.bad()) {
                            cin.clear();
                            cin.ignore();
                            cout << "Rossz bemenet, adja meg ujra" << endl;
                        }
                        vonat_keres(ind_k);
                        break;
                    }
                    case 2: {
                        cout << "\nAdja meg az indulo allomast:\t" << endl;
                        cin >> ind_k;
                        if(cin.bad()) {
                            cin.clear();
                            cin.ignore();
                            cout << "Rossz bemenet, adja meg ujra" << endl;
                        }
                        cout << "\nAdja meg az erkezo allomast:\t" << endl;
                        cin >> erk_k;
                        if(cin.bad()) {
                            cin.clear();
                            cin.ignore();
                            cout << "Rossz bemenet, adja meg ujra" << endl;
                        }
                        vonat_keres(ind_k, erk_k);
                        break;
                    }
                    case 3: {
                        cout << "\nAdja meg az indulo allomast:\t" << endl;
                        cin >> ind_k;
                        if(cin.bad()) {
                            cin.clear();
                            cin.ignore();
                            cout << "Rossz bemenet, adja meg ujra" << endl;
                        }
                        cout << "\nAdja meg az erkezo allomast:\t" << endl;
                        cin >> erk_k;
                        if(cin.bad()) {
                            cin.clear();
                            cin.ignore();
                            cout << "Rossz bemenet, adja meg ujra" << endl;
                        }
                        cout << "\nAdja meg a datumot (ev/ho/nap/ora/perc):\t" << endl;
                        cin >> ev_ind >> ho_ind >> nap_ind >> ora_ind >> perc_ind;
                        if(cin.bad()) {
                            cin.clear();
                            cin.ignore();
                            cout << "Rossz bemenet, adja meg ujra" << endl;
                        }

                        Datum date(ev_ind, ho_ind, nap_ind, ora_ind, perc_ind);

                        vonat_keres(ind_k, erk_k, date);
                        break;
                    }
                }
                break;
            }
            case 4: {
                listaz_ossz();
                cout << "Osszes vonat kilistazva" << endl;
                break;
            }
            case 5: {
                vonat_felvesz();
                cout << "Sikeres vonat felvetel" << endl;
                break;
            }
            case 6:{
                int vonat_id_torol;
                bool err = true;
                while (err != false) {
                    err = false;

                    cout << "\nAdja meg melyik vonatot akarja torolni:" << endl;

                    cin >> vonat_id_torol;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        err = true;
                        cout << "Rossz bemenet, adja meg ujra" << endl;
                    }
                }
                vonat_torol(vonat_id_torol);
                break;
            }
            case 42:{
                break;
            }
            default:{
                cout << "Nem adott meg jo menupontot" << endl;
                break;
            }

        }
    }
    while(button != 42);
    cout << "\n##########Kilepett##########" << endl;
}


/*
 * Vonatot felvevő függvény
 * A felhasználónak kell megadni a paramétereket
 * A 'vonat.txt' fájlt bővíti
 * Újra kiolvassa a vonat.txt fájlt
 */
void Program::vonat_felvesz() {
    int id, kocsi_db, hely_db, ev_ind, ho_ind, nap_ind, ora_ind, perc_ind,
                                ev_erk, ho_erk, nap_erk, ora_erk, perc_erk;
     string indulo, erkezo;

    bool err = true;
    while(err != false) {
        cout << "**Vonat felvetele**\n\n\n" << "Vonat azonositoja: " << endl; cin >> id;
        cout << "Kocsik szama: " << endl; cin >> kocsi_db;
        err = false;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            err = true;
            cout << "Rossz bemenet, adja meg ujra" << endl;
        }
    }
    cout << "Helyek szama kocsinkent: " << endl; cin >> hely_db;
    if(cin.bad()) {
        cin.clear();
        cin.ignore();
        cout << "Rossz bemenet, adja meg ujra" << endl;
    }
    cout << "Indulo allomas: " << endl; cin >> indulo;
    if(cin.bad()) {
        cin.clear();
        cin.ignore();
        cout << "Rossz bemenet, adja meg ujra" << endl;
    }
    cout << "Erkezo allomas: " << endl; cin >> erkezo;
    if(cin.bad()) {
        cin.clear();
        cin.ignore();
        cout << "Rossz bemenet, adja meg ujra" << endl;
    }

    cout << "Indulas idopontja (ev/ho/nap/ora/perc) : " << endl;
    cin >> ev_ind >> ho_ind >> nap_ind >> ora_ind >> perc_ind;
    if(cin.bad()) {
        cin.clear();
        cin.ignore();
        cout << "Rossz bemenet, adja meg ujra" << endl;
    }
    cout << "Erkezes idopontja (ev/ho/nap/ora/perc) : " << endl;
    cin >> ev_erk >> ho_erk >> nap_erk >> ora_erk >> perc_erk;
    if(cin.bad()) {
        cin.clear();
        cin.ignore();
        cout << "Rossz bemenet, adja meg ujra" << endl;
    }


    ofstream file;
    file.open("vonat.txt", ios::app);
    file << id <<" " << indulo <<" " << erkezo <<" " << kocsi_db <<" " << hely_db << " " <<ev_ind <<" " << ho_ind <<" " <<
    nap_ind <<" " << ora_ind <<" " << perc_ind
            <<" " << ev_erk <<" " << ho_erk <<" " << nap_erk <<" " << ora_erk <<" " << perc_erk << endl;

    file.close();
    file_beolvas();

}
/*
 * Összes vonat listázása
 * Ha a mai dátumtól később van a vonat, nem írja ki!
 */
void Program::listaz_ossz() {
    Node<Vonat> *temp = vonatLista_head;

    while(temp != NULL){
        if(Datum() <= temp->data->getMikor()){
            cout << *temp->data << endl;
            temp = temp->next;
        }
    }
}

/*
 * Kereső függvény
 * @parameter honnan = ""
 * @parameter hova = ""
 * @parameter ido = mai dátum
 *
 * A default paraméterek szerint 4 módon lehet keresni:
 *      -Összes kilistázás / nincs feltétel
 *      -Induló állomás szerint kilistázás
 *      -Induló és érkező szerint kilistázás
 *      -Induló, érkező és dátum szerinti kilistázás
 */
void Program::vonat_keres(string honnan, string hova, Datum ido) {
    if (Datum() <= ido) {
        if (honnan == "" && hova == "") {
            listaz_ossz();
        }
        if (honnan != "" && hova == "") {
            Node<Vonat> *temp = vonatLista_head;
            while (temp != NULL) {
                if (honnan.compare(temp->data->getHonnan()) == 0
                    && temp->data->getMikor() >= ido) {
                    cout << *temp->data << endl;
                }
                temp = temp->next;
            }
        }
        if (honnan != "" && hova != "") {
            Node<Vonat> *temp = vonatLista_head;
            while (temp != NULL) {
                if (honnan.compare(temp->data->getHonnan()) == 0
                    && hova.compare(temp->data->getHova()) == 0
                    && temp->data->getMikor() >= ido) {
                    cout << *temp->data << endl;
                }
                temp = temp->next;
            }
        }
    }
}
/*
 * Fájl beolvasó függvény
 * Meghívja a vonatok konstruktorát
 * Listába fűzi őket
 * Meghívja a foglalt áltállító függvényt
 */
void Program::file_beolvas() {
    int id, kocsi_db, hely_db, ev_ind, ho_ind, nap_ind, ora_ind, perc_ind,
            ev_erk, ho_erk, nap_erk, ora_erk, perc_erk;
    string indulo, erkezo;

    ifstream file;
    file.open("vonat.txt");
    try {

        if (!file) {
            throw out_of_range("Nem sikerult megnyitni a filet");
        }
    }
    catch(out_of_range &r){
        cout << r.what() << endl;
    }
    List<Vonat> vonat_list;

    while(file >> id >> indulo >> erkezo >> kocsi_db >> hely_db >> ev_ind >> ho_ind >> nap_ind >> ora_ind >> perc_ind >>
               ev_erk >> ho_erk >> nap_erk >> ora_erk >> perc_erk){

        Datum indul(ev_ind, ho_ind, nap_ind, ora_ind, perc_ind);
        Datum erkez(ev_erk, ho_erk, nap_erk, ora_erk, perc_erk);



        Vonat *tmp = new Vonat(id, kocsi_db, hely_db, indulo, erkezo, indul, erkez);

        vonat_list.add_node(tmp);
    }
    if(vonatLista_head != NULL) {
        Node<Vonat> *temp_free = vonatLista_head;
        while (temp_free != NULL) {
            Node<Vonat> *next = temp_free->next;
            delete temp_free;
            temp_free = next;
        }
    }
    vonatLista_head = vonat_list.get_ListHead();
    file.close();
    foglalt_check();
}

/*
 * 'foglalt.txt' megnyitása
 * Foglalt jegyeket átállítja a listában
 */
void Program::foglalt_check() {
    int id, kocsi, hely;

    ifstream file;
    file.open("foglalt.txt");
    try {
        if (!file) {
            throw out_of_range("Nem sikerult megnyitni a filet");
        }
    }
    catch(out_of_range &r){
        cout << r.what() << endl;
    }

    while(file >> id >> kocsi >> hely){
        Node<Vonat> *tmp_v = vonatLista_head;
        while(tmp_v->data->getVonatId() != id) {
            tmp_v = tmp_v->next;
        }
        tmp_v->data->hely_switch(kocsi, hely); ///A vonat tagfüggvénye, ami átállít
        tmp_v = tmp_v->next;
    }
    file.close();
}

/*
 * Vonat töröl függvény
 * Törli a megadott azonosítójú vonatot
 * /vonat.txt/ -ből
 * /foglalt.txt/ -ből az arra szóló jegyeket
 */
void Program::vonat_torol(int vonatID) {

    int id, kocsi_db, hely_db, ev_ind, ho_ind, nap_ind, ora_ind, perc_ind,
            ev_erk, ho_erk, nap_erk, ora_erk, perc_erk;

    string indulo, erkezo;

    ifstream file_v;
    file_v.open("vonat.txt");
    try {

        if (!file_v) {
            throw out_of_range("Nem sikerult megnyitni a filet");
        }
    }
    catch(out_of_range &r){
        cout << r.what() << endl;
    }

    ofstream tmp_v;
    tmp_v.open("temp_vonat.txt", ios::app);
    try {

        if (!tmp_v) {
            throw out_of_range("Nem sikerult megnyitni a filet");
        }
    }
    catch(out_of_range &r){
        cout << r.what() << endl;
    }


    while(file_v >> id >> indulo >> erkezo >> kocsi_db >> hely_db >>
    ev_ind >> ho_ind >> nap_ind >> ora_ind >> perc_ind >>
    ev_erk >> ho_erk >> nap_erk >> ora_erk >> perc_erk){

        if(id == vonatID);

        else {
            tmp_v << id << " " << indulo << " " << erkezo << " " << kocsi_db << " " << hely_db << " " << ev_ind << " "
                << ho_ind << " " <<
                nap_ind << " " << ora_ind << " " << perc_ind
                << " " << ev_erk << " " << ho_erk << " " << nap_erk << " " << ora_erk << " " << perc_erk << endl;
        }
    }


    file_v.close();
    tmp_v.close();


    remove("vonat.txt");
    rename("temp_vonat.txt", "vonat.txt");

    vonat_torol_foglalt(vonatID);

    program_exit();
    file_beolvas();
}
/*
 * A vonat_torol segéd függvénye
 * Ez a függvény törli /foglalt.txt/ -ből a törölt vonatra szóló jegyeket
 */
void Program::vonat_torol_foglalt(int vonatID) {
    int foglalt_id, foglalt_kocsi, foglalt_hely;

    ifstream file;
    file.open("foglalt.txt");
    try {

        if (!file) {
            throw out_of_range("Nem sikerult megnyitni a filet");
        }
    }
    catch(out_of_range &r){
        cout << r.what() << endl;
    }

    ofstream temp_file;
    temp_file.open("temp_foglalt.txt", ios::app);
    try {

        if (!temp_file) {
            throw out_of_range("Nem sikerult megnyitni a filet");
        }
    }
    catch(out_of_range &r){
        cout << r.what() << endl;
    }


    while(file >> foglalt_id >> foglalt_kocsi >> foglalt_hely){

        if(foglalt_id == vonatID);

        else{
            temp_file << foglalt_id << " " << foglalt_kocsi << " " << foglalt_id << endl;
        }
    }

    file.close();
    temp_file.close();
    remove("foglalt.txt");
    rename("temp_foglalt.txt", "foglalt.txt");


    foglalt_check();
}

/*
 * Jegy vevő függvény
 * @param kocsi = 0
 * @param hely = 0
 * Beleírja a /fogalt.txt/ fájlba a jegyet
 * Átállítja a listában az adott helyet foglaltra
 * Létrehozza a jegy fájlját
 */
bool Program::jegy_vetel(int vonatID, int kocsi, int hely) {

    ofstream foglalt;
    foglalt.open("foglalt.txt", ios::app);
    try {

        if (!foglalt) {
            throw out_of_range("Nem sikerult megnyitni a filet");
        }
    }
    catch(out_of_range &r){
        cout << r.what() << endl;
    }

    Node<Vonat> *temp_v = vonatLista_head;


    while (temp_v->data->getVonatId() != vonatID) {
        temp_v = temp_v->next;
    }
            if (kocsi == 0 && hely == 0) {

                for (int i = 1; i <= temp_v->data->getKocsikDb(); i++) {
                    for (int j = 1; j <= temp_v->data->getKocsiHelyDb(); j++) {

                        if (temp_v->data->hely_check(i, j) == false) {
                            foglalt << vonatID << " " << i << " " << j << endl;
                            temp_v->data->hely_switch(i, j);
                            string jegy = jegy_name(vonatID, i, j);

                            jegy_txt(jegy, *temp_v->data, vonatID, i, j);
                            foglalt.close();
                            return true;
                        } else {
                            cout << "Foglalt volt a hely" << endl;
                            foglalt.close();
                            return false;
                        }
                    }
                }
            }
            if (kocsi != 0 && hely == 0) {
                for (int j = 1; j <= temp_v->data->getKocsiHelyDb(); j++) {
                    if (temp_v->data->hely_check(kocsi, j) == false) {
                        foglalt << vonatID << " " << kocsi << " " << j << endl;
                        temp_v->data->hely_switch(kocsi, j);
                        string jegy = jegy_name(vonatID, kocsi, j);

                        jegy_txt(jegy, *temp_v->data, vonatID, kocsi, j);
                        foglalt.close();
                        return true;
                    } else {
                        cout << "Foglalt volt a hely" << endl;
                        foglalt.close();
                        return false;
                    }
                }
            }
            if (kocsi == 0 && hely != 0) {
                for (int i = 1; i <= temp_v->data->getKocsikDb(); i++) {
                    if (temp_v->data->hely_check(i, hely) == false) {
                        foglalt << vonatID << " " << i << " " << hely << endl;
                        temp_v->data->hely_switch(i, hely);
                        string jegy = jegy_name(vonatID, i, hely);

                        jegy_txt(jegy, *temp_v->data, vonatID, i, hely);
                        foglalt.close();
                        return true;
                    } else {
                        cout << "Foglalt volt a hely" << endl;
                        foglalt.close();
                        return false;
                    }
                }
            }
            if (kocsi != 0 && hely != 0) {
                if (temp_v->data->hely_check(kocsi, hely) == false) {
                    foglalt << vonatID << " " << kocsi << " " << hely << endl;
                    temp_v->data->hely_switch(kocsi, hely);
                    string jegy = jegy_name(vonatID, kocsi, hely);

                    jegy_txt(jegy, *temp_v->data, vonatID, kocsi, hely);
                    foglalt.close();
                    return true;
                } else {
                    cout << "Foglalt volt a hely" << endl;
                    foglalt.close();
                    return false;
                }
            }
    cout << "Nincs ilyen kocsi vagy tele" << endl;
    foglalt.close();
    return false;
}

/*
 * jegy_vetel segédfüggvénye
 * létrehozza a kiadott jegy fájlt nevét
 */
string Program::jegy_name(int vonatID, int kocsiID, int helyID) {
    string id, kocsi, hely, name;
    id = to_string(vonatID);
    kocsi = to_string(kocsiID);
    hely = to_string(helyID);

    name = id + kocsi + hely + ".txt";

    return name;

}
/*
 * A jegy_vetel segédfüggvénye
 * Létrehozza a jegy fájlt
 */
void Program::jegy_txt(string nev, Vonat vonat, int id, int kocsi, int hely) {

    ofstream jegy_file;
    jegy_file.open(nev);
    try {

        if (!jegy_file) {
            throw out_of_range("Nem sikerult megnyitni a filet");
        }
    }
    catch(out_of_range &r){
        cout << r.what() << endl;
    }

    jegy_file << "*********************JEGY*********************\n\n\n" << endl;
    jegy_file << "Indulo allomas:\t" << vonat.getHonnan() << endl;
    jegy_file << "Erkezo allomas:\t" << vonat.getHova() << endl;
    jegy_file << "\n\nIndulas idopontja:\t" << vonat.getMikor() << '\t' <<
              "Erkezes idopontja:\t" << vonat.getErkez() << endl;

    jegy_file << "\n\n\nVonat szam:\t" << id << "\tKocsi szam:\t" << kocsi << "\tHely szam:\t" << hely;

    jegy_file.close();
    cout << "Sikeres jegy vetel" << nev << endl;
}
/*
 * Jegyet törlő függvény
 */
void Program::jegy_torles(int vonatID, int kocsiID, int helyID) {
    int temp_id, temp_kocsi, temp_hely;

    ifstream file;
    file.open("foglalt.txt");
    try {

        if (!file) {
            throw out_of_range("Nem sikerult megnyitni a filet");
        }
    }
    catch(out_of_range &r){
        cout << r.what() << endl;
    }

    ofstream tmp;
    tmp.open("tmp.txt", ios::app);
    try {

        if (!tmp) {
            throw out_of_range("Nem sikerult megnyitni a filet");
        }
    }
    catch(out_of_range &r){
        cout << r.what() << endl;
    }

    while (file >> temp_id >> temp_kocsi >> temp_hely) {
        if (temp_id == vonatID && temp_kocsi == kocsiID && temp_hely == helyID);

        else {
            tmp << temp_id << " " << temp_kocsi << " " << temp_hely << endl;
        }
    }
    file.close();
    tmp.close();
    remove("foglalt.txt");
    rename("tmp.txt", "foglalt.txt");

    foglalt_check();
}

/*
 * Foglalt jegyek kilistázása
 * Nem használtam fel
 */
void Program::foglalt_listaz() {
    Node<Vonat> *temp_v = vonatLista_head;


    while(temp_v != NULL){
        Node<Kocsi> *temp_k = temp_v->data->getKocsik();
        while(temp_k != NULL){
            Node<Hely> *temp_h = temp_k->data->getHelyek();
            while(temp_h != NULL){
                if(temp_h->data->getFoglalt_e() == true){
                    cout << temp_h->data->getHelyID() << endl;
                }
                temp_h = temp_h->next;
            }
            temp_k = temp_k->next;
        }
        temp_v = temp_v->next;
    }
}

/*
 * A program bezáró függvény
 * Végigmegy a lista elemeken
 * Törli őket
 *
 * Memória szivárgás miatt van rá szükség
 */
void Program::program_exit() {
    Node<Vonat> *tmp_v = vonatLista_head;
    while(tmp_v != NULL){
        Node<Kocsi> *temp_k = tmp_v->data->getKocsik();
        while(temp_k != NULL) {
            Node<Kocsi> *next = temp_k->next;
            temp_k->data->kocsi_exit();
            //delete temp_k;
            temp_k = next;
        }
        tmp_v->data->vonat_exit();
        Node<Vonat> *next = tmp_v->next;
        delete tmp_v->data;
        delete tmp_v;
        tmp_v = next;
    }
    vonatLista_head = NULL;
}
