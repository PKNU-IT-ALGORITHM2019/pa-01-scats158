
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#define Dictionary_Size 1000000
#define Word_Size 55
#define Line_Length 2500
#define Buffer_Length 55


char *Diction[Dictionary_Size];
int size = 0;

void load(char *s);
int load_line(FILE * fo, char str[], int n);
void capital_word(char *c);


void load(char *s) {
	int x = 0;
	FILE *open;
	char buffer[Line_Length];
	

	open = fopen(s, "r"); //파일을 읽기 형식으로 연다.
	if (open == NULL) {
		printf("존재 하지 않는 파일입니다. 다시 입력해 주세요. \n");
		exit(1);
	}
	else
		printf("파일을 불러오는 중... \n");
	

	while (!feof(open)) {
		load_line(open, buffer, Line_Length);
		if (strcmp(_strdup(buffer), "") == 0) 
			continue;
		else {
			Diction[x] = _strdup(buffer);
			size++;
			x++;
		}
	}
	fclose(open);
}


void capital_word(char *c) {
	int i = 1;
	char buffer[Word_Size];
	if (islower(c[0])) 
		buffer[0] = c[0] - 32;
	else 
		buffer[0] = c[0];
	while (c[i] != '/0') {
		if (isupper(c[i])) 
			buffer[i] = c[i] + 32;
		else 
			buffer[i] = c[i];
		i++;
	}
	buffer[i] = '\0';
	strcpy(c, buffer);
	
}


int load_line(FILE * fp, char str[], int n)
{
	int ch, z = 0;
	while ((ch = fgetc(fp)) != '\n' && ch != EOF)
		if (z < n)
			str[z++] = ch ;
	str[z] = '\0';
	return z;
}

int main() {
	char instruction[Buffer_Length];
	char *isr, *sentence;

	while (1) {
		printf("$ ");
		if (load_line(stdin, instruction, Buffer_Length) <= 0)
			continue;
		isr = strtok(instruction, " ");

		if (strcmp(isr, "read") == 0) {
			sentence = strtok(NULL, " ");
			if (sentence == NULL) continue;
			load(sentence);
		}

		else if (strcmp(isr, "size") == 0)
			printf("%d\n\n", size);

		
		else if (strcmp(isr, "exit") == 0)
			exit(1);

		else printf("존재하지 않는 명령입니다.\n");
	}
	return 0;
}



// 참고한 사이트 : http://blog.naver.com/PostView.nhn?blogId=sharonichoya&logNo=220513886595
//				https://modoocode.com/37