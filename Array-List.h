//
// Created by Boody on 4/9/2023.
//
#include <iostream>
#include <algorithm>
#ifndef DATAA2_ARRAY_LIST_H
#define DATAA2_ARRAY_LIST_H

#endif //DATAA2_ARRAY_LIST_H

using namespace std;

class List{
private:

    int size;
    int maxlength;
    int* content;

public:
    explicit List(int n){
        content = new int(n);
        maxlength=n;
        size=0;
    }
    int operator[](int n){
        return content[n];
    }
    void insert(int value){
        if (size>=maxlength){
            cout<<"Max size Reached";
        }else{
            content[size]=value;
            size++;
        }

    }
    void insertAt(int index, int value){
        if (size>=maxlength){
            cout<<"Max size Reached";
        }else{
            size++;
            int arr1[index];
            int arr2[size-index];
            for (int i = 0; i < index; ++i) {
                arr1[i]=content[i];
            }
            for (int i = index+1; i < size; ++i) {
                arr2[i]=content[i-1];
            }

            content = new int(size);
            for (int i = 0; i < index; ++i) {
                content[i]=arr1[i];

            }
            content[index]=value;
            for (int i = index+1; i < size; ++i) {
                content[i]=arr2[i];
            }

        }
    }
    void removeAt(int index){
        size--;
        int x=0;
        int arr[size];

        for (int i = 0; i < size+1; ++i) {
          arr[i]=content[i];
        }
        content = new int(size);
        for (int i = 0; i < size+1; ++i) {
            if (i==index){
                content[i]=arr[++x];
            }else{
                content[i]=arr[x];
            }
            x++;
        }


    }
    int retrieveAt(int index){
        return content[index];
    }
    void replaceAt(int index, int value){
       content[index]=value;
    }
    bool isItemAtEqual(int index, int value){
        return content[index]==value;
    }
    bool isEmpty(){
        return size==0;
    }
    bool isFull(){
        return size==maxlength;
    }
    int listSize(){
        return size;
    }
    int maxSize(){
        return maxlength;
    }
    void clear(){
        size=0;
    };
    void print(){
        for (int i = 0; i < size; ++i) {
            cout<<content[i]<<" - ";
        }
    }
};