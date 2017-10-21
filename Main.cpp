/* Agenda de cadastro de contatos
Autor : Raffael Bottoli Schemmer
Revisão de projeto : Agenda_Rev_5.0
Data de Inicio : 25/03/2008 Termino : 31/03/2008
*/
#include<iostream> // Declaracão de bibliotecas
#include<string>
#include "Funcoes.hpp" // Inclusão do arquivo de cabecalho Funcoes.hpp
#define TAM2 100 // Constante TAM2 que define o tamanho do vetor de cadastro em 100 elementos(contatos)
using namespace std;
struct endereco 
{
	string rua;
	string bairro;
	string cidade;
	string CEP;
};
extern struct agenda // Estrutura principal pelo cadastro permanente de contatos da agenda sendo referenciada como extern(declarada em outro arquivo)
{
	string nome;
	struct endereco end;
	int estado_civil;
	int sexo;
	string celular;
	string residencial;
}*cadastro[TAM2];
struct temp // Estrutura responsavel pelo cadastro temporario de contatos(Para depois passar eles como parametros)
{
	string rua;
	string bairro;
	string cidade;
	string CEP;
	string nome;
	string celular;
	string residencial;
	int estado_civil;
	int sexo;
}temp;
int main()
{
	int opcao,x,aux,flag=0; 
	int retorno,retorno_posicao;
	char vet[TAM2]; // Declaracão do vetor vet de indice TAM que informa (-) para posicões livres e (*) para posicões ocupadas
	for(x=0;x<TAM2;x++) // Estrutura que limpa o vetor vet colocando todas as opcões como livres (-)
	{
		vet[x] = '-';
	}
	do
	{
		system("cls");
		cout << "\n\n\t\t        || ------------- Agenda ------------- ||"; // Menu de interacão com o usuario
		cout << "\n\n\n\t\t1 - Cadastrar Contato";
		cout << "\n\t\t2 - Excluir Contato";
		cout << "\n\n\t\t3 - Procurar Contato por nome";
		cout << "\n\t\t4 - Procurar Contato por Estado Civil";
		cout << "\n\n\t\t5 - Procurar Contato por Sexo";
		cout << "\n\t\t6 - Procurar Contato por Sexo e por Estado Civil";
		cout << "\n\n\t\t7 - Listar todos os Contatos Cadastrados";
		cout << "\n\t\t8 - Sair";
		cout << "\n\n\n\n\t\t\t\t\t\t\t\tOpcao [ ]\b\b";
		cin >> opcao; // Coloca em Opcao a selacão de usuario
		cin.get();
		if(opcao < 1 || opcao > 8) // Teste que informa ao usuario caso a entrada seja invalida
		{
			cout << "\nOpcao Invalida !! Digite novamente...\n\n";
			system("pause");
			system("cls");
			continue;
		}
		switch(opcao) 
		{
			case(1): // Cadastra Contatos
			{
				for(x=0;x<TAM2;x++)
				{
					if(vet[x] == '-') // caso o vetor na posicão x for (-) então cadastra um contato
					{
						system("cls");
						flag=1; // Flag que indica que ao menos um contato foi encontrado
						do
						{
							cout << "\n\t\t|| ---------- Cadastrando um Contato ---------- ||"; // Coloca todos os dados abaixo na estrutura temp
							cout << "\n\n\nDigite seu nome Ex(Raffael Bottoli Schemmer): "; // Solicita que o usuario informe um nome e cadastra um nome
							getline(cin,temp.nome);
							retorno = procura_nome(vet,temp.nome,&retorno_posicao); // Chama a funcao procura_nome para ver se existe um nome como o informado já cadastrado na agenda
							if(retorno == 1)// Se sim ele informa ao usuario e solicita um nome nome
							{
								cout << "\nO nome " << temp.nome << " ja esta cadastrado na agenda\n\n";
								system("pause");
								system("cls");
							}
						}while(retorno == 1); // Só sai até que o usuario digite um nome que não conste na agenda
						cout << "\nDigite o nome da rua Ex:(Largo Sao Francisco): ";  // Solicita que o usuario informe uma rua e cadastra a rua
						getline(cin,temp.rua);
						cout << "\nDigite o nome do bairro Ex(Jardim Sabo): ";  // Solicita que o usuario informe um bairro e cadastra um bairro
						getline(cin,temp.bairro);
						cout << "\nDigite o nome da cidade Ex(Santo Angelo): ";  // Solicita que o usuario informe uma cidade e cadastra um cidade
						getline(cin,temp.cidade);
						cout << "\nDigite o CEP Ex:(9800-000) : ";  // Solicita que o usuario informe um CEP e cadastra um CEP
						getline(cin,temp.CEP);
						cout << "\nDigite o celular Ex:(0xx99434453) : ";  // Solicita que o usuario informe um celular e cadastra um celular
						getline(cin,temp.celular);
						cout << "\nDigite o telefone residencial Ex:(3312-6224) : ";  // Solicita que o usuario informe um telefone residencial e cadastra um telefone residencial
						getline(cin,temp.residencial);
						do  // Solicita que o usuario informe um sexo e cadastra um sexo
						{
							system("cls");
							cout << "\n\t\t       || ---------- Digite o sexo ---------- ||";
							cout << "\n\n\n\t\t        1 - Feminino\n\t\t        2 - Masculino\n\n\n\t\t\t\t\t\t    Opcao [ ]\b\b";
							cin >> aux;
							if(aux < 1 || aux > 2)
							{
								cout << "\nOpcao Invalida !!\n\n";
								system("pause");
								system("cls");
							}
							else
							{
								temp.sexo = aux;
							}
						}while(aux < 1 || aux > 2);
						do  // Solicita que o usuario informe um estado civil e cadastra um estado civil
						{
							system("cls");
							cout << "\n\t\t   || ---------- Digite o Estado civil ---------- ||";
							cout << "\n\n\n\t\t    1 - Solteiro(a)\n\t\t    2 - Casado(a)\n\t\t    3 - Divorciado(a)\n\t\t    4 - Viuvo(a)\n\t\t    5 - Enrolado(a)\n\n\n\t\t\t\t\t\t    Opcao [ ]\b\b";
							cin >> aux;
							if(aux < 1 || aux > 5)
							{
								cout << "\nOpcao Invalida !!\n\n";
								system("pause");
								system("cls");
							}
							else
							{
								temp.estado_civil = aux;
							}
						}while(aux < 1 || aux > 5);		
						cadastra_contato(x,temp.nome,temp.rua,temp.bairro,temp.cidade,temp.CEP,temp.celular,temp.residencial,temp.estado_civil,temp.sexo); //Passa todos os dados da temp como parametros para a funcao cadastra_contato 
						vet[x] = '*'; // Coloca (*) na posicão vet[x] indicando que existe ali agora um contato cadastrado
						break;
					}
				}
				if(flag == 1) // Caso o flag for igual a 1 indica que o contato foi cadastrado com sucesso
				{
					cout << "\nContato Cadastrado com sucesso\n\n";
					flag=0;
				}	
				else if(flag == 0) // senão se o flag for igual a zero indica que não foi possivel cadastrar um contato(Memoria Insificiente)
				{
					cout << "\nNao foi possivel cadastrar o contato (Memoria Insuficiente !)\n\n";
				}
				system("pause");
				break; // Finaliza o case(1)
			}
			case(2): // Exclui um Contato
			{ 
				system("cls");
				for(x=0;x<TAM2;x++)
				{
					retorno = lista_contato(vet,x); // Chama a funcao lista_contato listando todos os contatos cadastrados na agenda
					if(retorno == 1) // se o retorno for igual a 1 significa que o indice x possui um contato cadastrado e este é listado
					{
						if(flag == 0)
						{
							cout << "\n\t\t|| ---------- Contatos Cadastrados ---------- ||\n\n";
						}
						flag = 1; // Flag que indica que ao menos um contato foi encontrado
						cout << "\nNome : " << cadastro[x]->nome; // Lista os dados do contato
						cout << "\nRua : " << cadastro[x]->end.rua;
						cout << "\nBairro : " << cadastro[x]->end.bairro;
						cout << "\nCidade : " << cadastro[x]->end.cidade;
						cout << "\nCEP : " << cadastro[x]->end.CEP;
						cout << "\nCelular : " << cadastro[x]->celular;
						cout << "\nTelefone Residencial : " << cadastro[x]->residencial;
						cout << "\nEstado Civil : " << lista_estado_civil(cadastro[x]->estado_civil);
						cout << "\nSexo : " << lista_sexo(cadastro[x]->sexo); 
						cout << "\n\n";
					}
				}
				if(flag == 0) // se o flag continuar valedo zero imprime que não foram encontrados contatos na agenda
				{	
					cout << "\n\t\t|| ---------- Contatos Cadastrados ---------- ||\n\n";
					cout << "\nNao existe contatos cadastrados na agenda\n\n";
					system("pause");
					flag = 0;
					break; // Para o case(2) caso não existirem contatos para serem excluidos
				}
				cout << "Digite o nome do contato que deseja excluir : ";  // Caso existirem contatos cadastrados, é solicitado um nome de um contato para excluir
				getline(cin,temp.nome);
				retorno = excluir_contato(retorno,vet,temp.nome); // chama a funcao exclui_contato passando como parametro o nome do contato como o vetor e seu indice
				if(retorno == 1) // se o retorno da funcao for igual a 1 retorna contato excluido com sucesso
				{
					cout << "\nO contato " << temp.nome << " foi excluido com sucesso\n\n";
					system("pause");
				}
				else if(retorno == 0) // se o retorno da funcao for igual a 0 retorna que não foi possivel excluir o contato
				{
					cout << "\nO contato " << temp.nome << "nao foi encontrado\n\n";
					system("pause");
				}
				break; // finaliza o case(2)
			}
			case(3): // Procura Contatos por Nome
			{
				system("cls");
				cout << "\n\t\t|| ---------- Procurando um Contato ---------- ||"; // Solicita que o usuario informe um nome
				cout << "\n\n\nDigite o nome que voce deseja procurar : ";
				getline(cin,temp.nome);
				retorno = procura_nome(vet,temp.nome,&retorno_posicao); // Passa o nome como parametro para a funcao procura_nome
				if(retorno == 1) // Caso o nome seja encontrado retorna 1
				{
					system("cls");
					cout << "\n\t\t   || ---------- Contato Encontrado ---------- ||";
					cout << "\n\n\nNome : " << cadastro[retorno_posicao]->nome; // Lista os dados do nome encontrado usando o ponteiro retorno_posicao como indice retornado pela funcao procura_nome
					cout << "\nRua : " << cadastro[retorno_posicao]->end.rua;
					cout << "\nBairro : " << cadastro[retorno_posicao]->end.bairro;
					cout << "\nCidade : " << cadastro[retorno_posicao]->end.cidade; 
					cout << "\nCEP : " << cadastro[retorno_posicao]->end.CEP; 
					cout << "\nCelular : " << cadastro[retorno_posicao]->celular; 
					cout << "\nTelefone Residencial : " << cadastro[retorno_posicao]->residencial;
					cout << "\nEstado Civil : " << lista_estado_civil(cadastro[retorno_posicao]->estado_civil);
					cout << "\nSexo : " << lista_sexo(cadastro[retorno_posicao]->sexo); 
					cout << "\n\n";
					system("pause");
				}
				else // Caso o nome não seja encontrado lista a mensagem abaixo
				{
					system("cls");
					cout << "\n\t\t|| ---------- Procurando um Contato ---------- ||\n\n";
					cout << "\nO contato " << temp.nome << " nao foi encontrado\n\n";
					system("pause");
				}
				break; // Fianliza o case(3)
			}
			case(4): // Procurar Contato por Estado Civil
			{	
				flag=0;
				do // Menu que solicita que o usuario informe o estado civil
				{
					system("cls");
					cout << "\n\t\t   || ---------- Digite o Estado civil ---------- ||";
					cout << "\n\n\n\t\t    1 - Solteiro(a)\n\t\t    2 - Casado(a)\n\t\t    3 - Divorciado(a)\n\t\t    4 - Viuvo(a)\n\t\t    5 - Enrolado(a)\n\n\n\t\t\t\t\t\t    Opcao [ ]\b\b";
					cin >> aux;
					if(aux < 1 || aux > 5)
					{
						cout << "\nOpcao Invalida !!\n\n";
						system("pause");
						system("cls");
					}
					else
					{
						temp.estado_civil = aux;
					}
				}while(aux < 1 || aux > 5);	
				system("cls");
				for(x=0;x<TAM2;x++)
				{
					retorno = procura_estado_civil(vet,temp.estado_civil,x);  // Passa como parametros o estado civil como o vetor e o indice da estrutura que varre o vetor de cadastros
					if(retorno == 1) // Se o retorno for 1 indica que existe um contato com o estado civil, e este é listado abaixo
					{
						if(flag == 0)
						{
							cout << "\n\t\t   || ---------- Contatos Encontrados ---------- ||";
						}
						flag=1;// Flag que indica que um contato foi encontrado
						cout << "\n\n\nNome : " << cadastro[x]->nome;
						cout << "\nRua : " << cadastro[x]->end.rua;// Lista os dados do contato cadastrado
						cout << "\nBairro : " << cadastro[x]->end.bairro;
						cout << "\nCidade : " << cadastro[x]->end.cidade; 
						cout << "\nCEP : " << cadastro[x]->end.CEP; 
						cout << "\nCelular : " << cadastro[x]->celular; 
						cout << "\nTelefone Residencial : " << cadastro[x]->residencial;
						cout << "\nEstado Civil : " << lista_estado_civil(cadastro[x]->estado_civil);
						cout << "\nSexo : " << lista_sexo(cadastro[x]->sexo); 
						cout << "\n\n";
					}
				}
				if(flag == 0) // Se o flag não for atrabuido 1 significa que não existe contatos cadastrados na agenda, e o bloco abaixo é executado
				{
					system("cls");
					cout << "\n\t\t|| ---------- Procurando um Contato ---------- ||\n\n";
					cout << "\nO estado civil " << lista_estado_civil(temp.estado_civil) << " nao foi encontrado\n\n";
					system("pause");
					break;
				}
				system("pause");
				break;// Pausa e finaliza o case(4)
			}
			case(5): // Procurar Contato por Sexo
			{
				flag=0;
				do // Menu que solicita que o usuario informe o sexo
				{
					system("cls");
					cout << "\n\t\t       || ---------- Digite o sexo ---------- ||";
					cout << "\n\n\n\t\t        1 - Feminino\n\t\t        2 - Masculino\n\n\n\t\t\t\t\t\t    Opcao [ ]\b\b";
					cin >> aux;
					if(aux < 1 || aux > 2)
					{
						cout << "\nOpcao Invalida !!\n\n";
						system("pause");
						system("cls");
					}
					else
					{
						temp.sexo = aux;
					}
				}while(aux < 1 || aux > 2);
				system("cls");
				for(x=0;x<TAM2;x++)
				{
					retorno = procura_sexo(vet,temp.sexo,x);  // Passa como parametros o sexo como o vetor e o indice da estrutura que varre o vetor de cadastros
					if(retorno == 1) // Se o retorno for 1 indica que existe um contato com o sexo, e este é listado abaixo
					{
						if(flag == 0)
						{
							cout << "\n\t\t   || ---------- Contato Encontrado ---------- ||\n\n";
						}
						flag=1;  // Flag que indica que um contato foi encontrado
						cout << "\nNome : " << cadastro[x]->nome;
						cout << "\nRua : " << cadastro[x]->end.rua; // Lista os dados do contato cadastrado
						cout << "\nBairro : " << cadastro[x]->end.bairro;
						cout << "\nCidade : " << cadastro[x]->end.cidade; 
						cout << "\nCEP : " << cadastro[x]->end.CEP; 
						cout << "\nCelular : " << cadastro[x]->celular; 
						cout << "\nTelefone Residencial : " << cadastro[x]->residencial;
						cout << "\nEstado Civil : " << lista_estado_civil(cadastro[x]->estado_civil);
						cout << "\nSexo : " << lista_sexo(cadastro[x]->sexo); 
						cout << "\n\n";
					}
				}
				if(flag == 0) // Se o flag não for atrabuido 1 significa que não existe contatos cadastrados na agenda, e o bloco abaixo é executado
				{
					system("cls");
					cout << "\n\t\t|| ---------- Procurando um Contato ---------- ||\n\n";
					cout << "\nCadastros com o sexo " << lista_sexo(temp.sexo) << " nao foi encontrado\n\n";
					system("pause");
					break;
				}
				system("pause");
				break; // Pausa e finaliza o case(5)
			}
			case(6): // Procurar Contato por Sexo e por Estado Civil
			{
				flag=0;
				do // Menu que solicita que o usuario informe o sexo
				{
					system("cls");
					cout << "\n\t\t       || ---------- Digite o sexo ---------- ||";
					cout << "\n\n\n\t\t        1 - Feminino\n\t\t        2 - Masculino\n\n\n\t\t\t\t\t\t    Opcao [ ]\b\b";
					cin >> aux;
					if(aux < 1 || aux > 2)
					{
						cout << "\nOpcao Invalida !!\n\n";
						system("pause");
						system("cls");
					}
					else
					{
						temp.sexo = aux;
					}
				}while(aux < 1 || aux > 2);
				do // Menu que solicita que o usuario informe o estado civil
				{
					system("cls");
					cout << "\n\t\t   || ---------- Digite o Estado civil ---------- ||";
					cout << "\n\n\n\t\t    1 - Solteiro(a)\n\t\t    2 - Casado(a)\n\t\t    3 - Divorciado(a)\n\t\t    4 - Viuvo(a)\n\t\t    5 - Enrolado(a)\n\n\n\t\t\t\t\t\t    Opcao [ ]\b\b";
					cin >> aux;
					if(aux < 1 || aux > 5)
					{
						cout << "\nOpcao Invalida !!\n\n";
						system("pause");
						system("cls");
					}
					else
					{
						temp.estado_civil = aux;
					}
				}while(aux < 1 || aux > 5);	
				system("cls");
				for(x=0;x<TAM2;x++)
				{
					retorno = procura_sexo_estado_civil(vet,temp.sexo,temp.estado_civil,x); // Passa como parametros o sexo e o estado civil como o vetor e o indice da estrutura que varre o vetor de cadastros
					if(retorno == 1) // Se o retorno for 1 indica que existe um contato com o sexo e o estado civil, e este é listado abaixo
					{
						if(flag == 0)
						{
							cout << "\n\t\t   || ---------- Contato Encontrado ---------- ||\n\n";
						}
						flag=1; // Flag que indica que um contato foi encontrado
						cout << "\nNome : " << cadastro[x]->nome; // Lista os dados do contato cadastrado
						cout << "\nRua : " << cadastro[x]->end.rua;
						cout << "\nBairro : " << cadastro[x]->end.bairro;
						cout << "\nCidade : " << cadastro[x]->end.cidade; 
						cout << "\nCEP : " << cadastro[x]->end.CEP; 
						cout << "\nCelular : " << cadastro[x]->celular; 
						cout << "\nTelefone Residencial : " << cadastro[x]->residencial;
						cout << "\nEstado Civil : " << lista_estado_civil(cadastro[x]->estado_civil);
						cout << "\nSexo : " << lista_sexo(cadastro[x]->sexo); 
						cout << "\n\n";
					}
				}
				if(flag == 0) // Se o flag não for atrabuido 1 significa que não existe contatos cadastrados na agenda, e o bloco abaixo é executado
				{
					system("cls");
					cout << "\n\t\t|| ---------- Procurando um Contato ---------- ||\n\n";
					cout << "\nCadastros com o sexo " << lista_sexo(temp.sexo) << " e o estado civil " << lista_estado_civil(temp.estado_civil) << " nao foi encontrado\n\n";
					system("pause");
					break;
				}
				system("pause"); // Pausa e finaliza o case(6)
				break;
			}
			case(7):// Lista Contatos 
			{
				system("cls");
				flag=0;
				for(x=0;x<TAM2;x++) 
				{
					retorno = lista_contato(vet,x); // Varre o tamanho definido por TAM passando como parametros o valor da variavel x e comparando se vet indice x é igual a *(Ocupado)
					if(retorno == 1) // Se a posicão for ocupada (*) executa
					{
						if(flag == 0) 
						{ 
							cout << "\n\t\t|| ---------- Contatos Cadastrados ---------- ||\n\n";
						}
						flag = 1;
						cout << "\nNome : " << cadastro[x]->nome; // Informa os dados da posicão cadastrada na agenda
						cout << "\nRua : " << cadastro[x]->end.rua;
						cout << "\nBairro : " << cadastro[x]->end.bairro;
						cout << "\nCidade : " << cadastro[x]->end.cidade;
						cout << "\nCEP : " << cadastro[x]->end.CEP;
						cout << "\nCelular : " << cadastro[x]->celular;
						cout << "\nTelefone Residencial : " << cadastro[x]->residencial;
						cout << "\nEstado Civil : " << lista_estado_civil(cadastro[x]->estado_civil);
						cout << "\nSexo : " << lista_sexo(cadastro[x]->sexo); 
						cout << "\n\n";
					}
				}
				if(flag == 0) // Se o flag não for atrabuido 1 significa que não existe contatos cadastrados na agenda, e o bloco abaixo é executado
				{
					system("cls");
					cout << "\n\t\t|| ---------- Contatos Cadastrados ---------- ||\n\n";
					cout << "\nNao existe contatos cadastrados na agenda\n\n";
					system("pause");
					break;
				}
				system("pause"); // Pausa e finaliza o case(7)
				break;
			}
			case(8): // Sair
			{
				cout << "Obrigado por usar a agenda\n\n"; // Informa ao usuario e finaliza o switch
				system("pause");
				break;
			}
		}
	}while(opcao != 8); // Continua até que a opcao seja 8(Sair)
	return(0);
}
