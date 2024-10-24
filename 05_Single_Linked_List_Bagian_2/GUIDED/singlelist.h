#include <iostream> 

using namespace std;

struct Elemen{
    int data;
    Elemen *next;
};

struct List{
    Elemen *first;
};

void createList(List &L){
    L.first = NULL;
}

Elemen *alokasi(int x){
    Elemen *p = new Elemen;
    if(p == NULL){
        return NULL;
    }else{
        p->data = x;
        p->next = NULL;
        return p;
    }
}

void insertFirst(List &L, Elemen *p){
    p->next = L.first;
    L.first = p;
}

void insertLast(List &L, Elemen *p){
    if(L.first == NULL){
        L.first = p;
    }else{
        Elemen *last = L.first;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = p;
    }
}

Elemen *findElm(List L, int x){
    Elemen *p = L.first;
    while(p != NULL){
        if(p->data == x){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Elemen *sumAllElemenst(List L){
    int total = 0;
    Elemen *p = L.first;
    while(p != NULL){
        total += p->data;
        p = p->next;
    }
    return total;
}


