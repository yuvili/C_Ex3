#include <stdio.h>
#include <string.h>
#include "my_char.h"

#define TXT 1024
#define WORD 30

int main(){
    char word[WORD];
    char text[TXT];

    scanf("%30s", word);
    scanf("%[^'~']s", text);

    char* ans = Gematria_Sequences(text,word);
    printf("Gematria Sequences: %s",ans);
    printf("\n");
    char* ans1 = Atbash_Sequences(text,word);
    printf("Atbash Sequences: %s",ans1);
    printf("\n");
    // char* ans2 = Anagram_Sequences(text,word);
    // printf("\n");
    // printf("Anagram Sequences: %s",ans2);
    return 0;
}