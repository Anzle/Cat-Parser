/*
 * File: tokenparser.c
 * Authors: Sangini and Rob
 * This file parses a string argument and decides what type of C
 * token to classify it as.
 */
 #include<ctype.h>
 
 /* Library of String Constants used in Tokenizer*/
 char* WORD = "word";
 char* INTEGER = "integer";
 
 
 
 /* */
 TokenizerT* genToken(char* ts, char* type){
	TokenizerT* t = TKCreate( char * ts );
	t -> type = type;
	return t;
 };
 
 /* The function creates a list of tokens to be returned by the parser
  Input: String to be parsed
  Output: TokenizerT pointer to the head of the list of tokens
 */
 TokenizerT* stringParse(char* input){
	TokenizerT* head = NULL, tail = NULL, cur = NULL;
	
	int length = strlen(input); //length of input string
	int pos = 0;
	do{
		//Input is a word
		if(isalphainput[pos]){
			int len=1;
			while(isalnum(input[++pos])
				len++; 
			//Create substring
			char* token = malloc(sizeof(char)*len+1);
			cur = genToken(strncpy(input+(pos*sizeof(char), token, len), WORD);
		}
		else if (input[pos] > 0x2f && input[pos] < 0x3a){
			//input is a digit, what kind?
			
			if(input[pos] == 0x30){//Check for 0 and 0x/0X
				if((pos+1) != length && (input[pos+1] == 0x58 || input[pos+1] == 0x78))
				{/*is Hexadecimal*/}
				else
				{/*is Octal - Check for error in input*/}
			}
			
			//Must check for decimal point/e in the parsing loop function
			
		}
		switch(input[pos]{
			//check for the special characters, such as braces and stuffs
		}
		
	}while(pos < length);
	
 
 } 