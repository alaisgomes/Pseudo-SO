#include "defines.h"

//Imprime informacoes de processos que acabaram de chegar.
void OUTPUT::mostraDispatcher() {
	for (unsigned int i = 0; i < processos_novos.size(); i++) {
		proc_t proc = vet_processos[processos_novos[i]];
		if (proc.estado != 2) {
			cout << "dispatcher =>\n";
			cout << "\tPID: " << proc.pid + 1 << "\n";
			cout << "\toffset: " << proc.bloc_ini << "\n";
			cout << "\tblocks: " << proc.offset << "\n";
			cout << "\tpriority: " << proc.prioridade << "\n";
			cout << "\ttime: " << proc.processador << "\n";
			cout << "\tprinters: " << proc.impressora << "\n";
			cout << "\tscanners: " << proc.scanner << "\n";
			cout << "\tmodems: " << proc.modem << "\n";
			cout << "\tdrivers: " << proc.disco << "\n\n\n";
		}
	}
}

//Imprime qual instrucao de qual processo esta sendo execuada
void OUTPUT::mostraExecucaoAtual(int pid) {
	proc_t proc = vet_processos[pid];

	if (proc.pc == 1) {
		cout<<"P"<< pid + 1 << "  STARTED\n";
		cout<<"P"<< pid + 1 << "  Instruction 1\n";
	} else 	if (proc.pc == proc.processador) {
		cout<<"P"<< pid + 1 << "  Instruction " << proc.pc << "\n";
		cout<<"P"<< pid + 1 << "  return SIGINT \n";
	} else {
		cout<<"P"<< pid + 1  << " Instruction " << proc.pc << "\n";

	}
}

void OUTPUT::mensagemRecusaProcesso(int pid) {
	cout << "Um processo foi recusado, nao ha memoria suficiente para o mesmo " << "\n";
}