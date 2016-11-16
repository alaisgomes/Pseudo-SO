#include "defines.h"

vector<proc_t> vet_processos;
vector<int> vet_memoria;

queue<proc_t> fila_prioridade_zero;

int main(int argc, char **argv) {

	// Le arquivo de processos
	string	arq;
	if(argc < 2) {
		cout << "passe arquivo de processos\n";
		return -1;
	}
	else {
		arq.assign(argv[1]);
	}

	// carrega vetor de processos
	UTILS::carregaProcesso(arq.data());

	// carrega vetor de memoria
	UTILS::inicializaMemoria();

	// carrega processos na fila de prioridade um
	UTILS::carregaFilaPrioridadeZero();

	//DEBUG::mostrarProcesso(vet_processos[0]);
	DEBUG::mostrarFilaPrioridadeZero();

	return 0;
}
