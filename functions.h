//
// Created by tonny on 27.11.2021.
//

#ifndef NVM_FUNCTIONS_H
#define NVM_FUNCTIONS_H

#define IMMEDIATE(x) ((x) & 0x00FFFFFF)
#define SIGN_EXTEND(i) ((i) & 0x00800000 ? (i) | 0xFF000000 : (i))

#define HALT 0
#define PUSHC 1
#define ADD 2
#define SUB 3
#define MUL 4
#define DIV 5
#define MOD 6
#define RDINT 7
#define WRINT 8
#define RDCHR 9
#define WRCHR 10
int launchProzess(unsigned int *prog);
void execute(unsigned int instruction);
void showExecution(unsigned int *prog);
extern int pc;
extern unsigned int code1[];
extern unsigned int code2[];
extern unsigned int code3[];

#endif //NVM_FUNCTIONS_H
