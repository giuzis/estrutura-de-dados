#include "arvores1.h"

using namespace std;

node* newNode (int dado)
{
	node *aux;
	aux = new node;
    aux->info = dado; 
    aux->left = NULL;
    aux->right = NULL;
    return(aux);
}

int insere (node **no, int dado)
{
    if(*no == NULL)
    {
        *no = newNode(dado);
        cout << "Dado inserido! " << endl;
    	return 1;
    }
    else 
    {
        if(dado < ((*no)->info))
            return(insere(&(*no)->left, dado));
        else
        {
            if(dado > ((*no)->info))
        	    return(insere(&(*no)->right, dado));
        	else 
        	{
        		cout << "Dado ja inserido. " << endl;
        		return 0;
        	}
        }
    }
}

int imprime (node** pilha, node* no, int i)
{
	if (i == 0)
		cout << "Raiz: " << no->info;
	else
		cout << "No " << no->info << ": ";
	if (no->left == NULL)
		cout << " FE: -1";
	else
	{
		cout << " FE: " << no->left->info;
		i++;
		pilha[i] = no->left;
	}
	if (no->right == NULL)
		cout << " FD: -1" << endl;
	else
	{
		cout << " FD: " << no->right->info << endl;
		i++;
		pilha[i] = no->right;
	}
	return i;
}

void mostraArvore (node* no, int n_elementos)
{
	int iteracoes = 0, counter_elementos = 0;
	node **pilha;
	pilha = new node*[n_elementos];
	pilha[counter_elementos] = no;

	if(no == NULL)
	{
		cout << "Arvore vazia. " << endl;
	}
	while (iteracoes < n_elementos)
	{
		counter_elementos = imprime(pilha, pilha[iteracoes], counter_elementos);
		iteracoes++;
	}
}

void achaNULL (node* no)
{
	node* aux;
	node* aux2 = no;
	int direcao = 2;

	aux = no->right;
	while (aux->left != NULL)
	{
		direcao = 1;
		aux2 = aux;
		aux = aux->left;
	}
	if(aux->right == NULL)
	{
		no->info = aux->info;
		if(direcao == 2)
			aux2->right = NULL;
		else
			aux2->left = NULL;
		delete aux;
	}
	else
	{
		no->info = aux->info;
		if(direcao == 2)
			aux2->right = aux->right;
		else
			aux2->left = aux->right;
		delete aux;
	}
}

void substitui (node* no, node* substituto, int direcao)
{
	if(direcao == 1)
	{
		no->left = substituto;
	}
	else
	{
		if(direcao == 2)
			no->right = substituto;
		else
		{
			no->info = substituto->info;
			no->left = substituto->left;
			no->right = substituto->right;
			delete(substituto);
		}

	}

}

int remove(node** raiz, int dado)
{
	int flag = 0, direcao = 0;
	node* aux = *raiz;
	node* aux2 = *raiz;

	if(raiz == NULL)
	{
		cout << "Arvore vazia. " << endl;
		return 0;
	}
	while (!flag)
	{
		if(dado < aux->info)
		{
			aux2 = aux;
			aux = aux->left;
			direcao = 1;
		}
		else
		{
			if(dado > aux->info)
			{
				aux2 = aux;
				aux = aux->right;
				direcao = 2;
			}
			else
			{
				flag = 1;
			}
		}
		if(aux == NULL)
		{
			cout << "Dado inexistente " << endl;
			return 0;
		}
	}

	if((aux->right != NULL) && (aux->left != NULL))
	{
		achaNULL(aux);
	}
	else
	{
		if(aux->left != NULL)
		{				
			substitui(aux2, aux->left, direcao);
			if(direcao != 0) delete (aux);
		}
		else
		{
			if(aux->right != NULL)
			{
				substitui(aux2, aux->right, direcao);
				if(direcao != 0) delete (aux);
			}
			else
			{
				if (direcao == 0)
				{
					delete(*raiz);
					*raiz = NULL;
				}
				else
					substitui(aux2, NULL, direcao);
			}
		}		
	}
	return 1;
}