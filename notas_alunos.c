#include <stdio.h>
#include <string.h>

/* Professor, esse arquivo serve para criar a lista dos alunos. 
Eu havia entendido errado o trabalho, por isso criei esse código.
Porém, por achar que ficou um sistema mais completo, resolvi envia-lo também.*/

struct notas_aluno{
	int matricula;
	float nota[3];
};
struct lista_nomes{
	int matricula;
	char nome[51];
};

int main() {
	FILE *arquivo1, *arquivo2;
	int i, matricula, quanti;
	int on_off = 0;
	struct notas_aluno notas[30];
	struct lista_nomes nomes[30];

	arquivo1 = fopen("notas_alunos.txt", "a");
	if (arquivo1 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    arquivo2 = fopen("nomes_alunos.txt", "a");
	if (arquivo2 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
	for(i = 0; i < 30; i++){
		setbuf(stdin, NULL);
		printf("Nome do aluno: ");
		fgets(nomes[i].nome, sizeof(nomes[i].nome), stdin);
		nomes[i].nome[strcspn(nomes[i].nome, "\n")] = '\0';
		setbuf (stdin,NULL);
		printf("Nota 1 desse aluno: ");
		scanf("%f", &notas[i].nota[0]);
		setbuf (stdin,NULL);
		printf("Nota 2 desse aluno: ");
		scanf("%f", &notas[i].nota[1]);
		setbuf (stdin,NULL);
		printf("Nota 3 desse aluno: ");
		scanf("%f", &notas[i].nota[2]);
		printf("Matricula desse aluno: ");
		scanf("%d", &matricula);
		notas[i].matricula = matricula;
    	nomes[i].matricula = matricula;
    	quanti = i;
		printf("Tem mais alunos para adicionar? SIM[0] NAO[1] ");
		scanf("%d", &on_off);
		if (on_off == 1){
			break;
		}
	};
	for(i = 0; i <= quanti; i++){
		fprintf(arquivo1, "%d %.3f %.3f %.3f\n", notas[i].matricula, notas[i].nota[0], notas[i].nota[1], notas[i].nota[2]);
    	fprintf(arquivo2, "%d %s \n", nomes[i].matricula, nomes[i].nome);
	}
    
    
	fclose(arquivo1);
	fclose(arquivo2);
	return 0;
}
