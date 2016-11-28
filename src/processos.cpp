#include "defines.h"


//PUBLIC 

//Verifica se existe algum processo "chegando" no tempo de clock atual, se sim, salva eles no vetor processos_novos e return 1
// Caso contrario, retorna 0 apenas
int PROCESSOS::verificaNovo(int clock) {
	int j = 0;

	for(unsigned int i = 0; i < vet_processos.size(); i++) {

		proc_t proc = vet_processos[i];

		if(proc.inicializacao == clock) {
			processos_novos.push_back(proc.pid);
			j++;
		}
	}
	
	if (j == 0)
		return 0;
	else 

		return 1;
}

//Verifica se processo esta executando. Retorna: seu pid se sim sim, -1 nao
int PROCESSOS::verificaExecucao(){
	for(unsigned int i = 0; i < vet_processos.size(); i++) {

		proc_t proc = vet_processos[i];

		if(proc.estado == 1) {
			return i;
		}
	}
	return -1;
}


void PROCESSOS::atualizaPC(int pid){
	vet_processos[pid].pc++;
}

//Estados: 0 = Nao em execucao; 1 = em execucao; 2 = finalizado
void PROCESSOS::atualizaEstado(int pid, int estado){
	vet_processos[pid].estado = estado;
}


int PROCESSOS::verificaExisteMaisProcessos() {
	proc_t proc;
	for(unsigned int i = 0; i < vet_processos.size(); i++) {

		proc = vet_processos[i];
		if(proc.estado != 2) {
			return 1;
		}
	}
	return 0;
}

//Muda a prioridade do processo
void PROCESSOS::mudaPrioridade(int pid) {
	switch(vet_processos[pid].prioridade) {
		case 0: //Prioridade nunca pode mudar
			break;
		case 1:
			vet_processos[pid].prioridade = 2;
			break;
		case 2:
			vet_processos[pid].prioridade = 3;
			break;
		case 3: //Se ja esta na ultima fila, soh fica.
			break;
	}
}