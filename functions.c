//
// Created by tonny on 23.01.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int pc = 0;

unsigned int code1[] = {
        (PUSHC << 24) | IMMEDIATE(3),
        (PUSHC << 24) | IMMEDIATE(4),
        (ADD << 24),
        (PUSHC << 24) | IMMEDIATE(10),
        (PUSHC << 24) | IMMEDIATE(6),
        (SUB << 24),
        (MUL << 24),
        (WRINT << 24),
        (PUSHC << 24) | IMMEDIATE(10),
        (WRCHR << 24),
        (HALT << 24)
};

unsigned int code2[] = {
        (PUSHC << 24) | IMMEDIATE(-2),
        (RDINT << 24),
        (MUL << 24),
        (PUSHC << 24) | IMMEDIATE(3),
        (ADD << 24),
        (WRINT << 24),
        (PUSHC << 24) | IMMEDIATE('\n'),
        (WRCHR << 24),
        (HALT << 24)
};

unsigned int code3[] = {
        (RDCHR << 24),
        (WRINT << 24),
        (PUSHC << 24) | IMMEDIATE('\n'),
        (WRCHR << 24),
        (HALT << 24)
};

int halt(){
    return 0;
}

void pushc(int value){
    pushs(value);
}

void add(){
    pushc(( pop() + pop() ));
}

void sub(){
    int temp = pop();
    pushc((pop()-temp));
}

void mul(){
    pushc((pop() * pop()));
}

void divi(){
    int divident = pop();
    int divisor = pop();
    if(divident == 0 ){
        printf("Exception: Divisor is 0\n");
    }else{
        pushc((divident/divisor));
    }
}

void mod(){
    int temp = pop();
    pushc( pop()%temp);
}

void rdint(){
    int value;
    scanf("%d", &value);
    pushc(value);
}

void wrint(){
    printf("%d", pop());
}

void rdchr(){
    char charVal;
    scanf("%c", &charVal);
    pushc(charVal);
}


void rwchr(){
    printf("%c", pop());
}

int launchProzess(unsigned int *prog){
    printf("Ninja Virtual Machine started\n");
    showExecution(prog);
    while(prog[pc] >>24 != HALT){
        unsigned int instruction = prog[pc];
        pc++;
        execute(instruction);
    }

    if(prog[pc] >> 24 == HALT){
        halt();
        printf("Ninja Virtual Machine stopped\n");
    }

    return 0;
}

void execute(unsigned int instr){
    int opcode = instr >> 24;

    switch(opcode){
        case HALT:
            halt();
            break;
        case PUSHC:
            pushc(SIGN_EXTEND(IMMEDIATE(instr)));
            break;
        case ADD:
            add();
            break;
        case SUB:
            sub();
            break;
        case MUL:
            mul();
            break;
        case DIV:
            divi();
            break;
        case MOD:
            mod();
            break;
        case RDINT:
            rdint();
            break;
        case WRINT:
            wrint();
            break;
        case RDCHR:
            rdchr();
            break;
        case WRCHR:
            rwchr();
            break;
    }
}


void showExecution(unsigned int *prog){
    int idx = 0;
    int opcode;
    do{
        printf("%03d:\t", idx);
        opcode = prog[idx] >> 24;
        switch(opcode){
            case HALT:
                printf("halt\n");
                break;
            case PUSHC:
                printf("pushc\t%d\n", SIGN_EXTEND(IMMEDIATE(prog[idx])));
                break;
            case ADD:
                printf("add\n");
                break;
            case SUB:
                printf("sub\n");
                break;
            case MUL:
                printf("mul\n");
                break;
            case DIV:
                printf("div\n");
                break;
            case MOD:
                printf("mod\n");
                break;
            case RDINT:
                printf("rdint\n");
                break;
            case WRINT:
                printf("wrint\n");
                break;
            case RDCHR:
                printf("rdchr\n");
                break;
            case WRCHR:
                printf("wrchr\n");
                break;
        }
        idx++;
    }while(opcode != HALT);

}


