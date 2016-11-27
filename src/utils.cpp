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
	proc.pc = -1;
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
	for(int i; i < MAX_MEM; i++) {
		vet_memoria.push_back(-1);
	}
}

// Carrega processos com prioridade zero na fila de prioridade zero
void UTILS::carregaFilaPrioridadeZero() {
	for(unsigned int i=0; i < vet_processos.size(); i++) {
		proc_t proc = vet_processos[i];
		if(proc.prioridade == 0) {
			fila_prioridade_zero.push(proc);
		}
	}
}
