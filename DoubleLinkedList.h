//
// Created by Boody on 4/8/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;
#ifndef DATAA2_DOUBLELINKEDLIST_H
#define DATAA2_DOUBLELINKEDLIST_H

#endif //DATAA2_DOUBLELINKEDLIST_H

class doubleLinkedList{
private:
    struct Node{
        Node *next{};
        Node *previous{};
        int data{};
        explicit Node(int data):data(data){};
    };

private:
    Node *head{};
    Node *tail{};
    int size=0;

public:
    void push(int val){
        size++;
        Node * temp = new Node(val);
        if(!head && !tail){
            head = tail = temp;
        }


        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }

    void print(){
        for(Node* cur = head; cur != nullptr; cur = cur->next)
            cout<<cur->data<<" ";

    }


    void reverse(){
        for(Node* cur=head; cur!=nullptr;){
            Node*temp = cur->next;
            cur->next = cur->previous;
            cur->previous = temp;
            cur = cur->previous;
        }
        Node* t = head;
        head = tail;
        tail = t;
        tail->next= nullptr;

    }

    void insertAtHead(int value){
        size++;
        Node cr(value);

        Node* temp;
        temp=head;
        cr.next=temp;
        cr.previous= nullptr;
        head=&cr;
    }

    void insertAt(int index,int value){
        Node tmp(value);
        Node* cr=head;

        size++;
        for (int i = 0; i < index-1; ++i) {
            cr=cr->next;
        }

        tmp.next=cr->next;
        tmp.previous=cr->previous;
        cr=head;
        for (int i = 0; i < index-1; ++i) {
            cr=cr->next;
        }

        cr->next=&tmp;
    }
    /*
     * Insert After is the same as Insert At !!??
     */

    void removeAtHead(){
        size--;
        head=head->next;
        head->previous= nullptr;
    }

    void removeAtTail(){
        Node* tmp;
        tmp=head;
        size--;
        for (int i = 0; i < size-1; ++i) {
            tmp=tmp->next;
        }
        tmp->next= nullptr;
        tail=tmp;
    }

    void removeAt(int index){
        Node* tmp;
        tmp=head;
        size--;
        for (int i = 0; i < index-1; ++i) {
            tmp=tmp->next;
        }
        tmp->next=tmp->next->next;
        tmp->next->previous=tmp;
    }

    int retrieveAt(int index){
        Node* tmpr;
        tmpr=head;
        for (int i = 0; i < index-1; ++i) {
            tmpr=tmpr->next;
        }
        return tmpr->data;
    }

    void replaceAt(int index,int value){
        Node* tmpr;
        tmpr=head;
        for (int i = 0; i < index-1; ++i) {
            tmpr=tmpr->next;
        }
        tmpr->data=value;
    }

    bool isExist(int value){
        Node* x=head;

        for (int i = 0; i < size; ++i) {
            if (x->data==value) {
                return true;
            }else{
                x=x->next;
            }
        }
        return false;
    }

    bool isItemAt(int index,int value){
        Node* x=head;
        for (int i = 0; i < index-1; ++i) {
            x=x->next;
        }
        if (x->data==value){
            return true;
        }else{
            return false;
        }
    }

    void swapItems(int first , int second){
        Node* f=head;
        Node* s=head;
        for (int i = 0; i < first; ++i) {
            f=f->next;
        }
        for (int i = 0; i < second; ++i) {
            s=s->next;
        }
        swap(s->data,f->data);
    }

    bool isEmpty(){
        return size==0;
    }

    void clear(){
        size=0;
        head->next= nullptr;
        tail->previous= nullptr;
    }

    int getSize(){
        return size;
    }

    void forwardTraversal(){
        this->print();
    }

    void backwardTraversal(){
        Node* ptr=tail;
        for (int i = 0; i < size; ++i) {
            cout<<ptr->data<<",";
            ptr=ptr->previous;
        }
    }
};