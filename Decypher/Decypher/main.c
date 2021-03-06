#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*char *Create(int length){
    char *c = (char*)malloc(sizeof(length))
}*/

int main()
{
    /* Initializing variables */
    FILE *sourcefile;
    FILE *decfile;
    char c;
    int i=0;
    int len=0;
    char name[200];
    char decname[200];

    printf("Enter file's name to encode\n");
    scanf("%s", name);
    len=strlen(name);
    decname[0]='D';
    decname[1]='e';
    decname[2]='c';
    for (i=3;i<len-1;i++){
        decname[i]=name[i-3];
    }
    decname[i+0]='.';
    decname[i+1]='d';
    decname[i+2]='e';
    decname[i+3]='c';
    decname[i+4]='\n';
    i+=4;
    while(i<200){
        decname[i]=0;
        i++;
    }

    sourcefile=fopen(name, "r");
    if (sourcefile == NULL){
            printf("File opening error, run program as administrator or contact with developer.\n");
            return -1;
    }
    else {
            printf("Source opening successful\n\n");
    }

    decfile=fopen(decname, "w");
    if (decfile == NULL){
            printf("DecFile opening error, run program as administrator or contact with developer.\n");
            return -2;
    }
    else {
            printf("Dec opening successful\n\n");
    }

    while(1)
   {
        c = fgetc(sourcefile);
        if( feof(sourcefile) ){
            break ;
        }
        //Encrypt here
        if ((c=='\n')||(c=='\0')){
            fprintf(decfile, "%c", c);
        }
        else {
            fprintf(decfile, "%c", c+1);
        }
    }
    fclose(sourcefile);
    fclose(decfile);

    printf("Encoded file: ");
    printf("%s\n", decname);

    printf("Press any button to close the program\n");
    scanf("%c\n", &c);
    //printf("%s\n", name);
    //printf("%d\n", len);


    return 0;
}
