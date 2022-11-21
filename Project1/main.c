#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AutoHtmlEnd.h"

void main() {
	int c = 0;
	int headerlan = 0;
	int ifSingleHeader = 1;
	int singleHeaderCheckCount = 0;
	element header;
	element singleheader[] = { "input","img","hr","br","MWU","KYH","kbd","link" };
	//element singleheader[] = { "input","img","hr","br","a","MWU","KYH","kbd","link" };
	FILE* fp;
	fp = fopen("htmlsample.txt", "r");
	if (fp == NULL) {
		printf("파일열기오류입니다.");
		return;
	}

	while ((c = fgetc(fp)) != EOF)
	{
		if (c == '<') {
			printf("%c", c);
			headerlan = 0;
			while ((c = fgetc(fp)) != '>' && c != ' ')
			{
				printf("%c", c);
				header[headerlan] = c;
				headerlan++;
			}
			printf("%c", c);
			header[headerlan] = '\0';
			for (int i = 0;i<sizeof(singleheader)/sizeof(singleheader[0]) && ifSingleHeader; i++) {
				if (strcmp(header,singleheader[i]) == 0) {
					ifSingleHeader = 0;
				}
			}
			if (ifSingleHeader) {
				push(header);
			}
			ifSingleHeader = 1;
		}else if (c == '\n') {
			pop();
		}
		else {
			printf("%c", c);
		}
	}
	while (top != NULL)
	{
		pop();
	}

	getchar();
	getchar();
	getchar();
}
