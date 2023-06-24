/*File Copy: Write a C program to copy a file using file operations*/

#include<stdio.h>
#include<stdlib.h>


void copyFile(const char *source_file, const char *destination_file){
    FILE *fsource;
    FILE *fdestination;
    int ch;

    fsource = fopen(source_file,"rb");

    if(fsource == NULL){

        printf("Failed to open the Source file : %s\n",source_file);

        perror("Error");
        
        exit(EXIT_FAILURE);
    }

    fdestination = fopen(destination_file,"w+b");

    if(fdestination == NULL){

        printf("Failed to create the Destination file : %s\n",destination_file);

        perror("Error");

        fclose(fsource);
        
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fsource)) != EOF){

        if(fputc(ch, fdestination) == EOF){
            printf("Error occurred while writing to the destination file\n");

            fclose(fsource);

            fclose(fdestination);

            exit(EXIT_FAILURE);
        }
    }

    if(ferror(fsource)) {
        printf("Error occurred while reading from the source file\n");

        fclose(fsource);

        fclose(fdestination);

        exit(EXIT_FAILURE);
    }

    printf("Success the Source file contents is copied into Destination file\n");

    fclose(fsource);
    
    fclose(fdestination);
}
int main(){
    char source_file[25],destination_file[25];

    printf("Enter the Source file name\n");
    scanf("%24s",source_file);

    printf("Enter the Destination file name\n");
    scanf("%24s",destination_file);

    copyFile(source_file,destination_file);

    return 0;
}