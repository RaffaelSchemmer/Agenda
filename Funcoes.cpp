#ifndef Fun__cpp // Caso n�o esteja definido Fun_cpp ele executa o codigo
#define Func_cpp // Define Func_cpp
#include<string>
#define TAM 100
using namespace std;
struct endereco 
{
	string rua;
	string bairro;
	string cidade;
	string CEP;
};
struct agenda // Estrutura principal pelo cadastro permanente de contatos da agenda 
{
	string nome;
	struct endereco end;
	int estado_civil;
	int sexo;
	string celular;
	string residencial;
}*cadastro[TAM];
string lista_estado_civil(int x) // Func�o que retorna uma string(O estado Civil) da entrada x feita na chamada da func�o
{
	switch(x) // Dependendo a entrada retorna um estado civil diferente
	{
		case(1):
		{
			return("Solteiro(a)");
			break;
		}
		case(2):
		{
			return("Casado(a)");
			break;
		}
		case(3):
		{
			return("Divorciado(a)");
			break;
		}
		case(4):
		{
			return("Viuvo(a)");
			break;
		}
		case(5):
		{
			return("Enrolado(a)");
			break;
		}
	}
}
string lista_sexo(int x) // Func�o que retorna uma string(O Sexo) da entrada x feita na chamada da func�o
{
	switch(x) // Dependendo a entrada retorna um tipo de string
	{
		case(1):
		{
			return("Feminino");
			break;
		}
		case(2):
		{
			return("Masculino");
			break;
		}
	}
}
void cadastra_contato(int x,string nome,string rua,string bairro, string cidade, string CEP,string celular,string residencial,int estado_civil,int sexo) // Cadastra um usuario
{
	cadastro[x] = new(agenda); // retorna para o ponteiro cadastro[x] um endereco de memoria que aponta para a primeira posic�o de memoria reservada de tamanho dados
	cadastro[x]->nome = nome;
	cadastro[x]->end.rua = rua;  // Cadastra no novo espaco de memoria os dados passados como parametros na estrutura cadastro indice x de tipo dados
	cadastro[x]->end.bairro = bairro;
	cadastro[x]->end.cidade = cidade;
	cadastro[x]->end.CEP = CEP;
	cadastro[x]->celular = celular;
	cadastro[x]->residencial = residencial;
	cadastro[x]->estado_civil = estado_civil;
	cadastro[x]->sexo = sexo;
}
int procura_nome(char vet[],string nome,int *retorno) // Procura um usuario por nome
{
	int x;
	for(x=0;x<TAM;x++) // Estrutura que corre o vetor de 0 at� TAM
	{
		if(vet[x] == '*') // Compara se a posic�o x do vetor possui um item cadastrado
		{
			if(cadastro[x]->nome == nome) // Compara para ver se o nome passado como parametro � igual ao cadastrado na agenda
			{
				*retorno = x; // retorna ao ponteiro passado como parametro a posic�o do nome no vetor
				return(1); // Retorna 1 informando que encontrou um nome igual ao informado
			}
		}
	}
	return(0); // Caso chegar at� aqui retorna zero informando que n�o encontrou um nome igual ao informado
}
int excluir_contato(int retorno,char vet[],string nome) // Funcao que exclui um contato
{
	int retorno_posicao; 
	retorno = procura_nome(vet,nome,&retorno_posicao); // Chama a funcao procura_nome passando como parametro  o nome passado como parametro pelo usuario a exclui_nome
	if(retorno == 1) // Caso o nome for igual a procura_nome vai retornar 1, e se o retorno for igual a 1 ele vai executar
	{
		delete(cadastro[retorno_posicao]); // deleta a area de memoria apontada pelo ponteiro
		vet[retorno_posicao] = '-'; // coloca (-) liberando a posic�o do contato no vetor de cadastros
		return(1); // retorna 1 informando que deletou o contato corretamente
	}
	else
	{
		return(0); // caso o nome n�o seja encontrado retorna zero indicando que n�o foi possivel deletar
	}
}
int lista_contato(char vet[],int x) // Funcao que lista os contatos cadastrados
{
	if(vet[x] == '*') // caso a posic�o informada no vetor de cadastros for (*) Ocupado ele retorna 1 
	{
		return(1);
	}
	else // Se a posic�o n�o for igual ele retorna zero
	{
		return(0);
	}
}
int procura_estado_civil(char vet[],int estado_civil,int x) // Func�o que procura contatos por estado civil
{
	if(vet[x] == '*')
	{
		if(cadastro[x]->estado_civil == estado_civil)
		{
			return(1);
		}
	}
	else
	{
		return(0);
	}
}
int procura_sexo(char vet[],int sexo,int x) // Func�o que procura contatos por sexo
{
	if(vet[x] == '*') // caso a posic�o informada no vetor de cadastros for (*) Ocupado ele entra
	{
		if(cadastro[x]->sexo == sexo) // Caso o sexo informado for igual ao da posic�o cadastrada ele retorna 1
		{
			return(1);
		}
	}
	else // Se a posic�o n�o for igual ele retorna zero
	{
		return(0); 
	}
}
int procura_sexo_estado_civil(char vet[],int sexo,int estado_civil,int x) // Func�o que procura contatos por sexo e por estado civil
{
	if(vet[x] == '*')  // caso a posic�o informada no vetor de cadastros for (*) Ocupado ele entra
	{
		if(cadastro[x]->sexo == sexo) // Caso o sexo informado for igual ao da posic�o cadastrada ele entra
		{
			if(cadastro[x]->estado_civil == estado_civil) // Caso o estado civil informado for igual ao da posic�o cadastrada ele retorna 1
			{
				return(1);
			}
		}
	}
	else // Se a posic�o n�o for igual ele retorna zero
	{
		return(0);
	}
}
#endif
