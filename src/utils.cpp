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
	return proc;
}

// Carrega configuracao de todos os processos a partir do arquivo
v_proc UTILS::carregaProcesso(string arq) {
	v_proc vet_processos;

	fstream fp;
	fp.open(arq.c_str());

	char* pch;
	string var;
	int linha=0;

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
	return vet_processos;
}
