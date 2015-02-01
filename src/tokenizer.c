/*
 * tokenizer.c
 */
#include <stdio.h>
#include <stdlib.h>

int pos = 0; //index location of where the tokenizer is in the string
char* input; // This will reference the address of argv[1]

/* Library of String Constants used in Tokenizer*/
 char* WORD = "word";
 char* INT = "integer";
 char* HEX = "hex";
 char* OCT = "oct";
 char* FLOAT = "float";

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
 
 
 /* This function is a wrapper function to expand the header options provided
  * by the code given to us by the professor. build token creates a token and then
  * gives the token a type for use later on  
  */
 TokenizerT* buildToken(char* ts, char* type){
	TokenizerT* t = TKCreate( char * ts );
	t -> type = type;
	return t;
 };
 
 /* The function creates a token, from the first word of the input string
  Input: String to be parsed
  Output: TokenizerT pointer to the created token
 */
 TokenizerT* stringParse(){
	TokenizerT* tok = NULL;
	int length = strlen(input) - pos; //length of input string
	//do{
		//Input is a word
		if(isalphainput[pos]){
			while(isalnum(input[++pos]) 
			//Create substring
			char* token = malloc(sizeof(char)*pos+1);
			 tok = buildToken(strncpy(input, token, pos), WORD);
		}		
			//input is a digit, what kind?
		else if (isdigit(input[pos])){
				//HEX
			if(input[pos] == 0x30){//Check for 0 
				pos++; //and 0x/0X, make sure not at the end of the string
				if((pos) != length && (input[pos] == 0x58 || input[pos] == 0x78))
				{
					while(isxdigit(input[++pos]) 
					char* token = malloc(sizeof(char)*pos+1);
					tok = buildToken(strncpy(input, token, pos), HEX);	
					
				}
				//OCT
				else
				{
					while(isdigit(input[++pos]) 
					char* token = malloc(sizeof(char)*pos+1);
					tok = buildToken(strncpy(input, token, pos), OCT);
				}
			}
			else{ //The digit is an integer or a float
				char t = 'd';
				//INTEGER
				while(!isspace(input[++pos])){
					if(isdigit(input[pos]){}
					//Float
					else if(toloswer(input[pos]) ==  0x65 || input[pos] == 0x2e){
						t = 'f'; //is float
					}
				}
				char* token = malloc(sizeof(char)*pos+1);
				if(t == 'f');
						tok = buildToken(strncpy(input, token, pos), FLOAT);
				else
					tok = buildToken(strncpy(input, token, pos), INT);
				//Must check for decimal point/e in the parsing loop function
			}
		}//End Digit Check
		switch(input[pos]{
			//check for the special characters, such as braces and stuffs
		}
		
		return tok;
	//}while(pos < length);
 } //END function stringParse


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
	input = argv[1];
	
	//create a tokenizer with the given string
	TokenizerT *tokenizer = TKCreate(input); 
	
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

