#include "kocsi.h"
#include "vonat.h"
#include "hely.h"

Kocsi::Kocsi(){
    kocsiID=0;
    hely_db=0;
    tele_e=false;
    vonat=NULL;
    hely = NULL;
}

Kocsi::Kocsi(int kocsiID, int hely_db, bool tele_e, Vonat* vonat){
    this->kocsiID=kocsiID;
    this->hely_db=hely_db;
    this->tele_e=tele_e;
    this->vonat=vonat;

    List<Hely> helyek_list;

    for(int i=1; i<=this->hely_db; i++){

        Hely *hely = new Hely(i,false,this);
        helyek_list.add_node(hely);
        //this->helyek->add_node(hely);
    }
    hely=helyek_list.get_ListHead();
}

std::ostream &operator<<(std::ostream &os, const Kocsi &kocsi) {
    os << "kocsiID: " << kocsi.getKocsiId() << " hely_db: " << kocsi.getHely_db() << " tele_e: " << kocsi.isTeleE() << " vonat: "
       << kocsi.getVonat()->getVonatId();
    return os;
}

bool Kocsi::isTeleE() const {
    return tele_e;
}

Node<Hely> * Kocsi::getHelyek() {
    return hely;
}

void Kocsi::Helyek_listaz() {
    Node<Hely> *temp = hely;
    while(temp != NULL){
        std::cout << *temp->data << std::endl;
        temp = temp->next;
    }
}

int Kocsi::getKocsiId() const {
    return kocsiID;
}

int Kocsi::getHely_db() const {
    return hely_db;
}

Vonat *Kocsi::getVonat() const {
    return vonat;
}

Kocsi& Kocsi::operator=(const Kocsi &k) {
    if(this != &k){
    kocsiID=k.kocsiID;
    hely_db=k.hely_db;
    tele_e=k.tele_e;
    vonat=k.vonat;
    if(hely != NULL){
        Node<Hely> *temp = hely;
        while(temp != NULL){
            Node<Hely> *next = temp->next;
            delete temp->data;
            delete temp;
            temp = next;
        }
    }
    hely=k.hely;
    }
    return *this;
}

void Kocsi::helyek_check() {
    Node<Hely> *tmp = hely;

    while(tmp != NULL){
        if(tmp->data->getFoglalt_e() == false) {
            set_szabad();
            return;
        }
        tmp=tmp->next;
    }
    set_tele();

}




