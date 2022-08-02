


#include "program.h"
//#include "memtrace.h"
//#include "gtest_lite.h"
#include "hely.h"
#include "kocsi.h"

#include <iostream>




using namespace std;

/*
void test() {
    TEST("Hely", "Konstruktor")

    Hely hely = Hely();

    EXPECT_EQ(0, hely.getHelyID());
    EXPECT_EQ(false, hely.getFoglalt_e());
    END

    TEST("Hely", "Setter")


    Hely hely = Hely();

    hely.set_foglalt();
    EXPECT_EQ(true, hely.getFoglalt_e());
    hely.set_szabad();
    EXPECT_EQ(false, hely.getFoglalt_e());
    END

    TEST("Hely", "Konstruktor_par")


    Hely hely(5, false, NULL);

    EXPECT_EQ(5, hely.getHelyID());
    EXPECT_EQ(false, hely.getFoglalt_e());
    END


    TEST("Kocsi", "Konstruktor")


    Kocsi kocsi = Kocsi();
    EXPECT_EQ(0, kocsi.getKocsiId());
    EXPECT_EQ(false, kocsi.isTeleE());
    EXPECT_EQ(0, kocsi.getHely_db());
    kocsi.kocsi_exit();
    END

    TEST("Kocsi", "Setter")
    Kocsi kocsi = Kocsi();

    kocsi.set_szabad();
    EXPECT_EQ(false, kocsi.isTeleE());

    kocsi.set_tele();
    EXPECT_EQ(true, kocsi.isTeleE());
    END

    TEST("Kocsi", "Konstruktor_par")

    Kocsi kocsi(5, 10, false, NULL);

    EXPECT_EQ(5, kocsi.getKocsiId());
    EXPECT_EQ(10, kocsi.getHely_db());
    EXPECT_EQ(false, kocsi.isTeleE());
    EXPECT_EQ(10, kocsi.getHelyek()->data->getHelyID());
    kocsi.kocsi_exit();
    END

    TEST("Vonat", "Konstruktor_par")

    Vonat vonat(100, 3, 10, "BUDAPEST", "MISKOLC", Datum(), Datum());
    EXPECT_EQ(100, vonat.getVonatId());
    EXPECT_EQ(3, vonat.getKocsikDb());
    EXPECT_EQ(10, vonat.getKocsiHelyDb());
    EXPECT_EQ(string("BUDAPEST"),vonat.getHonnan());
    EXPECT_EQ(string("MISKOLC"), vonat.getHova());
    Node<Kocsi> *temp = vonat.getKocsik();
    int i = vonat.getKocsikDb();
    while(temp != NULL){
        EXPECT_EQ(i , temp->data->getKocsiId());
        i--;
        temp = temp->next;
    }
    Node<Kocsi> *temp_delete = vonat.getKocsik();
    while(temp_delete != NULL){
        temp_delete->data->kocsi_exit();
        temp_delete = temp_delete->next;
    }
    vonat.vonat_exit();
    END

    TEST("Datum", "Datum")
    Datum d1(2021, 7, 10, 21, 00);
    Datum d2;

    bool nagyobb = d1 > d2;

    EXPECT_EQ(true, nagyobb);

    END

    TEST("Vonat", "Jegy")

    Vonat vonat(100, 3, 10, "BUDAPEST", "MISKOLC", Datum(), Datum());
    vonat.hely_switch(3, 6);
    EXPECT_EQ(true, vonat.hely_check(3, 6));
    Node<Kocsi> *temp_delete = vonat.getKocsik();
    while(temp_delete != NULL){
        temp_delete->data->kocsi_exit();
        temp_delete = temp_delete->next;
    }
    vonat.vonat_exit();
    END
}
*/

int main() {


    int button;
    std::cout << "Program inditasahoz uzemmod valasztas:\n(1) Teszt program\n(2) Vonatjegy program" << std::endl;
    std::cin >> button;
    switch(button) {
        case 1: {
            //test();
            break;
        }
        case 2: {
            Program program;
            program.program_start();
            program.program_exit();
            break;
        }
        default: {
            std::cout << "Nem adott meg jo lehetoseget" << std::endl;
        }
    }
	return 0;
}