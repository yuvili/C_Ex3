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
int equals(char* word, char* check){
    int len = (int) strlen(check);
    int i = 0;
    int j = 0;
    int b = 0;

    while(j<len){
        if(word[i] == check[j]){
            b = 0;
            i++;
            j++;
        }
        else if(check[i] == 32){
            i --;
            j++;
        }
        else{
            return 1;
        }
    }
    return b;
}

 char* Atbash_Sequences(char *text,char *word){
     int word_len = number_of_AB(word);
     int s_length = (int) strlen(word);
     char word_at[s_length+1];
     char flipped_at[s_length+1];
     int temp = 0;

     for (int i = 0; i < s_length ; i++){
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
     flipped_at[s_length] = '\000';
     char dest[60];
     char temp_ans[1024];
     int len = (int) strlen(text);

     for (int i = 0; i < len; i++) {
         strncat(dest, &text[i], 1);
         int dest_len = number_of_AB(dest);

         if ((dest[0] != word_at[0]) && (dest[0] != flipped_at[0])) {
             dest[0] = 0;
         } else {
             if (dest_len == word_len) {
                 strncat(dest, &flipped_at[s_length], 1);

                 int equals_atbash = equals(word_at,dest);
                 int equals_flipped_atbash = equals(flipped_at, dest);

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

int number_of_symbols(char* str){
    int ans = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if(str[i] != 32){
            ans++;
        }
    }
    return ans;
}
int anagram(int (*chars)[95], char* check){
    int len = (int) strlen(check);
    int temp_chars[95] = {'\0'};

    for (int i = 0; i < len; ++i) {
        if(check[i] != 32) {
            int ascii = (int) check[i] - 33;
            temp_chars[ascii] +=1;
            if ((*chars)[ascii] == 0) {
                return 1;
            }
        }
    }
    for (int i = 0; i < 95; ++i) {
        if((*chars)[i] != temp_chars[i]){
            return 1;
        }
    }
    return 0;
}
char* Anagram_Sequences(char *text,char *word){
    int word_len = (int) strlen(word);
    int chars[95] = {'\0'};
    for (int i = 0; i < word_len; ++i) {
        int ascii = (int) word[i] - 33;
        chars[ascii] += 1;
    }

     char temp_ans[1024];
     int len = (int) strlen(text);
     char dest[word_len + 30];
     memset(dest, 0, word_len + 30);

     for (int i = 0; i < len; i++){
         strncat(dest, &text[i], 1);

         if (dest[0] == '\n' || dest[0] == '\t' || dest[0] == 32) {
             dest[0] = 0;
         }
         else {
             int syb_len = number_of_symbols(dest);
             int ascii = (int) text[i] - 33;
             if (chars[ascii] > 0) {
                 if (syb_len == word_len) {
                     int valid = anagram(&chars, dest);
                     if (valid == 0) {
                         strcat(temp_ans, dest);
                         strcat(temp_ans, "~");

                         i = i - strlen(dest) + 1;
                         memset(dest, 0, strlen(dest));
                     }
                 } else if (syb_len > word_len) {
                     i = i - strlen(dest) + 1;
                     memset(dest, 0, strlen(dest));
                 }
             }
             else{
                 memset(dest, 0, strlen(dest));
             }
         }
     }
     temp_ans[strlen(temp_ans) -1] = '\0';
     char* ans = temp_ans;
     return ans;
 }