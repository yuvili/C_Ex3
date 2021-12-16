#include <stdio.h>
#include <string.h>

int gematria_value(char *str){
    int s_length = strlen(str);
    int ans = 0;
    for (int i = 0; i < s_length; i++){
        int temp = (int) str[i];

        if(temp > 64 && temp < 91){
            temp = temp - 64;
        }
        else if(temp > 96 && temp < 123){
            temp = temp - 96;
        }
        else{
            temp = 0;
        }
        ans = ans + temp;
    }
    return ans;
}

int gematria(char c){
    int temp_gv = (int) c;

    if(temp_gv > 64 && temp_gv < 91){
        temp_gv = temp_gv - 64;
    }
    else if(temp_gv > 96 && temp_gv < 123){
        temp_gv = temp_gv - 96;
    }
    else{
        temp_gv = 0;
    }
    return temp_gv;
}

char* Gematria_Sequences(char* text, char* word){
    int word_gv = gematria_value(word);
    char dest[1024];
    char temp_ans[1024];
    int len = (int) strlen(text);

    for (int i = 0; i < len; i++){
        int temp_gv = gematria(text[i]);

        if(temp_gv < word_gv){
            if(strcmp(dest,"\000") == 0 && temp_gv == 0){
                temp_gv == 0;
            }
            else{
                strncat(dest, &text[i], 1);
            }
        }
        else if(temp_gv == word_gv){
            strncat(temp_ans, &text[i], 1);
            strcat(temp_ans, "~");
        }
        else if(temp_gv > word_gv){
            memset(dest,0,strlen(dest));
        }

        int dest_gv = gematria_value(dest);
        if (dest_gv == word_gv){
            strcat(temp_ans, dest);
            strcat(temp_ans, "~");

            i = i - strlen(dest) + 1;
            memset(dest,0,strlen(dest));
        }
        else if(dest_gv > word_gv){
            i = i - strlen(dest) + 1;
            memset(dest,0,strlen(dest));
        }
    }
    temp_ans[strlen(temp_ans) -1] = '\0';
    char* ans = temp_ans;
    return ans;
}

 int number_of_AB(char* str){
    int ans = 0;
     for (int i = 0; i < strlen(str); ++i) {
         if(gematria(str[i]) != 0){
             ans++;
         }
     }
     return ans;
}

 char* Atbash_Sequences(char *text,char *word){
     int word_len = number_of_AB(word);
     int s_length = (int) strlen(word);
     char word_at[s_length];
     char flipped_at[s_length];
     int temp = 0;

     for (int i = 0; i < s_length; i++){
         int current_ascii = (int) word[i];
         int current_asciiF = (int) word[s_length - 1- i];

         if(current_ascii > 64 && current_ascii < 91){
             temp = 90 + 65 - current_ascii;
             word_at[i] = temp;
         }
         else if(current_ascii > 96 && current_ascii < 123){
             temp = 122 + 97 - current_ascii;
             word_at[i] = temp;
         }

         if(current_asciiF > 64 && current_asciiF < 91){
             temp = 90 + 65 - current_asciiF;
             flipped_at[i] = temp;
         }
         else if(current_asciiF > 96 && current_asciiF < 123){
             temp = 122 + 97 - current_asciiF;
             flipped_at[i] = temp;
         }
     }

     char dest[s_length];
     char temp_ans[1024];
     int len = (int) strlen(text);

     for (int i = 0; i < len; i++) {
         strncat(dest, &text[i], 1);
         int dest_len = number_of_AB(dest);

         if ((dest[0] != word_at[0]) && (dest[0] != flipped_at[0])) {
             memset(dest, 0, strlen(dest));
         } else {
             if (dest_len == word_len) {
                 int equals_atbash = strcmp(dest, word_at);
                 int equals_flipped_atbash = strcmp(dest, flipped_at);

                 if (equals_flipped_atbash == 0 || equals_atbash == 0) {
                     strcat(temp_ans, dest);
                     strcat(temp_ans, "~");

                     i = i - strlen(dest) + 1;
                     memset(dest, 0, strlen(dest));
                 }
             } else if (dest_len > word_len) {
                 i = i - strlen(dest) + 1;
                 memset(dest, 0, strlen(dest));
             }
         }
     }
     temp_ans[strlen(temp_ans) -1] = '\0';
     char* ans = temp_ans;
     return ans;
 }

// char* Anagram_Sequences(char *text,char *word){
//
// }