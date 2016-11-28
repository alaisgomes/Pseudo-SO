#include "defines.h"
#include <unistd.h>

// Instanciado uma vez variavel extern
vector<proc_t> vet_processos;
vector<int> vet_memoria;
queue<proc_t> fila_prioridade_zero;
queue<proc_t> fila_prioridade_um;
queue<proc_t> fila_prioridade_dois;
queue<proc_t> fila_prioridade_tres;

vector<int> processos_novos;

#define CLOCK 100000  


int main(int argc, char **argv) {

	int clock_atual = 1; // É incrementado sempre que roda o loop
	
	int pid_exec = 0;
	


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
	
	// Inicia Fluxo
	while(1) {
		
		//Ha novos processos? SIM
		if(vet_processos.size() > 0) {

			if (PROCESSOS::verificaNovo(clock_atual)) {

				// aloca memoria
				MEMORIA::alocaMemoria();

				//poe na fila de processos
				UTILS::carregaFilasPrioridades();
			}
		
		}

		// Ha um processo em execucao? SIM
		
		if ((pid_exec = PROCESSOS::verificaExecucao()) > -1) {
			

			//Incrementa PC dele
			PROCESSOS::atualizaPC(pid_exec);

			
	
		}  else { // Nao ha um processo em execucao
			//Verifica em Cada fila por um Processo returna o pid do proximo a ser executado pid_exec
			pid_exec = UTILS::verificaProximoParaExecutar();

			//PRECISA DE RECURSO? SIM
			if (RECURSOS::verificaRecurso(pid_exec)) {
					//Verifica se recurso disponivel

					// Se sim, aloca, se nao, poe processo na fla do recurso e atualiza fila de processos (?)


			} else { // nao precisa de recurso
				//atualiza fila
				UTILS::removeProcessoFila(pid_exec);

				//coloca em execucao
				PROCESSOS::atualizaEstado(pid_exec, 1);
				PROCESSOS::atualizaPC(pid_exec);

			}

		}

		//Acabou processo em execucao? SIM
		if (vet_processos[pid_exec].pc == vet_processos[pid_exec].processador) {
			
			//Marca  que terminou e libera processador
			PROCESSOS::atualizaEstado(pid_exec, 2);

			//libera memoria e dispositivos
			MEMORIA::removeMemoria(pid_exec);

			//desfrag memoria
			MEMORIA::desfragmentar();


		} else { // NAO


			//Verifica se nao eh um processo em tempo real. Se for, pula atualizacoes
			if (vet_processos[pid_exec].prioridade != 0) {

				//Acabou o Quantum? SIM 
				if ((vet_processos[pid_exec].pc % QUANTUM) == 0) {
					
						//diminui prioridadE
						PROCESSOS::mudaPrioridade(pid_exec);

						//poe de volta na fila
						UTILS::insereProcessoFila(vet_processos[pid_exec]);

						// devolve processador
						PROCESSOS::atualizaEstado(pid_exec, 0);
					} 

			}

		}


		//incrementa clock
		clock_atual++;
		processos_novos.clear();

		//atualiza recursos

		
		//usleep(CLOCK);

		DEBUG::mostraEstadoProcessos ();
		if (!PROCESSOS::verificaExisteMaisProcessos()) {
			break;	
		}

		DEBUG::mostrarFilas();
		DEBUG::mostrarMemoria();

		getchar();
	}
	

	//DEBUG::mostrarProcesso(vet_processos[0]);
	//DEBUG::mostrarProcesso(vet_processos[1]);
	//DEBUG::mostrarFilaPrioridadeZero();

	return 0;
}
