#include "defines.h"


//Verifica se o processo precisa de algum recurso e retorna 
int RECURSOS::verificaRecurso(int pid){
	if (vet_processos[pid].impressora > 0 || vet_processos[pid].scanner > 0 || vet_processos[pid].disco > 0 || vet_processos[pid].modem > 0) 
		return 1;
	else
		return 0;
}



void RECURSOS::alocaRecurso(int pid){
	//verifica os recursos necessarios ao processo e os aloca

}

void RECURSOS::insereFilaRecurso(int pid){
	//aloca o id do processo nas filas de recurso que o processo pid precisa

}

void RECURSOS::liberaRecurso(int pid){
	//libera os recursos usados pelo processo pid

}

void RECURSOS::atualizaRecurso(){
	//atualiza os recursos vazios com os proximos da fila
};

void RECURSOS::inicializaRecurso(){
	//poe -1 em cada recurso pra indicar que estão livres
}