#include "defines.h"


//Verifica se o processo precisa de algum recurso e retorna:-1 se pelo menos algum estiver ocupado e 1 se todos livres
int RECURSOS::verificaRecurso(int pid){
	
	//verifica se precisa de impressora
	if (vet_processos[pid].impressora==1){

		//verifica se as impressoras estao ocupadas
		if(((impressora[0]!=-1)&&(impressora[0]!=pid))&&((impressora[1]!=-1)&&(impressora[1]!=pid))){
			return -1;
		}
	}
	//verifica se precisa de disco
	if (vet_processos[pid].disco==1){
		//verifica se os discos estao ocupados
		if(((disco[0]!=-1)&&(disco[0]!=pid))&&((disco[1]!=-1)&&(disco[1]!=pid))){
			return -1;
		}
	}
	
	//verifica se precisa de modem
	if (vet_processos[pid].modem==1){
		//verifica se o modem esta ocupado
		if((modem!=-1)&& (modem!=pid)){
			return -1;
		}
	}

	//verifica se precisa de scanner
	if (vet_processos[pid].scanner==1){
		//verifica se o scanner esta ocupados
		if((scanner!=-1)&& (scanner!=pid)){
			return -1;
		}
	}
	//se todos estiverem livres retorna 1;
	return 1;
}


//aloca os recursos requisitados pelo processo
void RECURSOS::alocaRecurso(int pid){
	

	//verifica se o processo precisa de impressora
	if (vet_processos[pid].impressora==1){
		//verifica se as impressoras estao ocupadas
		if(impressora[0]==-1&&impressora[1]!=pid)
			//aloca o recurso
			impressora[0]=pid;
		else//testa a outra impressora
			if(impressora[1]==-1&&impressora[0]!=pid)
			//aloca o recurso
			impressora[1]=pid;
	}
	//verifica se o processo precisa de disco
	if (vet_processos[pid].disco==1){
		
		if(disco[0]==-1&&disco[1]!=pid)
			disco[0]=pid;
		else
			if(disco[1]==-1&&disco[0]!=pid)
			disco[1]=pid;
	}
		
	if (vet_processos[pid].modem==1)
		modem = pid;
	

	if (vet_processos[pid].scanner==1)
		scanner =pid;
	
}
//Insere o processo nas filas dos recursos pedidos 
void RECURSOS::insereFilaRecurso(int pid){
	
	if (vet_processos[pid].impressora==1){
		fila_impressora.push(pid);
	}

	if (vet_processos[pid].disco==1){
		fila_disco.push(pid);
	}

		
	if (vet_processos[pid].modem==1){
		fila_modem.push(pid);
	}

	if (vet_processos[pid].scanner==1){
		fila_scanner.push(pid);
	}

}

void RECURSOS::liberaRecurso(int pid){

	if (vet_processos[pid].impressora==1){
		//verifica se as impressoras estao ocupadas
		if(impressora[0]==pid)
			impressora[0]=-1;
		if (impressora[1]==pid)
			impressora[1]=-1;
	}

	if (vet_processos[pid].disco==1){
		//verifica se as impressoras estao ocupadas
		if(disco[0]==pid)
			disco[0]=-1;
		else if (disco[1]==pid)
			disco[1]=-1;
	}

		
	if (vet_processos[pid].modem==1){
		//verifica se os discos estao ocupadas
		if(modem==pid)
			modem = -1;
	}

	if (vet_processos[pid].scanner==1){
		//verifica se os discos estao ocupadas
		if(scanner==pid)
			scanner =-1;
	}

}

//atualiza os recursos vazios com os proximos da fila
void RECURSOS::atualizaRecurso(){
	

	if (impressora[0] == -1) {
		if(fila_impressora.size()!=0){
			impressora[0]=fila_impressora.front();
			fila_impressora.pop();
		}
	}
	if (impressora[1] == -1) {
		if(fila_impressora.size()!=0){
			impressora[1]=fila_impressora.front();
			fila_impressora.pop();
		}
	}
	if (scanner== -1) {
		if(fila_scanner.size()!=0){
		scanner=fila_scanner.front();
		fila_scanner.pop();
		}
	}	
	
	if (modem== -1) {
		if(fila_modem.size()!=0){
		modem=fila_modem.front();
		fila_scanner.pop();
		}
	}
	if (disco[0] == -1) {
		if(fila_disco.size()!=0){ 
			disco[0]=fila_disco.front();
			fila_disco.pop();
		}
	}
	if (disco[1]== -1) {
		if(fila_disco.size()!=0){ 
			disco[1]=fila_disco.front();
			fila_disco.pop();
		}
	}	
}

//inicializa os recursos com valores indicando disponibilidade
void RECURSOS::inicializaRecurso(){
	
	impressora.push_back(-1);
    impressora.push_back(-1);
	disco.push_back(-1);
	disco.push_back(-1);
	scanner =-1;
	modem = -1;

}