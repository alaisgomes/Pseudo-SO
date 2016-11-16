#include "defines.h"

// Printar processo passado como parametro
void DEBUG::mostrarProcesso(proc_t proc) {
	cout << proc;
}

// Printar fila de prioridade zero
void DEBUG::mostrarFilaPrioridadeZero() {
	queue<proc_t> fila_aux = fila_prioridade_zero;
	while(!fila_aux.empty()) {
		proc_t proc = fila_aux.front(); // Frente
		fila_aux.pop(); // Retira
		cout << proc.pid << " "<< '\n';
	}
}
