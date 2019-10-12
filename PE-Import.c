#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

int isFileExists(const char *path, const char *str);
int hasString(FILE *fp, const char *str);

int main()
{
    char path[] = "PE-1.txt";
    char string[] = "I want to learn PE file format!";
    char buff[1000];
    char temp;
    ssize_t read;

    // Tries to open file for r/w or will create one if does not exist
    FILE *fptr = fopen(path, "ab+");
    
    
    // Checks to see if file has string and if yes then prints all contents otherwise appends the string to file
    if(hasString(fptr, string))
    {
        while (fgets(buff, 512, fptr) != NULL){
        	printf ("%s", buff);
        }
    } else {
        fprintf(fptr, "%s", string);  
    }
    
    //close the file
    fclose(fptr);
    return 0;
}

int hasString(FILE *fp, const char *str){
	char buff[1000];
	while(fgets(buff, 512, fp) != NULL) {
        if((strstr(buff, str)) != NULL) {
            return 1;
        }
    }
    return 0;
	
}
