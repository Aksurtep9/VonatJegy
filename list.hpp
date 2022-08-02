

#ifndef VONAT_CLION_LIST_HPP
#define VONAT_CLION_LIST_HPP

#include <iostream>
//#include "memtrace.h"

template<typename T>
struct Node{
    T *data;
    Node* next;


};

template<class T> class List{
    Node<T> *head;
public:

    List(){
        head = NULL;
    }

    List(const List& rhs) {
        (*this = rhs);
    }

    void add_node(T *data){

        if (head==NULL){
            head = new Node<T>;
            head->data=data;
            head->next = NULL;
        }
        else{
            Node<T> *tmp = new Node<T>;
            tmp->data=data;
            tmp->next=head;
            head = tmp;
        }
    }

    Node<T>* get_ListHead(){
        return head;
    }

    List& operator=(const List& rhs){
        if(this != &rhs) {
            if (rhs.head == NULL) {
                head = NULL;
            } else {
                Node<T> *tmp;
                tmp = rhs.head;
                while (tmp != NULL) {
                    this->add_node(tmp)
                    * tmp = tmp->next;
                }
            }
        }
        return *this;
    }

 /*   virtual ~List() {
        Node<T> *tmp = head;
        while(tmp != NULL){
            Node<T> *next = tmp->next;
            delete tmp;
            tmp = next;
        }
        head = NULL;
    }
*/

};


#endif //VONAT_CLION_LIST_HPP
