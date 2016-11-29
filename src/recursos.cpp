#include "defines.h"


//Verifica se o processo precisa de algum recurso e retorna 
int RECURSOS::verificaRecurso(int pid){
	if (vet_processos[pid].impressora > 0 || vet_processos[pid].scanner > 0 || vet_processos[pid].disco > 0 || vet_processos[pid].modem > 0) 
		return 1;
	else
		return 0;
}

int 

void RECURSOS::alocaRecurso(int pid){
	return;
}