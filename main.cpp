#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Criando a estrutura da lista
struct node{
	char nome[20];
	int idade;
	int id;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//Percorrendo a lista
//Entra no loop se != de NULL e mostra os dados contidos nos nós percorrendo a lista usando o next 
void printList(){
	struct node *ptr = head;
	printf("\n[");
	
	while(ptr != NULL){
		printf("%s,%d,%d) ", ptr->nome, ptr->idade, ptr->id);
		ptr = ptr->next; 
	}
	printf("]");
}

//Definindo prioridade
void insertFirst(char nome, int idade, int id){
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link -> nome = nome;
	link -> idade = idade;
	link -> id = id;
	link -> next = head;
	head = link;
	
}

//Eliminação do primeiro nó
struct node *deleteFirst(){
	struct node *tempLink = head; 
	head = head -> next; //passa o primeiro nó para o segundo
	free(tempLink); //limpa a memoria alocada do primeiro nó
	return tempLink;
} 

//Verificando o tamanho da lista
int lenght(){
	int lenght = 0; //inicia a verificação do tamanho a partir da posição 0
	struct node *current;
	for(current = head; current != NULL; current -> next){ //varre a lista após o head ate chegar no tail, onde lenght funciona como contador de nós
		lenght++;
	}
	return lenght;
}



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	printList();
	insertFirst("Ozzy Osbourne", 71, 1);
	insertFirst("Pendleton Ward", 37, 2);
	insertFirst("Gandalf The Grey", 2021, 3);
	insertFirst("William Higinbotham", 84, 4);
	insertFirst("Edmond Halley", 86, 5);
	
	printf("\n======= Lista =======\n\n");
	printf("Lista completa: ");
	printList();
	printf("\n")
	
	
	return 0;
}
