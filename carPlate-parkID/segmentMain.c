#include <stdio.h>
#include <string.h>
int DealLine(char *StrLine)
{
	// find : data save
	char Parkid[20] = "";
	char *p = StrLine;
	char *prt = StrLine;
	char carNum[20] = "";
	if(p = strstr(p,":"))
	{
		p = p + 1;
		strncpy(Parkid,p,20);
		printf("Parkid == %s",Parkid);
	}else{
		return -1;
	}
	char endflag = 0;
	while(1){
		endflag = *prt;	
		if(endflag == 58)
		{
			return 0;
		}
		memset(carNum ,0, 20);
		sscanf(prt,"%[^,]",carNum);
		prt = strstr(prt,",");
		prt = prt + 1;
		printf("carNum = %s \n",carNum);		
	}
}

int main(void)
{
	FILE *fp; 

	char StrLine[1024] = "";
	fp = fopen("./test1.txt","r"); //判断文件是否存在及可读
	if(fp == NULL)
	{
		printf("open fail");
		return -1;
	}
	while(!feof(fp)){
		fgets(StrLine,1024,fp);  //读取一行
		printf("\n\n\n");
		printf("%s\n",StrLine);
		int ret = DealLine(StrLine);
	}
	fclose(fp);
	return 0;
}
