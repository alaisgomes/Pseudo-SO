#include "defines.h"

//Chamar logo apos a chamada de UTILS::carregaFilasPrioridades();
void OUTPUT::mostraDispatcher() {
	for (unsigned int i = 0; i < processos_novos.size(); i++) {
		proc_t proc = vet_processos[processos_novos[i]];
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

//chamar essa funcao depois de qualquer chamada de PROCESSOS::atualizaPC(pid_exec);
//chamar como OUTPUT::mostraExecucaoAtual(pid_exec);
void OUTPUT::mostraExecucaoAtual(int pid) {
	proc_t proc = vet_processos[pid];

	if (proc.pc == 1) {
		cout<<"P"<< pid + 1 << "  STARTED\n";
		cout<<"P"<< pid + 1 << "  Instruction 1\n";
	} else 	if (proc.pc == proc.processador) {
		cout<<"P"<< pid + 1 << "  Instruction " << proc.pc << "\n";
		cout<<"P"<< pid + 1 << "  return SIGINT \n";
	} else {
		cout<<"P"<< pid + 1 << " Instruction " << proc.pc << "\n";

	}
}