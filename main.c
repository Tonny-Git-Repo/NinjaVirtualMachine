#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

#define VERSION 2

FILE *fp;
char extens[4];
int vers;
int instructions;
int anzahlStatVar;
int *statDaA;
unsigned int *programm;

int main(int argc, char *argv[]) {

    fp = NULL;
    if (argv[1] != NULL) {

       if (strcmp(argv[1], "--help") == 0) {
           printf("%s\n %s\n %s\n %s\n %s\n %s\n", "usage: ./njvm [option] [option] ...",
                  "  --prog1\tselect program 1 to execute",
                  "  --prog2\tselect program 2 to execute", "  --prog3\tselect program 3 to execute",
                  "  --version\tshow version and exit", "  --help\tshow this help and exit");
       } else if (strcmp(argv[1], "--version") == 0) {
            printf("Ninja Virtual Machine version %d (compiled %s, %s)\n", VERSION, __DATE__, __TIME__);
       }else {
           fp = fopen(argv[1],"rb");
           if(fp == NULL){
               printf("Error beim Öffnen der Datei !\n");
           }else{
               fread(extens,sizeof(char), 4, fp);
               if(strcmp("NJBF",extens)!= 0){
                   printf("Error: file %s has wrong format\n",argv[1]);
               }else{
                   fread(&vers, sizeof(int), 1, fp );
                   if(vers != VERSION){
                       printf("Error: file %s has wrong version number\n", argv[1]);
                   }else{
                       fread(&anzahlStatVar, sizeof (int), 1, fp);
                       statDaA = malloc(anzahlStatVar * sizeof (unsigned int));

                       fread(&instructions, sizeof (int), 1, fp);
                       programm = malloc(instructions * sizeof (unsigned int));
                       fread(programm, sizeof (unsigned int), instructions, fp);
                       launchProzess(programm);
                       free(statDaA);
                   }
               }
           }
           fclose(fp);
       }
    } else {
        printf("Error : no program selected\n");
    }
    return 0;
}
