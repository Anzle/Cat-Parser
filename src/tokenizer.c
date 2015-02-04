/*
* tokenizer.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
* Tokenizer type.  You need to fill in the type as part of your implementation.

** This struct acts as the TokenizerStream
** It stores the entire original string into the token variable, and then iterates
** though the stream, keeping track of it's possition with with pos variable
*/

struct TokenizerT_ {
	char *token; //The token stream to read from
	int pos; //
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

TokenizerT *TKCreate(char * ts) {
	if (ts == 0){
		return NULL;
	}
	else {
		//Should probably check these for existence
		TokenizerT *tokenizer = (TokenizerT *)calloc(1, sizeof(TokenizerT));
		tokenizer->token = (char*)malloc(sizeof(char*)*(strlen(ts)+1));


		strcpy(tokenizer->token, ts); //Copy the TokenStream
		tokenizer->pos = 0; //the position in the TokenStream
		return tokenizer;
	}
}

/*
* TKDestroy destroys a TokenizerT object.  It should free all dynamically
* allocated memory that is part of the object being destroyed.
*
* You need to fill in this function as part of your implementation.
*/

void TKDestroy(TokenizerT * tk) {
	free(tk->token);
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

**THIS Function is supposed to parse the token stream
*/

char *TKGetNextToken(TokenizerT * tk) {

	if (tk == NULL || tk->pos == strlen(tk->token))
		return NULL;
	
	int length = 0;
	int start = tk->pos;
	char* ret = NULL;
	char flag= '0';

	/*Beging parsing*/
	/*Word*/
	if (isalpha(tk->token[tk->pos])){
		length++;
		while (isalnum(tk->token[++tk->pos]))
			length++;
		ret = (char*)malloc(sizeof(char*)*(length + 8)); //add 1 for NULL and 7 for "Word_\"\""
		strcpy(ret, "Word \"");
		strncat(ret, tk->token+start, length);
		strcat(ret, "\"\0");
		
	}
	else if (isdigit(tk->token[tk->pos])){
		length++;
		/*Begin oct/hex check*/
		if (tk->token[tk->pos] == 0x30){
			tk->pos++;
			
			if/*Hex*/(tk->token[tk->pos] == 0x58 || tk->token[tk->pos] == 0x78){
				length++;
				while (isxdigit(tk->token[++tk->pos]))
					length++;
				ret = (char*)malloc(sizeof(char*)*(length + 7)); //add 1 for NULL and 6 for "Hex_\"\""
				strcpy(ret, "Hex \"");
				strncat(ret, tk->token + start, length);
				strcat(ret, "\"\0");
			}

			else/*OCT*/{
				while (isdigit(tk->token[++tk->pos]))
					length++;
				ret = (char*)malloc(sizeof(char*)*(length + 7)); //add 1 for NULL and 6 for "Oct_\"\""
				strcpy(ret, "Oct \"");
				strncat(ret, tk->token + start, length);
				strcat(ret, "\"\0");
			}
		}//End Hex/Oct Check
		else /*Int and Float*/{
			
			while (isdigit(tk->token[++tk->pos]))
				length++;
			if (tk->token[tk->pos] == 0x2e){ /*Is there a decimal*/
				length++;
				while (isdigit(tk->token[++tk->pos])) /*Keep getting digits*/
					length++;
				flag = 'f'; //set to f for float
			}
			if (tk->token[tk->pos] ==0x45 || tk->token[tk->pos] == 0x65){
				length++;
				tk->pos++;
				if (tk->token[tk->pos] == 0x2d) /*There can only be a - after the e/E*/
					length++;
				while (isdigit(tk->token[++tk->pos])) /*Keep getting digits*/
					length++;
				flag = 'f';
			}

			if (flag == 'f'){
				ret = (char*)malloc(sizeof(char*)*(length + 9)); //add 1 for NULL and 8 for "Float_\"\""
				strcpy(ret, "Float \"");
				strncat(ret, tk->token + start, length);
				strcat(ret, "\"\0");
			}
			else{
				ret = (char*)malloc(sizeof(char*)*(length + 7)); //add 1 for NULL and 6 for "Int_\"\""
				strcpy(ret, "Int \"");
				strncat(ret, tk->token + start, length);
				strcat(ret, "\"\0");
			}

		}//End int/float check
		

	}
	/*IS it a white space, increment via recursion*/
	else if (isblank(tk->token[tk->pos])){
		tk->pos++;
		ret = TKGetNextToken(tk);
	}
	else{
		switch (tk->token[tk->pos]){
		case '\0': ret = NULL; break;
			/*Non-AlphaNumeric cases*/
		default: break;
			/*This is a case we do not test for*/
		} 
	}


	return ret;
}

/*
* main will have a string argument (in argv[1]).
* The string argument contains the tokens.
* Print out the tokens in the second string in left-to-right order.
* Each token should be printed on a separate line.
*/

int main(int argc, char **argv) {
	//Input validation
	/*
	if (argc != 2){
		// input should include a string 
		printf("Error: Invalid number of arguments.\n");
		return 0;
	}

	printf("%s\n", argv[1]); //Taken out for inline Testing
	TokenizerT *tkStream = TKCreate(argv[1]); //Initalize the TokenStream
	*/
	char* stream = " love 1.2e-345";
	char* tok = NULL;
	TokenizerT *tkStream = TKCreate(stream); //Initalize the TokenStream
	int length = strlen(tkStream->token);
	printf("%s\nStarting:\n", tkStream->token);

	/*
	loop over TKGetNextToken*/
	do{
		tok = TKGetNextToken(tkStream);
		printf("%s\n", tok);
		free(tok);
	} while (tkStream->pos < length);

	TKDestroy(tkStream);
	return 0;
}