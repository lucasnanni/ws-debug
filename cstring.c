#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int len;
} CString;

CString *Init_CString(char *str)
{
    CString *p = malloc(sizeof(CString));
    p->len = strlen(str);
    strncpy(p->str, str, strlen(str) + 1);
    return p;
}

void Delete_CString(CString *p)
{
    free(p);
    free(p->str);
}

// Remove o último caractere da CString e retorna ele

char Chomp(CString *cstring)
{
    char lastchar = cstring->str[cstring->len];
    // Encurta string em um char
    cstring->str[cstring->len] = '0';
    cstring->len = strlen(cstring->str);

    return lastchar;
}

// Concatena uma string (char *) a uma CString

CString *Append_To_CString(CString *p, char *str)
{
    char *newstr = malloc(p->len + 1);
    p->len = p->len + strlen(str);
    
    // Cria a nova string para substituir p->str
    snprintf(newstr, p->len, "%s%s", p->str, str);
    
    // Libera a string antiga e faz CString apontar para a nova string
    free(p->str);
    p->str = newstr;
    
    return p;
}

int main(void)
{
    CString *mystr;
    char c;
    
    mystr = Init_CString("Hello!");
    printf("Init:\n str: '%s' len: %d\n", mystr->str, mystr->len);
    
    c = Chomp(mystr);
    printf("Chomp '%c':\n str:'%s' len: %d\n", c, mystr->str, mystr->len);
    
    mystr = Append_To_CString(mystr, " world!");
    printf("Append:\n str: '%s' len: %d\n", mystr->str, mystr->len);
    
    Delete_CString(mystr);
    return 0;
}