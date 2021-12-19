#include <stdio.h>
#include <string.h>
#include "my_char.h"

#define TXT 1024
#define WORD 30

int main(){
    char word[WORD+1];
    char text[TXT+1];

    scanf("%30s",word);
    scanf("%[^'~']s",text);

    char* ans = Gematria_Sequences(text,word);
    printf("Gematria Sequences: %s\n",ans);
    char* ans1 = Atbash_Sequences(text,word);
    printf("Atbash Sequences: %s\n",ans1);
    char* ans2 = Anagram_Sequences(text,word);
    printf("Anagram Sequences: %s",ans2);
    return 0;
}