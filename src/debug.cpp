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


// Printar Memoria atual
void DEBUG::mostrarMemoria() {
	cout << "Situacao da Memoria: \n";
	for (unsigned int i = 0; i < vet_memoria.size(); i++) {
		if (vet_memoria[i] == -1)
			cout << "# | ";
		else
			cout << vet_memoria[i] << " | ";
	}


	cout << '\n'; 
}

//Printar Situacao das filas
void DEBUG::mostrarFilas() {
	queue<proc_t> fila_aux0 = fila_prioridade_zero;
	queue<proc_t> fila_aux1 = fila_prioridade_um;
	queue<proc_t> fila_aux2 = fila_prioridade_dois;
	queue<proc_t> fila_aux3 = fila_prioridade_tres;
	cout << "Fila 0: [";
	while(!fila_aux0.empty()) {
		proc_t proc = fila_aux0.front(); // Frente
		fila_aux0.pop(); // Retira
		cout << proc.pid << " ";
	}

	cout << "]\n";

	cout << "Fila 1: [" ;
	while(!fila_aux1.empty()) {
		proc_t proc = fila_aux1.front(); // Frente
		fila_aux1.pop(); // Retira
		cout << proc.pid << " ";
	}

	cout << "]\n"; 

	cout << "Fila 2: [";
	while(!fila_aux2.empty()) {
		proc_t proc = fila_aux2.front(); // Frente
		fila_aux2.pop(); // Retira
		cout << proc.pid << " ";
	}

	cout << "]\n"; 

	cout << "Fila 3: [";
	while(!fila_aux2.empty()) {
		proc_t proc = fila_aux3.front(); // Frente
		fila_aux3.pop(); // Retira
		cout << proc.pid << " ";
	}

	cout << "]\n";
}

void DEBUG::mostraEstadoProcessos() {
	cout << "Estado de todos os processos: \n";
	for (unsigned int i = 0; i < vet_processos.size(); i++) {
		proc_t proc = vet_processos[i];
		cout << proc.estado << " ";
	}
	cout << "\n";
}