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

// char* Atbash(char* word){
//     int s_length = (int) strlen(word);
//     char* ans = word;

//     for (int i = 0; i < s_length/2; i++){
//         char temp = ans[i];
//         ans[i] = ans[s_length-i-1];
//         ans[s_length-i-1] = temp;
//     }
//     return ans;
// }

// char* Atbash_Sequences(char *text,char *word){
//     int word_len = (int) strlen(word);
//     char* word_gv = Atbash(word);
//     char dest[] = "";
//     char temp_ans[] = "";
//     int len = (int) strlen(text);

//     for (int i = 0; i < len; i++){
//         strncat(dest,&text[i],1);
//         int dest_len = (int) strlen(dest);

//         if(dest_len == word_len){
//             int equals_word = strcmp(dest,word);
//             int equals_atbash = strcmp(dest,word_gv);

//             if(equals_word == 0 || equals_atbash == 0){
//                 strcat(temp_ans,dest);
//                 strcat(temp_ans,"~");
//             }
//         }
//         else if(dest_len > word_len){
//             char* empty = "";
//             strcpy(empty,dest);
//         }
//     }
//     char* ans = temp_ans;
//     return ans;
// }

// int correct(char a, char* word){
//     int len = (int) strlen(word);

//     for (int i = 0; i < len; i++)
//     {
//         if(a == word[i] || '\n'){
//             return 0;
//         }
//     }
//     return 1;
// }

// char* Anagram_Sequences(char *text,char *word){
//     char temp_ans[] = "";
//     int len = strlen(text);
//     int added = 0;

//     for (int i = 0; i < len; i++){
//         if(correct(text[i],word) == 0){
//             strncat(temp_ans, &text[i], 1);
//             added++;
//         }
//         else{
//             if (added > 0)
//             {
//                 strcat(temp_ans,"~");
//                 added = 0;
//             }
//         }
//     }
//     char* ans = temp_ans;
//     return ans;
// }