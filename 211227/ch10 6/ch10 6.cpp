#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORDS 20

typedef struct {
	char language[MAX_WORDS];
	int amount;
	char word[12][MAX_WORDS];
}word_list_t;

void load_word_list(char fileName[], word_list_t* wlp);
void add_word(char inputWord[], word_list_t* wlp);
bool contains(char searchWord[],word_list_t wordlist);
bool equal_lists(word_list_t wordlist1,word_list_t wordlist2);
void display_word_list(word_list_t wordlist);

int main(void) {
	word_list_t wordList[2];
	char fileName[MAX_WORDS];
	char inputWord[MAX_WORDS];
	bool found;
	bool flag;
	bool equal;

	//load word list
	strcpy(fileName, "data.txt");
	load_word_list(fileName, &wordList[0]);
	
	
	//add word
	printf("Enter a language of user's wordlist> ");
	scanf(" %s", &wordList[1].language);
	printf("Enter 12 words to add to the user's wordlist, enter -1 to stop> ");
	wordList[1].amount = 0;
	do{
		scanf(" %s", inputWord);
		if (strcmp(inputWord, "-1") == 0) {
			wordList[1].amount++;
			break;
		}
		add_word(inputWord, &wordList[1]);
	} while (wordList[1].amount<=12);
	wordList[1].amount--;

	//search words in the list
	do{
		flag = 0;
		printf("Enter a word you want to search, enter -1 to leave> ");
		scanf(" %s", inputWord);
		if (strcmp(inputWord,"-1")==0){
			break;
		}
		for (int i = 0; i < 2; i++) {
			found = contains(inputWord, wordList[i]);
			if (found && i == 0) {
				printf("'%s' is in file wordlist.\n", inputWord);
				flag = 1;
			}
			else if (found && i == 1) {
				printf("'%s' is in user wordlist.\n", inputWord);
				flag = 1;
			}
		}
		if (!flag) {
			printf("'%s' is NOT in any wordlist.\n", inputWord);
		}
	} while (true);

	//determine whether lists are the same
	equal = equal_lists(wordList[0],wordList[1]);
	if (equal){
		printf("\nTwo wordlists are THE SAME.\n");
	}
	else {
		printf("\nTwo wordlists are DIFFERENT.\n");
	}

	//display word list
	printf("\nFile wordlist:\n");
	printf("------------------------\n");
	display_word_list(wordList[0]);
	printf("\nUser wordlist:\n");
	printf("------------------------\n");
	display_word_list(wordList[1]);

	system("pause");
	return 0;
}

void load_word_list(char fileName[], word_list_t* wlp) {
	FILE* inp = fopen(fileName, "r");
	int status;
	int index = 0;

	fscanf(inp, " %s", wlp->language);

	do{
		status = 0;
		status = fscanf(inp, " %s", &wlp->word[index++]);
	} while (status==1);

	wlp->amount = --index;
}

void add_word(char inputWord[], word_list_t* wlp) {
	if (wlp->amount == 12) {
		printf("List full! '%s' not added.\n", inputWord);
	}else if ((wlp->amount)<12){
		strcpy(wlp->word[wlp->amount], inputWord);
	}
	wlp->amount++;
}

bool contains(char searchWord[], word_list_t wordlist) {

	for (int i = 0; i < wordlist.amount; i++){
		if (strcmp(searchWord, wordlist.word[i]) == 0) {
			return true;
		}
	}
	return false;
}

bool equal_lists(word_list_t wordlist1,word_list_t wordlist2) {
	bool found;
	if (stricmp(wordlist1.language, wordlist2.language)!=0){
		return false;
	}
	if (wordlist1.amount!=wordlist2.amount){
		return false;
	}
	for (int i = 0; i < wordlist1.amount; i++){
		found = contains(wordlist1.word[i], wordlist2);
		if (!found){
			return false;
		}
	}
	for (int j = 0; j < wordlist2.amount; j++){
		found = contains(wordlist2.word[j], wordlist1);
		if (!found) {
			return false;
		}
	}
	return true;
}

void display_word_list(word_list_t wordlist) {
	printf("Language: %s\n", wordlist.language);
	printf("Number of words in the list: %d\n", wordlist.amount);
	printf("Words:  ");
	for (int i = 0; i < wordlist.amount; i++){
		printf("%s ",wordlist.word[i]);
	}
	printf("\n------------------------\n");
}