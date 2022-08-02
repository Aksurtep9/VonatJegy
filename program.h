
#ifndef VONAT_CLION_PROGRAM_H
#define VONAT_CLION_PROGRAM_H

#include <fstream>

#include "list.hpp"
//#include "memtrace.h"
#include "vonat.h"


class Program{
    Node<Vonat> *vonatLista_head;
public:

    Program(): vonatLista_head(NULL){}

    void program_start();

    void vonat_felvesz();

    void listaz_ossz();

    void vonat_keres(std::string honnan="", std::string hova ="", Datum ido = Datum());

    void vonat_torol(int vonatID);

    void vonat_torol_foglalt(int vonatID);

    bool jegy_vetel(int vonatID, int kocsi = 0, int hely = 0);

    void jegy_torles(int vonatID, int kocsiID, int helyID);

    std::string jegy_name(int vonatID, int kocsiID, int helyID);

    void jegy_txt(std::string nev, Vonat vonat, int id, int kocsi, int hely);

    void file_beolvas();

    void foglalt_check();

    void foglalt_listaz();

    void program_exit();

};


#endif //VONAT_CLION_PROGRAM_H
