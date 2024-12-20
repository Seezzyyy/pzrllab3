#include <stdio.h>
#include <string.h>
#include "func.h"

void replace_text(const char *line, const char *old_text, const char *new_text, FILE *output) {
    const char *pos = line;
    while ((pos = strstr(pos, old_text)) != NULL) {
        fwrite(line, 1, pos - line, output);
        fprintf(output, "%s", new_text);
        pos += strlen(old_text);
        line = pos;
    }
    fprintf(output, "%s", line);
}

void delete_lines(const char *line, const char *text_to_delete, FILE *output) {
    if (strstr(line, text_to_delete) == NULL) {
        fprintf(output, "%s", line);
    }
}

void insert_text(const char *line, const char *insert_text, int at_front, FILE *output) {
    if (at_front) {
        fprintf(output, "%s%s", insert_text, line);
    } else {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            fprintf(output, "%.*s%s\n", (int)(len - 1), line, insert_text);
        } else {
            fprintf(output, "%s%s", line, insert_text);
        }
    }
}