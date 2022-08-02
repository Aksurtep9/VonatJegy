#ifndef VONAT_H_INCLUDED
#define VONAT_H_INCLUDED


#include <ostream>
#include <sstream>
//#include "memtrace.h"
#include "datum.h"
#include "list.hpp"
#include "kocsi.h"


//class Kocsi;

class Vonat {
	int vonatID;
	int kocsik_db;
	Node<Kocsi> *kocsik;
	int kocsi_hely_db;

	std::string honnan;
	std::string hova;
	Datum indul;
	Datum erkez;
public:

	Vonat();

	Vonat(int vonatID,int kocsik_db, int kocsik_hely_db, std::string indulo, std::string erkezo, Datum indul, Datum erkez );

	Vonat(std::string& line);

    Vonat(const Vonat & v){
        *this=v;
    }

    Vonat& operator=(const Vonat&);


    int getVonatId() const;

    std::string getHonnan() const{
        return honnan;
    }

    std::string getHova() const{
        return hova;
    }
    Datum getMikor() const{
        return indul;
    }

    Node<Kocsi> *getKocsik();

    void kocsi_listaz();

    void hely_switch(int kocsi_sz, int hely_sz);

    bool hely_check(int kocsi_sz, int hely_sz);

    friend std::ostream &operator<<(std::ostream &os, const Vonat &vonat);

    virtual ~Vonat(){
        Node<Kocsi> *tmp = kocsik;
        while(tmp != NULL){
            Node<Kocsi> *next = tmp->next;
            delete tmp->data;
            delete tmp;
            tmp = next;
        }
        kocsik = NULL;
    }

    int getKocsikDb() const;

    int getKocsiHelyDb() const;

    const Datum &getErkez() const;

    void vonat_exit(){
        Node<Kocsi> *tmp = kocsik;
        while(tmp != NULL){
            Node<Kocsi> *next = tmp->next;
            delete tmp->data;
            delete tmp;
            tmp = next;
        }
        kocsik = NULL;
    }

    void setKocsik(Node<Kocsi> *kocsik);
};

#endif //VONAT_H