#include "defines.h"
#include <fstream>

// Instancia processo colocando os valores do arquivo na estrutura
proc_t UTILS::instVetorProcesso(vector<int> conf) {
	proc_t proc;
	proc.pid = conf[0];
	proc.inicializacao = conf[1];
	proc.prioridade = conf[2];
	proc.processador = conf[3];
	proc.offset = conf[4];
	proc.impressora = conf[5];
	proc.scanner = conf[6];
	proc.modem = conf[7];
	proc.disco = conf[8];
	proc.estado = 0;
	proc.bloc_ini = -1;
	proc.pc = 0;
	return proc;
}

// Carrega configuracao de todos os processos a partir do arquivo
void UTILS::carregaProcesso(string arq) {

	fstream fp;
	fp.open(arq.c_str());

	char* pch;
	string var;
	int linha = 0;


	vector<int> conf;

	while(getline(fp, var)) {
		if(var != "") {
			pch = strtok((char*)var.c_str(), ",");
			conf.push_back(linha++);
			while(pch != NULL) {
				int i = atoi(pch);
				conf.push_back(i);
				pch = strtok(NULL, " ,");
			}
			proc_t proc = instVetorProcesso(conf);
			vet_processos.push_back(proc);
			
		}
		conf.clear();
	}	
	fp.close();

}

// Inicializa memoria colocando -1 em todos arrays do vetor
void UTILS::inicializaMemoria() {
	for(int i=0; i < MAX_MEM; i++) {
		vet_memoria.push_back(-1);
	}
}

// Carrega processos com prioridade zero na fila de prioridade zero
// void UTILS::carregaFilaPrioridadeZero(proc_t proc) {

// 	fila_prioridade_zero.push(proc);

// }


//Insere um processo na fila de processos
void UTILS::insereProcessoFila(proc_t proc){
	switch(proc.prioridade) {
		case 0:
			fila_prioridade_zero.push(proc);
			break;
		case 1:
			fila_prioridade_um.push(proc);
			break;
		case 2:
			fila_prioridade_dois.push(proc);
			break;
		case 3:
			fila_prioridade_tres.push(proc);
			break;
	}
}


// Carrega processo em sua determinada fila inicial
// cada processo só vai ser carregado no momento em que nele "chegar"
void UTILS::carregaFilasPrioridades() {
	for (unsigned int i = 0; i < processos_novos.size(); i++) {
		proc_t proc  = vet_processos[processos_novos[i]];

		UTILS::insereProcessoFila(proc);

	}
}

// Remove processo da fila de processos correspondente
void UTILS::removeProcessoFila(int pid) {
	switch (vet_processos[pid].prioridade) {
		case 0:
			fila_prioridade_zero.pop();
			break;
		case 1:
			fila_prioridade_um.pop();
			break;
		case 2:
			fila_prioridade_dois.pop();
			break;
		case 3:
			fila_prioridade_tres.pop();
			break;
	}
}


//Verifica filas para achar um processo para executar e retorna seu pid
int UTILS::verificaProximoParaExecutar() {
	proc_t proc;

	if (!fila_prioridade_zero.empty()) {

		proc = fila_prioridade_zero.front();

	} else if (!fila_prioridade_um.empty()){

		proc = fila_prioridade_um.front();


	} else if (!fila_prioridade_dois.empty()){

		proc = fila_prioridade_dois.front();

	} else if (!fila_prioridade_tres.empty()){

		proc = fila_prioridade_tres.front();
	}

	return proc.pid;
}
