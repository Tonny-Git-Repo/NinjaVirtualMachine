#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION 0

int main(int argc, char * argv[]) {

    if(argv[1] != NULL) {
        if(strcmp(argv[1], "--help") == 0){
            printf("%s\n  %s\n  %s","usage: ./njvm [option] [njvm] ...",
                   "--version\t\tshow version and exit", "--help\t\tshow this help and exit");
        }else if(strcmp(argv[1],"--version") == 0){
            printf("Ninja Virtual Machine version %d (compiled %s, %s)", VERSION, __DATE__, __TIME__);
        }else{
            printf("unknown command line argument '--%s', try './njvm --help'", argv[1]);
        }
    }else{
        printf("%s\n%s", "Ninja Virtual Machine started", "Ninja Virtual machine stopped");
    }
    return 0;
}
