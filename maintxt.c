#include <stdio.h>
#include <strings.h>


#define WORD 30
#define LINE 256
void print_lines(char* line,char *str);
void print_words(char* text,char *str);
int substring(char* str1,char* str2);
int get_word(char *text ,char* word);
int get_line(char *line);

int main() {
    char text[LINE];
    int end;
    bzero(text, LINE);
    get_line(text);
    char word[WORD];
    bzero(word,WORD);
    int i = get_word(text, word);
    if (*(text + i) == 'a') {
        bzero(text,LINE);
        get_line(text);
        bzero(text,LINE);
        for (int j = 0; j < 248; ++j) {
            end = get_line(text);
            print_lines(text, word);
            if (end == -1)
                break;
            bzero(text, LINE);
        }
    } else {
        bzero(text,LINE);
        get_line(text);
        for (int j = 0; j < 248; ++j) {
            bzero(text,LINE);
            end = get_line(text);
            print_words(text, word);
            if (end == -1)
                break;
        }
    }
        return 0;
    }
    int get_line(char *line) {
        int i = 0;
        do {
            scanf("%c", (line + i));
            if (*(line + i) == '\0' && *(line + i) == EOF)
                return -1;
            i++;
        } while (*(line + i-1) != '\n' && i < 256 && *(line + i-1) != '\r');
        return 1;
    }

    int substring(char *str1, char *str2) {
        int i = 0, j = 0, wrang = 0;
        while (i < sizeof(str1)) {
            if (*(str1 + i) == *(str2 + j) ||
                (*(str1 + i) <= 'z' && *(str1 + i) >= 'a' && (*(str1 + i) - 'a' + 'A') == *(str2 + j)) || (
                        *(str1 + i) >= 'A' && *(str1 + i) <= 'Z' && (*(str1 + i) - 'A' + 'a' == *(str2 + j)))) {
                i++;
                j++;
                continue;
            }
            if (*(str1 + i) == '\n' || *(str1 + i) == ' ' || *(str1 + i) == '\t' || *(str1 + i) == '\r' ||
                *(str1 + i) == '\0') {
                wrang += 2;
                break;
            }
            wrang++;
            i++;
        }
        if (wrang < 2)
            return 1;
        return 0;
    }
    void print_lines(char *line, char *str) {

        char *temp = line;
        char word[WORD];
        bzero(word, WORD);
        while (line - temp < 256 && *line != '\0') {
            line += get_word(line, word);
            if (substring(word, str)) {
                printf("%s", temp);
                break;
            }
            bzero(word, WORD);
        }
    }
    int get_word(char *text, char *word) {
        int i = 0;
        while (*(text + i) != '\t' && *(text + i) != ' ' && *(text + i) != '\n' && *(text + i) != '\r' &&
               *(text + i) != '\0') {
            *(word + i) = *(text + i);
            i++;
        }
        return i + 1;
    }
    void print_words(char *text, char *str) {
        char word[WORD];
        bzero(word, 30);
        while (*text != '\0') {
            text += get_word(text, word);
            if (substring(word, str) ) {
                printf("%s\n", word);
            }
            bzero(word, 30);
        }
    }
