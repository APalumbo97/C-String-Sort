/*
 * Author: Anthony Palumbo
 * Date: 11-10-16
 * Description: Bubble sort of strings without case sensitivity taking file input.
 */

#include <stdio.h>
#include <string.h>
#define NUM 25000	//The maximum number of input strings.
#define MAX_SIZE 256	//The maximum number of characters of the input strings.

/*
 * Sorts the strings in the file, returns 0 on completion.
 */
int main(void) {
    char input[NUM][MAX_SIZE], temp[MAX_SIZE], filename[MAX_SIZE];
    int a, b;
    int ctr = 0;

    //Gathers the input strings.
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE *myFile = fopen(filename, "r");
    int scan = fscanf(myFile, "%s", temp);
    while(scan != -1) {
        strcpy(input[ctr], temp);
        ctr++;
        scan = fscanf(myFile, "%s", temp);
    }

    //Sorts the strings.
    for(a = 0; a < ctr-1; a++) {
        for(b = 0; b < ctr-1; b++) {
            if(strcasecmp(input[b], input[b+1]) > 0) {
                strcpy(temp, input[b]);
                strcpy(input[b], input[b+1]);
                strcpy(input[b+1], temp);
            }
        } 
    }

    //Prints the sorted strings.
    printf("\nSorted strings:\n");
    for(a = 0; a < ctr; a++) {
        printf("%s\n", input[a]);
    }

    fclose(myFile);
    return 0;
}
