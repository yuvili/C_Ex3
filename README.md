# String functions in C programing 
This project includes 3 functions that can be used on string in C programing.
The functions are implemented in the *my_char.c* file, and can be used in the *main.c* file.
The program scans the user input in *main.c*, by reciving a word up to 30 characters, and a certain text up to 1024 characters.
After reciving the user's input, the two strings will be send as an input to the functions and the resulted output will be printed on the screen to the user.

## Gematria_Sequences
The function returns as an output all the minimum sequences in the text that have the same [gematria](https://en.wikipedia.org/wiki/Gematria) 
value as the value of the word absorbed.

## Atbash_Sequences
The function returns all the minimum sequences in the text, so that when ignoring blank characters, they are the same as a word or vice versa
in [Atbash.](https://en.wikipedia.org/wiki/Atbash)

## Anagram_Sequences
The function returns all the minimal sequences in the text that consist of the characters of the inputed word and only blank characters.
