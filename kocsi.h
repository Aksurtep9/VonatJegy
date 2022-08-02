#ifndef KOCSI_H_INCLUDED
#define KOCSI_H_INCLUDED


#include <ostream>
//#include "memtrace.h"
#include "list.hpp"
#include "hely.h"

class Vonat;

//class Hely;

class Kocsi {
	int kocsiID;
	int hely_db;
	bool tele_e;
	Vonat *vonat;
	Node<Hely> *hely;
public:
    Kocsi();

	Kocsi(int kocsiID, int hely_db, bool tele_e, Vonat* vonat);


	Kocsi(const Kocsi & k){ *this=k;}

    Kocsi& operator=(const Kocsi&);


    friend std::ostream &operator<<(std::ostream &os, const Kocsi &kocsi);

    bool isTeleE() const;

    Node<Hely> * getHelyek();

    void Helyek_listaz();

    int getKocsiId() const;

    int getHely_db() const;

    Vonat *getVonat() const;

    void set_tele(){
        tele_e = true;
    }

    void set_szabad(){
        tele_e = false;
    }

    void set_node(Node<Hely> *helyNode){
        hely = helyNode;
    }

    void helyek_check();



    virtual ~Kocsi(){
        Node<Hely> *tmp = hely;
        while(tmp != NULL){
            Node<Hely> *next = tmp->next;
            delete tmp->data;
            delete tmp;
            tmp = next;
        }
        hely = NULL;
    }

    void kocsi_exit(){
        Node<Hely> *tmp = hely;
        while(tmp != NULL){
            Node<Hely> *next = tmp->next;
            delete tmp->data;
            delete tmp;
            tmp = next;
        }
        hely = NULL;
    }
};

#endif //KOCSI_H