//
// Created by tonny on 23.01.2022.
//
#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int stack[MAX_SIZE];
int sp = 0;



bool isEmpty(){
    if(sp < 0){
        return true;
    }else{
        return false;
    }
}


bool isFull(){
    if(sp == MAX_SIZE){
        return true;
    }else{
        return false;
    }
}


void pushs(int value) {
    if (isFull()) {
        printf("Stack already full!");
        exit(0);
    } else {
        stack[sp++] = value;
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty!");
        exit(0);
    } else {
        return stack[--sp];
    }
}