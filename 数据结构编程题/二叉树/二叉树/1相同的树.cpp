#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true		1
#define false		0
typedef int bool;
int main(){
	int flag;
	char p[100]={0} ;//= NULL;
	char q[100]={0} ;//= NULL;
	scanf("%s",p);
	scanf("%s",q);
	flag = strcmp (p,q);
	if(flag == 0){
		printf("true"); 
	}else{
		printf("false");
	}
	return 0;
}