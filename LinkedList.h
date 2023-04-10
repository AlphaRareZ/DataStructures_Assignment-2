//
// Created by
// Abdelrahman Taymour - 20210200
//
//
// on 4/8/2023.
//
#include <iostream>
#include <algorithm>
#ifndef DATAA2_LINKEDLIST_H
#define DATAA2_LINKEDLIST_H

#endif //DATAA2_LINKEDLIST_H
using namespace std;

struct Node
{
    int info{};
    Node* link{};
};


class linked{
private:
    Node* head;
    int size;
    Node* current{};
public:

    linked(){
        size=0;
        head= nullptr;
    }

    int retrieveAt(int index){
        Node* x=head;
        for (int i = 0; i < index-1; ++i) {
            x=x->link;
        }
        return x->info;

    }

    void replaceAt(int index,int value){
        Node* x=head;
        for (int i = 0; i < index-1; ++i) {
            x=x->link;
        }
        x->info=value;

    }

    //Insert At Tail
    void push(int n){
        if(size==0){
            Node currentnode;
            currentnode.info=n;
            currentnode.link= nullptr;
            head=&currentnode;
            current=head;
            size++;
        }
        else{
            Node* currentnod = new Node() ;
            currentnod->info=n;
            currentnod->link= nullptr;
            current->link=currentnod;
            current=currentnod;
            size++;

        }
    }
    //return size
    int linkedListSize(){
        return size;
    }

    bool isExist(int value){
        Node* x=head;

        for (int i = 0; i < size; ++i) {
            if (x->info==value) {
                return true;
            }else{
                x=x->link;
            }
        }
        return false;
    }

    bool isItemAtEqual(int value, int index){
        Node* x=head;
        for (int i = 0; i < index-1; ++i) {
            x=x->link;
        }
        if (x->info==value){
            return true;
        }else{
            return false;
        }
    }
    void removeAt(int index){
        Node* x=head;
        size--;
        for (int i = 0; i < index-2; ++i) {
            x=x->link;
        }

        x->link=x->link->link;
    }
    //removeAtHead
    void removeAtHead(){
        size--;
        head=head->link;
    }
    void removeAtTail(){
        Node* x=head;
        size--;
        for (int i = 0; i < size-1; ++i) {
            x=x->link;
        }
        x->link= nullptr;
    }
    int& operator[](int x){
        Node* y=head;
        for (int i = 0; i < x; ++i) {
            y=y->link;
        }
        return y->info;
    }
    void swapitems(int first, int second){
        Node* f=head;
        Node* s=head;
        for (int i = 0; i < first; ++i) {
            f=f->link;
        }
        for (int i = 0; i < second; ++i) {
            s=s->link;
        }
        swap(s->info,f->info);

    }
    //Insert at head
    void insertAtHead(int value){
        size++;
        Node cr;
        cr.info=value;
        Node* temp;
        temp=head;
        cr.link=temp;
        head=&cr;

    }


    //Insert At
    void insertAt(int index , int value){
        Node tmp;
        Node* cr=head;
        tmp.info=value;
        size++;
        for (int i = 0; i < index-1; ++i) {
            cr=cr->link;
        }

        tmp.link=cr->link;
        cr=head;
        for (int i = 0; i < index-1; ++i) {
            cr=cr->link;
        }

        cr->link=&tmp;
    }
    //Print
    void print(){
        Node* cr=head;
        for (int i = 0; i < size; ++i) {
            cout<<"->"<<cr->info;
            cr=cr->link;
        }
    }

    bool isEmpty(){
        return head== nullptr;
    }
    void clear(){
        size=0;
        head->link= nullptr;
    }


};
