#include <stdio.h>
#include "my_char.h"

#define TXT 1024
#define WORD 30

int main(){
    char word[WORD+1];
    char text[TXT+1];

    scanf("%30s",word);
    scanf("%[^'~']s",text);

    Gematria_Sequences(text,word);
    Atbash_Sequences(text,word);
    Anagram_Sequences(text,word);
    return 0;
}