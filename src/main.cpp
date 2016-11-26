#include "defines.h"
#include <unistd.h>

// Instanciado uma vez variavel extern
vector<proc_t> vet_processos;
vector<int> vet_memoria;
queue<proc_t> fila_prioridade_zero;

#define CLOCK 100000

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

	// Carrega vetor de processos
	UTILS::carregaProcesso(arq.data());

	// Carrega vetor de memoria
	UTILS::inicializaMemoria();

	// carrega processos na fila de prioridade um
	UTILS::carregaFilaPrioridadeZero();

	// Inicia processador
	while(1) {
		
		if(vet_processos.size() > 0) {
			// reserva memoria
			
		}

		usleep(CLOCK);
		break;
	}

	//DEBUG::mostrarProcesso(vet_processos[0]);
//	DEBUG::mostrarFilaPrioridadeZero();

	return 0;
}
