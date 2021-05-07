#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

void vergleichen(char buffer[255], char *argv){
    if(NULL != strstr(buffer,argv)){
        printf("%s", buffer);
    }
}

void vergleichenIgnore(char buffer[255], char *argv){
    if(NULL != strcasestr(buffer,argv)){
        printf("%s", buffer);
    }
    
}

int main(int argc, char *argv[]){
    int i;
    int j;
    FILE *datei;
    char buffer [255];
    char c;

    if (argc < 3 || argc > 4){
        printf("Fehlerhafte Eingabe");
    
    
    }else{

        if (argc == 3){
            datei = fopen (argv[1], "r");
            if (NULL == datei){                         
                printf("Datei konnte nicht gefunden werden!");
                return -1;
            }
        
            while(fgets(buffer, 255, datei) !=  NULL){
                vergleichen(buffer, argv[2]);
            }
            



        }
        if (argc == 4){
            //for (j = 0; argv[1][j] != '\0'; j++){}//printf("Zahl: %d \n", j);
            if(argv[1][0]=='-'&& argv[1][1]=='i'){     //j == 1 && argv[1][0] == '-' && argv[1][1] == 'i'){
                datei = fopen (argv[2], "r");    
                if (NULL == datei){
                    printf("Datei konnte nicht gefunden werden!");
                    return -1;
                }
                while(fgets(buffer, 255, datei) !=  NULL){
                vergleichenIgnore(buffer, argv[3]);
            }
                
            







            }else{
                printf("Falsche Parameter eigegeben");
            }
    
        }
    };
    /*}
    //char myString[] = {*argv[1], '\0'};

    //int länge = argv.length();
    for (i = 0; i < argc; i++){
        printf("Stelle %i: %s \n", i, argv[i]);   
    }

    printf("Stelle 1: %s \n", argv[1]);


    for (j = 0; argv[0][j] != '\0'; j++){
        printf("Zahl: %d \n", j);
    };
    char hilfsarray[j];
    
    for (i = 0; i < j; i++){
        hilfsarray[i] = argv[0][i];
    }

    printf("Hilfsarray: %s \n", hilfsarray);
   // for (i = 0; *argv[i] != 's'; i++);
    //printf("Länge: %d Zeichen", i);

    //

    //


    //printf("%s \n", myString);
    }
    */
    return 0;
}
