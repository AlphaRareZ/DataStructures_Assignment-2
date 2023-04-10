//
// Created by Boody on 4/10/2023.
//
#include <iostream>
#include <algorithm>
#ifndef DATAA2_STACK_H
#define DATAA2_STACK_H

#endif //DATAA2_STACK_H

using namespace std;

class Stack{
private:
    int size=0;
    int* arr;
    int max;
public:
    Stack(int n){
        size=0;
        arr=new int[n];
        max=n;
    }
    void top(){
        cout<<arr[size-1]<<endl;
    }
    void pop(){
        if(size !=0){
            cout<<arr[size-1]<<endl;
            size--;
        }
    }
    void clear(){
        size=0;
    };
    bool isEmpty(){
        return (size==0);
    }
    void push(int x){

        if (size <= max)
        {
            size++;
            arr[size-1]=x;

        }else{
            cout<<"Stack is Full !";
        }

    }

    int stackSize(){
        return size;
    }

};
