#include "defines.h"

//Chamar logo apos a chamada de UTILS::carregaFilasPrioridades();
void OUTPUT::mostraDispatcher() {
	for (unsigned int i = 0; i < processos_novos.size(); i++) {
		proc_t proc = vet_processos[processos_novos[i]];
		cout << "dispatcher =>\n";
		cout << "PID: " << proc.pid + 1 << "\n";
		cout << "offset: " << proc.bloco_ini << "\n";
		cout << "blocks: " << proc.offset << "\n";
		cout << "priority: " << proc.prioridade << "\n";
		cout << "time: " << proc.processador << "\n";
		cout << "printers: " << proc.pid << "\n";
		cout << "scanners: " << proc.pid << "\n";
		cout << "modems: " << proc.pid << "\n";
		cout << "drivers: " << proc.pid << "\n";
	}
}

//chamar essa funcao depois de qualquer chamada de PROCESSOS::atualizaPC(pid_exec);
//chamar como OUTPUT::mostraExecucaoAtual(pid_exec);
void OUTPUT::mostraExecucaoAtual(int pid) {
	proc_t proc = vet_processos[pid];

	if (proc.pc == 0) {
		cout<<"P"<< pid + 1 << " STARTED\n";
		cout<<"P"<< pid + 1 << " Instruction 1\n";
	} else 	if (proc.pc == proc.processador) {
		cout<<"P"<< pid + 1 << " Instruction \n" << proc.processador; << "\n";
		cout<<"P"<< pid + 1 << " return SIGINT \n";
	} else {
		cout<<"P"<< pid + 1 << "Instruction \n" << proc.processador; << "\n";

	}
}