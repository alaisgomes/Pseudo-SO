#include "defines.h"



//PUBLIC 

//Verifica se existe algum processo "chegando" no tempo de clock atual, se sim, salva eles no vetor pid_atual e return 1
// Caso contrario, retorna 0 apenas
int PROCESSOS::verificaNovo(int clock, vector<int> pid_atual) {
	int j = 0;

	for(unsigned int i = 0; i < vet_processos.size(); i++) {

		proc_t proc = vet_processos[i];

		if(proc.inicializacao == clock) {

			pid_atual.push_back(proc.pid);
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


int PROCESSOS::verificaNaoFinalizados() {
	for(unsigned int i = 0; i < vet_processos.size(); i++) {

		proc_t proc = vet_processos[i];

		if(proc.estado != 2) {
			return 1;
		}
	}
	return 0;
}