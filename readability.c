#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[]){

    // Get text from the user
    string text = get_string("Text: ");

    // Count the number of words in sentence and number of letter per word
    // Based on pset instructions reading level determined by:
    //  index = 0.0588 * L - 0.296 * S - 15.8
    //  S - average number of sentences (this code ignores Mr. and Ms. and calls them sentences) per 100 words
    //  L - average number of letters per word per 100 words

    int numChars = strlen(text);
    int numLetters = 0;
    int numWords = 0;
    int numSentences = 0;


    for(int i = 0; i < numChars; i++){

        // Count the number of sentences
        if (text[i] == '!' || text[i] == '.' || text[i] == '?'){
            numSentences++;
        }

        // Count the number of letters
        if (text[i] >= 'A' && text[i] <= 'z' ){
            numLetters++;
        }

        // Count the number of words


        // word is any characters separated by spaces and finishes in punctuation.
        // words with punctuation that are followed by space alpha characters is considered 1 word.

        if( i>0 && (isspace(text[i]) || ispunct(text[i])) && (!isspace(text[i-1]) && !ispunct(text[i-1])) ){
            if( i < numChars-1 && ispunct(text[i]) && isalpha(text[i+1])){
                //do nothing
            } else {
                numWords++;
            }

        }

    }

    float s = ( (float) numSentences / (float) numWords ) * 100; //average number of sentences per 100 words
    float l = ( (float) numLetters ) / (float) numWords * 100; //average number of letters per 100 words
    float index =  (0.0588 * l) - (0.296 * s) - 15.8 ;


   //printf("chars: %i, letters: %i, words: %i, sentences: %i\ns: %f, l: %f, index: %f\n",numChars,numLetters,numWords,numSentences,s,l,index);

    // Output grade level based on index
    if (index < 0.5){
        printf("Before Grade 1\n");
    } else if (index > 15){
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", (int) roundf(index));
    }

}