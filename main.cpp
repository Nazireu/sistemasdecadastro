#include<stdio.h>
#include<stdlib.h>
struct aluno{
  double ra;
  char nome[20];
  struct aluno *anterior;
};
struct aluno *atual = NULL;

void buscar_por_nome_ou_parte_dele(){
	printf("funcao buscar_por_nome_ou_parte_dele() em dev...\n");
}

void excluir_todos(){
	printf("funcao excluir_todos() em dev...\n");
}

void exibir_maior_e_menor_nome_cadastrado(){
	printf("funcao exibir_maior_e_menor_nome_cadastrado() em dev...\n");
}

void cadastrar(){
     printf("#### Cadastro ####\n\n");
     struct aluno *anterior = atual;
     atual = (struct aluno *) malloc(sizeof(struct aluno));
     atual->anterior = anterior;
     
     printf("Digite o RA..: ");
     scanf("%lf",&atual->ra);
     
     printf("Digite o NOME: ");
     fflush(stdin);
     gets(atual->nome);
     
     printf("\nDados cadastrador com sucesso!");
}

void consultar(){
	printf("#### Consulta ####\n\n");
	printf("Digite o RA..: ");
	double ra;
	scanf("%lf",&ra);
	struct aluno *atual_aux = atual;
	struct aluno *proximo   = atual;
	while(atual_aux!=NULL){
		if (atual_aux->ra==ra){
			printf("Dados encontrados:\n");
			printf("RA   = %.0lf\n",atual_aux->ra);                    
			printf("NOME = %s\n\n",atual_aux->nome);
			break;
		}
		proximo = atual_aux;
        atual_aux = atual_aux->anterior;
	}
     
	if (atual_aux==NULL){
		printf("Nenhum registro foi encontrado!");
		return;
	}
	int opcao;
    for(;;){
	 	printf("O que deseja fazer:\n");
		printf("1 - Alterar\n");
		printf("2 - Excluir\n");
		printf("3 - voltar\n");
		printf("Opcao: ");
		scanf("%d",&opcao);
		if (opcao==1){
			printf("Digite os novos dados:\n");                     
			printf("RA   = ");                    
			scanf("%lf",&atual_aux->ra);
			printf("NOME = ");
			fflush(stdin);
			gets(atual_aux->nome);
			printf("Registro alterado com sucesso!");  
			break;
		}else if (opcao==2){
			printf("Deseja realmente excluir o registro\n");
			printf("Resposta (s/n): ");
			fflush(stdin);
			if (getchar()=='s'){
			  if (atual_aux == atual){
			      atual = atual->anterior;
			      free(atual_aux);
			  }else{               
			      proximo->anterior = atual_aux->anterior;
			      free(atual_aux); 
			  }
			  printf("Registro excluido com sucesso!");
			  return;             
			}else{
			  printf("Nenhum registro foi excluido!");                        
			}
		}else if (opcao==3){
			printf("Voltando ao menu inicial...");
			break;
		}else{
			printf("Opção inválida!");
		}
	}
}

void listar_todos(){
	printf("#### Exibindo todos os registros ####\n\n");
	struct aluno *atual_aux = atual;
	if (atual_aux==NULL){
		printf("\nNenhum registro foi encontrado!");
	}else{
		while(atual_aux!=NULL){
			printf("RA   = %.0lf",atual_aux->ra);                    
			printf("\nNOME = %s",atual_aux->nome);
			atual_aux = atual_aux->anterior;
			printf("\n----------------\n");
		}
	}
}


main(){
     int opcao;
     for(;;){
         system("cls");
         printf("#### SISTEMA DE GERENCIAMENTO DE ALUNOS ####\n\n");
         printf("1 - Cadastrar aluno\n");
         printf("2 - Consultar por RA\n");
         printf("3 - Listar todos\n");
         printf("4 - Buscar por nome (completo ou uma parte nome) - Em Dev\n");
         printf("5 - Excluir todos - Em Dev\n");
         printf("6 - Exibir o maior e o menor nome cadastrado - Em Dev\n");
         printf("7 - Sair\n\n");
		         
         printf("\nDigite a opcao desejada: ");
         scanf("%d",&opcao);
         system("cls");
         if (opcao==1){
            cadastrar();
         }else if (opcao==2){
            consultar();
         }else if (opcao==3){
            listar_todos();
         }else if (opcao==4){
         	//Desenvolver esta função
            buscar_por_nome_ou_parte_dele();
         }else if (opcao==5){
            //Desenvolver esta função
            excluir_todos();
         }else if (opcao==6){
            //Desenvolver esta função
            exibir_maior_e_menor_nome_cadastrado();
         }else if (opcao==7){
            printf("Saindo...");
            getch();
            break;
         }
         getch();
     }
}