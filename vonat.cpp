
#include "vonat.h"
#include "kocsi.h"
#include "hely.h"

Vonat::Vonat()
{
    Datum d;
	vonatID = 0;
	kocsi_hely_db = 0;
	honnan= "";
	hova= "";
	indul =  d;
	erkez =  d;
	kocsik_db = 0;
	kocsik = NULL;

}
Vonat::Vonat( int vonatID, int kocsik_db, int kocsik_hely_db, std::string indulo, std::string erkezo, Datum indul, Datum erkez) {

    this->vonatID = vonatID;
    this->kocsik_db = kocsik_db;
    this->kocsi_hely_db = kocsik_hely_db;
    this->honnan = indulo;
    this->hova = erkezo;
    this->indul = indul;
    this->erkez = erkez;

    List<Kocsi> kocsik_list;
    for(int i=1; i <= this->kocsik_db; i++){
        Kocsi *kocsi = new Kocsi(i, this->kocsi_hely_db, false, this);
        //std::cout << this->kocsi_hely_db << std::endl;
        kocsik_list.add_node(kocsi);
    }
    this->kocsik=kocsik_list.get_ListHead();

}


int Vonat::getVonatId() const {
    return vonatID;
}

Node<Kocsi> *Vonat::getKocsik(){
    return kocsik;
}

Vonat& Vonat::operator=(const Vonat& v){
    if(this != &v) {
        vonatID = v.vonatID;
        kocsik_db = v.kocsik_db;
        kocsik = v.kocsik;
        kocsi_hely_db = v.kocsi_hely_db;
        honnan = v.honnan;
        hova = v.hova;
        indul = v.indul;
        erkez = v.erkez;
    }
    return *this;
}

void Vonat::kocsi_listaz(){
    Node<Kocsi> *temp = kocsik;

    while(temp != NULL){
        std::cout << *temp->data << std::endl;
        temp = temp->next;
    }
}

void Vonat::hely_switch(int kocsi_sz, int hely_sz) {

    Node<Kocsi> *temp_kocsi_node = kocsik;
    while(temp_kocsi_node->data->getKocsiId() != kocsi_sz) {
        temp_kocsi_node = temp_kocsi_node->next;
    }

    if(temp_kocsi_node->data->getHelyek()->data->getHelyID() == hely_sz){
        Node<Hely> *temp_hely_node = temp_kocsi_node->data->getHelyek();
        Hely *hely = new Hely(temp_hely_node->data->getHelyID() ,true, temp_kocsi_node->data);
        Node<Hely> *new_h = new Node<Hely>;
        new_h->data = hely;
        new_h->next = temp_hely_node->next;
        delete temp_hely_node->data;
        delete temp_hely_node;
        temp_kocsi_node->data->set_node(new_h);
    }
    else {
        Node<Hely> *temp_hely_node = temp_kocsi_node->data->getHelyek();
        Node<Hely> *iter = temp_hely_node;
        while (temp_hely_node->data->getHelyID() != hely_sz) {
            iter = temp_hely_node;
            temp_hely_node = temp_hely_node->next;
        }
        if (!temp_hely_node->data->getFoglalt_e()) {
            Hely *hely = new Hely(temp_hely_node->data->getHelyID(), true, temp_kocsi_node->data);
            Node<Hely> *new_h = new Node<Hely>;
            new_h->data = hely;
            new_h->next = temp_hely_node->next;
            iter->next = new_h;

            delete temp_hely_node->data;
            delete temp_hely_node;
        } else {
            Hely *hely = new Hely(temp_hely_node->data->getHelyID(), false, temp_kocsi_node->data);
            Node<Hely> *new_h = new Node<Hely>;
            new_h->data = hely;
            new_h->next = temp_hely_node->next;
            iter->next = new_h;

            delete temp_hely_node->data;
            delete temp_hely_node;
        }
    }
    if(kocsik->data->getKocsiId() == kocsi_sz){
        this->setKocsik(temp_kocsi_node);
    }
}

bool Vonat::hely_check(int kocsi_sz, int hely_sz) {
    Node<Kocsi> *temp_kocsi_node = kocsik;

    while(temp_kocsi_node->data->getKocsiId() != kocsi_sz){
            temp_kocsi_node = temp_kocsi_node->next;
        }
            Node<Hely> *temp_hely_node = temp_kocsi_node->data->getHelyek();
                while(temp_hely_node->data->getHelyID() != hely_sz) {
                    temp_hely_node = temp_hely_node->next;
                }

                    return temp_hely_node->data->getFoglalt_e();
}



std::ostream &operator<<(std::ostream &os, const Vonat &vonat) {
    os << "vonatID: " << vonat.vonatID <<  " honnan: " << vonat.honnan << " hova: " << vonat.hova
       << " indul: " << vonat.indul << " erkez: " << vonat.erkez;
    return os;
}

int Vonat::getKocsikDb() const {
    return kocsik_db;
}

int Vonat::getKocsiHelyDb() const {
    return kocsi_hely_db;
}

const Datum &Vonat::getErkez() const {
    return erkez;
}

void Vonat::setKocsik(Node<Kocsi> *kocsik) {
    this->kocsik = kocsik;
}
