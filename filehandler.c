#include "filehandler.h"
#include "arrayoc.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct arrayoc arrayOc;

/* Extracts the content in the file
 * and outputs it into a char array
 */
char* extract_lines(FILE* arq) {
    return NULL;
}

/* Opens file 'name' in mode 'mode'.
 * Returns a FILE* to the opened file
 */
FILE* open_file(char* name, char* mode) {
    FILE* arq = fopen(name, mode);
    if (arq == NULL) {
        fprintf(stderr, "ERROR OPENING FILE");
        exit(34); // file error exit code
    }
    return arq;
}

/* Closes a 'arq' FILE*
 * Returns NULL, after closing file,
 * and exhibits success message
 */
FILE* close_file(FILE* arq) {
    fclose(arq);
    arq = NULL;
    printf("File closed\n");
    return arq;
}

/* Builds an occurrence array from a given file */
arrayOc* build_arrayOc(char* name, char* mode) {
    FILE* char_arq = open_file(name, mode);

    char* lines = extract_lines(char_arq);

    arrayOc* occurrences = extract_characters(lines);

    close_file(char_arq);

    return occurrences;
}

