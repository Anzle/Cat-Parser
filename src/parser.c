/*
 * File: tokenparser.c
 * Authors: Sangini and Rob
 * This file parses a string argument and decides what type of C
 * token to classify it as.
 */
 #include<ctype.h>
 
 /* Library of String Constants used in Tokenizer*/
 char* WORD = "word";
 char* INT = "integer";
 char* HEX = "hex";
 char* OCT = "oct";
 char* FLOAT = "float";
 
 
 
 /* This function is a wrapper function to expand the header options provided
  * by the code given to us by the professor. build token creates a token and then
  * gives the token a type for use later on  
  */
 TokenizerT* buildToken(char* ts, char* type){
	TokenizerT* t = TKCreate( char * ts );
	t -> type = type;
	return t;
 };
 
 /* The function creates a token, from the first character of the input string
  Input: String to be parsed
  Output: TokenizerT pointer to the head of the list of tokens
 */
 TokenizerT* stringParse(char* input){
	TokenizerT* tok = NULL;
	int length = strlen(input); //length of input string
	int pos = 0;
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
	
 
 } 