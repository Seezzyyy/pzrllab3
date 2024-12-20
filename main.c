#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <operation> <arguments...>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *operation = argv[2];

    FILE *input = fopen(input_file, "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen("output.txt", "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    char line[MAX_LINE_LENGTH];

if (strcmp(operation, "-r") == 0) {
        if (argc < 5) {
            fprintf(stderr, "Usage: %s <input_file> -r <old_text> <new_text>\n", argv[0]);
            fclose(input);
            fclose(output);
            return 1;
        }
        const char *old_text = argv[3];
        const char *new_text = argv[4];
        while (fgets(line, sizeof(line), input)) {
            replace_text(line, old_text, new_text, output);
        }
    } else if (strcmp(operation, "-d") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s <input_file> -d <text_to_delete>\n", argv[0]);
            fclose(input);
            fclose(output);
            return 1;
        }
        const char *text_to_delete = argv[3];
        while (fgets(line, sizeof(line), input)) {
            delete_lines(line, text_to_delete, output);
            }
    } else if (strcmp(operation, "-i") == 0) {
        if (argc < 5) {
            fprintf(stderr, "Usage: %s <input_file> -i <-f|-b> <insert_text>\n", argv[0]);
            fclose(input);
            fclose(output);
            return 1;
        }
        int at_front = strcmp(argv[3], "-f") == 0;
        const char *insert_text_val = argv[4];
        while (fgets(line, sizeof(line), input)) {
            insert_text(line, insert_text_val, at_front, output);
        }
    } else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
        fclose(input);
        fclose(output);
        return 1;
    }

    fclose(input);
    fclose(output);

    printf("Operation completed. Output written to: output.txt\n");
    return 0;