#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define NAME 10

typedef struct{
	int x;
	int y;
	int z;
	int m;
	char name[NAME];
}address_t;

int scan_address(FILE *inp, address_t*adrp);
void print_address(address_t* adrp);
int local_address(address_t* adrp1, address_t* adrp2);

int main(void){
	address_t adr_list[MAX];
	FILE* inp;
	int status;
	char again;
	int index = 0;
	int sameNetwork;
	inp = fopen("data.txt", "r");

	//scan the file
	do{
		status = scan_address(inp, &adr_list[index++]);
	} while (status==5);
	--index;
	printf("Successfully read the file.\n");


	//search computers in same local network
	printf("\nSEARCHING THE SAME LOCAL NETWORK\n");
	for (int i = 0; i < index-1; i++){
		for (int j = i; j < index; j++){
			if (j==i){
				continue;
			}
			sameNetwork = 0;
			sameNetwork = local_address(&adr_list[i], &adr_list[j]);
			if (sameNetwork) {
				printf("Machines %s and %s are on the same local network.\n",adr_list[i].name, adr_list[j].name);
			}
		}
	}

	//print all address
	printf("\nALL DATA\n");
	for (int i = 0; i < index; i++){
		print_address(&adr_list[i]);
	}


	fclose(inp);
	system("pause");
	return 0;
}

int scan_address(FILE *inp,address_t *adrp) {
	int status = 0;
	char trash;
	status = fscanf(inp, "%d.%d.%d.%d %s",
		&adrp->x,
		&adrp->y,
		&adrp->z,
		&adrp->m,
		adrp->name);

	return status;
}

void print_address(address_t* adrp) {
	printf("%3d.", (*adrp).x);
	printf("%3d.", adrp->y);
	printf("%3d.", adrp->z);
	printf("%3d    ", adrp->m);
	printf("%s\n", adrp->name);
}

int local_address(address_t* adrp1, address_t* adrp2) {
	return(adrp1->x == adrp2->x && adrp1->y == adrp2->y);
}