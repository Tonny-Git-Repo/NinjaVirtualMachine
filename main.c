#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "stack.h"
#include "functions.h"

#define VERSION 1


int main(int argc, char *argv[]) {

    if (argv[1] != NULL) {

       if (strcmp(argv[1], "--help") == 0) {
           printf("%s\n %s\n %s\n %s\n %s\n %s\n", "usage: ./njvm [option] [option] ...",
                  "  --prog1\tselect program 1 to execute",
                  "  --prog2\tselect program 2 to execute", "  --prog3\tselect program 3 to execute",
                  "  --version\tshow version and exit", "  --help\tshow this help and exit");
       } else if (strcmp(argv[1], "--version") == 0) {
            printf("Ninja Virtual Machine version %d (compiled %s, %s)\n", VERSION, __DATE__, __TIME__);
       }else if (strcmp(argv[1], "--prog1") == 0){
           launchProzess(code1);
       }else if (strcmp(argv[1], "--prog2") == 0){
           launchProzess(code2);
       }else if (strcmp(argv[1], "--prog3") == 0){
           launchProzess(code3);
       }else {
           printf("unknown command line argument '--%s', try './njvm --help'\n", argv[1]);
       }

    } else {
        printf("Error : no program selected\n");
    }
    return 0;
}
