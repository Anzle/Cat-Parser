/*
 * tokenizer.c
 */
#include <stdio.h>
#include <stdlib.h>

int strloc = 0; //index location of where the tokenizer is in the string
char* str; // This will reference the address of argv[1]

/*Library of Token types*/
char* t1 = "WORD";
char* t2 = "INTEGER";

//ect

/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 */
struct TokenizerT_ {
	char *token; //The current token/piece of the string being analyzed
	char *type; //This is the type of token, points to an entry in the type table
};

typedef struct TokenizerT_ TokenizerT;

/*
 * TKCreate creates a new TokenizerT object for a given token stream
 * (given as a string).
 * 
 * TKCreate should copy the arguments so that it is not dependent on
 * them staying immutable after returning.  (In the future, this may change
 * to increase efficiency.)
 *
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

 /* Only call this method once, to set up the initial tokenizer. Then the 
  * TKGetNextToken uses the global string index (strloc declared above)
  * to keep track of where in str we are and what token to be stored in 
  * the tokenizer. 
  */
TokenizerT *TKCreate( char * ts ) {
	if(ts == 0){
		return NULL;
	}
	else {
		TokenizerT *tokenizer = (TokenizerT *) calloc(1,sizeof(TokenizerT));
		tokenizer -> token = ts; //technically don't need this since gettoken method returns a char*
		tokenizer -> type = NULL;
		return tokenizer;
	}
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy( TokenizerT * tk ) {
	free(tk -> token); 
	//free(tk -> type); //no need to free
	free(tk);
}

/*
 * TKGetNextToken returns the next token from the token stream as a
 * character string.  Space for the returned token should be dynamically
 * allocated.  The caller is responsible for freeing the space once it is
 * no longer needed.
 *
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

char *TKGetNextToken( TokenizerT * tk ) {

  return NULL;
}

/*
 * main will have a string argument (in argv[1]).
 * The string argument contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */

int main(int argc, char **argv) {
	if(argc != 2){
		// input should include a string 
		printf("Error: Invalid number of arguments.\n");
		return 0;
	}
	printf("%s\n", argv[1]);
	
	//make the scope of argv[1] global
	str = argv[1];
	
	//create a tokenizer with the given string
	TokenizerT *tokenizer = TKCreate(str); 
	
	if(tokenizer != NULL){
		//go through the string and tokenize it here
		char *tok = TKGetNextToken(tokenizer);
		while(tok != 0){
			//print the token and the type
		}
		//destroy the tokenizer. mission complete.
		TKDestroy(tokenizer);
	} else {
		printf("Error building tokenizer.\n");
	}
	
	return 0;
}

