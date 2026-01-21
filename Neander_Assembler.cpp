#include <stdio.h>
#include <string.h>
#include <conio.h>

/*
!ATENTION!

To ensure the program works, the user must enter the file name with the .txt suffix, 
saved in the same folder as the .exe file of this code. The program should generate 
a file named "prog1.mem" in the same folder, which should be opened in the Neander 
simulator. Additionally, the txt file must contain only assembly instructions, 
without any line number indications in the code. Moreover, the memory address values 
of the instructions should be in hexadecimal format. It does not matter if the 
instruction characters are in uppercase or lowercase. This project must be compiled
using "DEV-C++" to avoid issues.

TXT FILE EXEMPLE:

lda 80
NOT
ADD 81
STA 83
Hlt

*/

const int inst[11] = {0,16,32,48,64,80,96,128,144,160,240}; //instruction declaration
int encontraNum(char hex[2]); //Function declaration to convert hex strings to decimal integers
unsigned char cabecalho[4] = {3,78,68,82}; //header declaration

int main () {
	FILE *arquivo;
	FILE *Neander;
	char nome[80];
	char opcode[3];
	char endereco[2];
	int num;

	printf("Digite o nome do arquivo txt (arquivo deve estar na mesma pasta do programa): ");
	fflush(stdin);
	scanf("%s", &nome); //txt file input.
	
	arquivo = fopen(nome, "r");

	if(arquivo == NULL) { //Verify if the file exists
		puts("\nArquivo não encontrado...\n");
		return 1;
	} else {
		Neander = fopen("prog1.mem", "wb"); //Create de mem file
	}
	
	if(Neander == NULL) { //Verify if the file was created successfully
		puts("\nNão foi possível criar o arquivo...\n");
		fclose(arquivo);
		return 1;
	}
	
	if(arquivo != NULL && Neander != NULL)
		printf("Gerando prog1.mem ..."); //prints a message in the terminal
	
	
	for(int i = 0; i < sizeof(cabecalho); i++)
		fwrite(&cabecalho[i], sizeof(cabecalho[i]),1,Neander); //Writes the header into the neander file
	
	
	while (fscanf(arquivo, "%s", opcode) != EOF) { //assembler loop
		strcpy(opcode, strupr(opcode));
		if (strcmp(opcode, "NOP") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[0], 2,1,Neander);
		
		}
		if (strcmp(opcode, "STA") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[1], 2,1,Neander);
			
			fscanf(arquivo, " %s", endereco);
			num = encontraNum(endereco);
			fwrite(&num, 2,1, Neander);
		}
		if (strcmp(opcode, "LDA") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[2], 2,1,Neander);
			
			fscanf(arquivo, " %s", endereco);
			num = encontraNum(endereco);
			fwrite(&num, 2,1, Neander);
		}
		if (strcmp(opcode, "ADD") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[3], 2,1,Neander);
			
			fscanf(arquivo, " %s", endereco);
			num = encontraNum(endereco);
			fwrite(&num, 2,1, Neander);
		}
		if (strcmp(opcode, "OR") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[4], 2,1,Neander);
			
			fscanf(arquivo, " %s", endereco);
			num = encontraNum(endereco);
			fwrite(&num, 2,1, Neander);
		}
		if (strcmp(opcode, "AND") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[5], 2,1,Neander);
			
			fscanf(arquivo, " %s", endereco);
			num = encontraNum(endereco);
			fwrite(&num, 2,1, Neander);
		}
		if (strcmp(opcode, "NOT") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[6], 2,1,Neander);
		}
		if (strcmp(opcode, "JMP") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[7], 2,1,Neander);
			
			fscanf(arquivo, " %s", endereco);
			num = encontraNum(endereco);
			fwrite(&num, 2,1, Neander);
		}
		if (strcmp(opcode, "JN") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[8], 2,1,Neander);
			
			fscanf(arquivo, " %s", endereco);
			num = encontraNum(endereco);
			fwrite(&num, 2,1, Neander);
		}
		if (strcmp(opcode, "JZ") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[9], 2,1,Neander);
			
			fscanf(arquivo, " %s", endereco);
			num = encontraNum(endereco);
			fwrite(&num, 2,1, Neander);
		}
		if (strcmp(opcode, "HLT") == 0) {
			fflush(stdin);
			fflush(stdout);
			fwrite(&inst[10], 2,1,Neander);
		}
	}
	fclose(arquivo);
	fclose(Neander); //Closes both files
}

int encontraNum(char hex[2]) {
	int decimal;
	sscanf(hex, "%x", &decimal);
	return decimal;
}
