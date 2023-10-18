#include <stdio.h>
#include <unistd.h>

int main()
{ 
	printf("Os arquivos no diretório são:\n");
	execl("/bin/ls","ls", "-l",(char*)0);
	printf("Listagem terminada.\n\n");
	return 0;
}

