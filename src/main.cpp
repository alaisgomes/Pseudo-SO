#include "defines.h"

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

	// carrega em memoria
	v_proc vet_processos = UTILS::carregaProcesso(arq.data());

	//DEBUG
	for(unsigned int i=0; i<vet_processos.size(); i++) {
		proc_t proc = vet_processos[i];
		cout <<	proc.pid;
		cout <<	proc.inicializacao;
		cout <<	proc.prioridade;
		cout <<	proc.processador;
		cout << proc.offset;
		cout <<	proc.impressora;
		cout <<	proc.scanner;
		cout <<	proc.modem;
		cout <<	proc.disco << '\n';
	}
	return 0;
}
