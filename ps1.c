#include<stdio.h>
#include<malloc.h>

void small_case_converter(char *, int);
char* dup_remover(char *, int *);
int dup_checker(char *, char);
void remove_space(char *, int);

int main() {
    char *inp = (char*)malloc(sizeof(char));
    char c;
    int inp_size = 0, ans_size = 0;
    printf("Enter string : ");
    while(scanf("%c", &c) == 1 && c != '\n') {
        inp[inp_size] = c;
        inp_size++;
        inp = (char*)realloc(inp, sizeof(char) * (inp_size + 1));
    }
    if (inp_size == 0) {
        printf("Empty expression");
        return 0;
    }
    inp[inp_size] = '\0';
    small_case_converter(inp, inp_size);
    char *ans = dup_remover(inp, &ans_size);
    // remove_space(ans, ans_size);

    return 0;
}

void small_case_converter(char *str, int str_size) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

char* dup_remover(char *inp, int *str_size) {
    char *str = (char*)malloc(sizeof(char));
    *str_size = 0; // Initialize size

    for (char *c = inp; *c != '\0'; c++) {
        if (*c == ' ') {
            str[*str_size] = ' ';
            (*str_size)++;
            str = (char*)realloc(str, sizeof(char) * (*str_size + 1));
        } else if (dup_checker(str, *c)) {
            str[*str_size] = *c;
            (*str_size)++;
            str = (char*)realloc(str, sizeof(char) * (*str_size + 1));
        }
    }

    str[*str_size] = '\0'; // Null-terminate the string
    remove_space(str, *str_size); // Remove redundant spaces
    printf("After removing duplicate characters: %s", str);
    return str;
}

void remove_space(char* str, int str_size) {
    int indx = 0, i = 0;

    // Remove leading spaces
    while (i < str_size && str[i] == ' ') i++;

    // Remove trailing spaces
    int end = str_size - 1;
    while (end >= 0 && str[end] == ' ') end--;

    // Update string to remove spaces between words
    int first_space = 1;
    while (i <= end) {
        if (str[i] != ' ') {
            str[indx++] = str[i];
            first_space = 1;
        } else if (first_space) {
            str[indx++] = ' ';
            first_space = 0;
        }
        i++;
    }
    str[indx] = '\0';
}

int dup_checker(char *str, char c) {
    for (char *temp = str; *temp != '\0'; temp++) {
        if (c == *temp) return 0;
    }
    return 1;
}
