#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define BUFFSIZE 1024
#define TOKEN_DELIM " \t\r\n\a"

extern char **environ;

/* mode.c */
void interactive_sh(void);
void non_interactive_sh(void);

/* _execvpe.c */
int _execvpe(const char *cmd, char *argv[], char *const envp[]);

/* _strtok.c */
char *_strtok(char *input, const char *delim);

/* _getline.c */
ssize_t _getline(char **lineptr, size_t *alloc_size, FILE *input);
ssize_t _eof(char **lineptr, size_t tracker);

/* strings.c */
const char *_strchr(const char *s, int c);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strdup(const char *s);
char *_strcpy(char *dest, const char *src);

/* Strings1.c */
int _strncmp(const char *s1, const char *s2, size_t n);

/* _realloc.c */
void *_realloc(void *ptr, size_t new_size);

/* _F_OK.c */
int _f_ok(char *cmd);

/* builtin1.c */
int __exit(char **args);
int __env(char **args);
int _setenv(const char *name, const char *value, int overwrite);
int is_setenv(char **args);
int _putenv(char *name_value);

/* read_input.c */
char *read_input(int *eof_status);

/* parse_input.c */
char **parse_input(char *input, int *token_status);

/* builtin2.c */
int is_builtin(char **args);
int _unsetenv(char *name);

/* getenv */
char *_getenv(const char *name);

#endif
