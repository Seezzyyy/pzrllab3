// func.h
#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>

void replace_text(const char *line, const char *old_text, const char *new_text, FILE *output);
void delete_lines(const char *line, const char *text_to_delete, FILE *output);
void insert_text(const char *line, const char *insert_text, int at_front, FILE *output);

#endif