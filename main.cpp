/**
 * Implementação de Lista Sequencial de forma estruturada.
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//Declaração dos métodos
int leitura();
bool inserirInicio(int lista[], int valor, int &n);
bool inserirPosicao(int lista[], int k, int valor, int &n);
bool inserirFim(int lista[], int valor, int &n);
bool inserirOrdenado(int lista[], int valor, int &n);
bool excluirInicio(int lista[], int &n);
bool excluirPosicao(int lista[], int k, int &n);
bool excluirFim(int lista[], int &n);
bool excluirValor(int lista[], int valor, int &n);
int procurarPosicao(int lista[], int k, int &n);
int procurarValor(int lista[], int valor, int &n);
string listar(int lista[], int n);
bool estaCheia(int n);
bool estaVazia(int n);
int getQuantidade(int n);

/**
 * Tamanho máximo da lista.
 */
const int TAMANHO_LISTA = 100;

/**
 * Realiza a leitura dos dados dos nós.
 *
 * @return O valor lido.
 */
int leitura() {
    cout << "\nDigite um valor: ";
    int valor = 0;
    cin >> valor;
    return valor;
}

/**
 * Insere um Nó no início da lista.
 *
 * @param lista Lista dos Nós.
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @param n Quantidade de elementos da lista.
 * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
 */
bool inserirInicio(int lista[], int valor, int &n) {
    if (n < TAMANHO_LISTA) {
        //Desloca os Nós do fim até a posição 0
        for (int i = n; i >= 0; i--) {
            lista[i + 1] = lista[i];
        }
        //Insere o novo valor na posição 0.
        lista[0] = valor;
        //Incrementa a quantidade de Nós.
        n = n + 1;
        return true;
    } else {
        cout << "Inserir início - Lista cheia" << endl;
        return false;
    }
}

/**
 * Insere um Nó em uma posição especifica da lista.
 *
 * @param lista Lista dos nós. 
 * @param k Posição a ser inserida o valor.
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @param n Quantidade de elementos da lista.
 * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
 */
bool inserirPosicao(int lista[], int k, int valor, int &n) {

    if (n < TAMANHO_LISTA) {
        //Verifica se a posição está no intervalo de valores da lista.
        if (k >= 0 && k < n) {
            //Desloca os Nós do fim até a posição k
            for (int i = n; i >= k; i--) {
                lista[i + 1] = lista[i];
            }
            //Insere o novo valor na posição k.
            lista[k] = valor;
            //Incrementa a quantidade de Nós.
            n = n + 1;
            return true;
        } else {
            cout << "Inserir Posição - Posição inválida." << endl;
            return false;
        }
    } else {
        cout << "Inserir Posição - Lista cheia." << endl;
        return false;
    }
}

/**
 * Insere um Nó no final da lista.
 *
 * @param lista Lista dos Nós.
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @param n Quantidade de elementos da lista. 
 * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
 */
bool inserirFim(int lista[], int valor, int &n) {
    if (n < TAMANHO_LISTA) {
        //Insere o novo valor na posição n.
        lista[n] = valor;
        //Incrementa a quantidade de Nós.
        n = n + 1;
        return true;
    } else {
        cout << "Inserir Fim - Lista cheia." << endl;
        return false;
    }
}

/**
 * Inclui de forma ordenado um Nó na lista levando em consideração o seu
 * valor.
 *
 * @param lista Lista dos Nós.
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @param n Quantidade de elementos da lista. 
 * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
 */
bool inserirOrdenado(int lista[], int valor, int &n) {
    if (n < TAMANHO_LISTA) {
        int j = 0;
        while ((j < n) && (valor > lista[j])) {
            j = j + 1;
        }
        if (j <= n) {
            //Desloca os Nós do fim até a posição j
            for (int i = n - 1; i >= j; i--) {
                lista[i + 1] = lista[i];
            }
            //Insere o novo valor na posição j
            lista[j] = valor;
            //Incrementa a quantidade de Nós.
            n = n + 1;
            return true;
        }
        return false;
    } else {
        cout << "Inserir Ordenado - Lista cheia." << endl;
        return false;
    }
}

/**
 * Excluir um Nó do início da lista.
 *
 * @param lista Lista dos Nós.
 * @param n Quantidade de elementos da lista. 
 * @return Verdadeiro ou falso se excluiu o valor do início.
 */
bool excluirInicio(int lista[], int &n) {
    if (n != 0) {
        //Desloca os Nós do fim até a posição k da lista.
        for (int i = 0; i < n; i++) {
            lista[i] = lista[i + 1];
        }
        //Decrementa a quantidade de Nós da lista.
        n = n - 1;
        return true;
    } else {
        cout << "Excluir início - Lista vazia." << endl;
        return false;
    }
}

/**
 * Excluir um Nó da lista pela posição.
 *
 * @param lista Lista dos Nós.
 * @param k Posição do Nó a ser excluído da lista.
 * @param n Quantidade de elementos da lista.  
 * @return Verdadeiro ou falso se excluiu o valor da posição.
 */
bool excluirPosicao(int lista[], int k, int &n) {
    if (n != 0) {
        //Verifica se a posição está no intervalo de Nós da lista.
        if ((k >= 0) && (k < n)) {
            //Desloca os Nós do fim até a posição k da lista.
            for (int i = k; i < n; i++) {
                lista[i] = lista[i + 1];
            }
            //Decrementa a quantidade de Nós da lista.
            n = n - 1;
            return true;
        } else {
            cout << "Excluir início - Posição inválida." << endl;
            return false;
        }
    } else {
        cout << "Excluir posição - Lista vazia." << endl;
        return false;
    }
}

/**
 * Excluir um Nó do final da lista.
 *
 * @param lista Lista dos Nós.
 * @param n Quantidade de elementos da lista. 
 * @return Verdadeiro ou falso se excluiu o valor do final.
 */
bool excluirFim(int lista[], int &n) {
    if (n != 0) {
        //atribui 0 para posição final
        lista[n - 1] = 0;
        //Decrementa a quantidade de Nós da lista.
        n = n - 1;
        return true;
    } else {
        cout << "Excluir fim - Lista vazia." << endl;
        return false;
    }
}

/**
 * Excluir um Nó da lista pelo valor.
 *
 * @param lista Lista dos Nós.
 * @param valor Um valor de um nó a ser excluído da lista.
 * @param n Quantidade de elementos da lista. * 
 * @return Verdadeiro ou falso se excluiu o valor.
 */
bool excluirValor(int lista[], int valor, int &n) {
    if (n != 0) {
        int j = 0;
        //Procura a posição do Nó na lista.
        //Compara o valor na lista ou até chegar no final da lista.
        while ((j < n) && (valor != lista[j])) {
            j = j + 1;
        }
        //Verifica se a posição esta dentro do intervalo da lista
        if (j < n) {
            //Desloca os Nós do fim até a posição j da lista.
            for (int i = j; i < n; i++) {
                lista[i] = lista[i + 1];
            }
            //Decrementa a quantidade de Nós da lista.
            n = n - 1;
            return true;
        } else {
            cout << "Excluir valor - Valor não esta na lista." << endl;
            return false;
        }
    } else {
        cout << "Excluir valor - Lista vazia." << endl;
        return false;
    }
}

/**
 * Retorna o dado de uma posição na lista.
 *
 * @param lista Lista dos Nós.
 * @param k Posição do nó a ser consultado na lista.
 * @param n Quantidade de elementos da lista. *  
 * @return A posição de valor na lsita.
 */
int procurarPosicao(int lista[], int k, int &n) {
    if (n != 0) {
        //Verifica se a posição esta dentro do intervalo da lista
        if ((k >= 0) && (k < n)) {
            return lista[k];
        } else {
            cout << "Procurar posição - Posição inválida." << endl;
            return -1;
        }
    } else {
        cout << "Procurar posição - Lista vazia." << endl;
        return -1;
    }
}

/**
 * Retorna a posição de um Nó na lista.
 *
 * @param lista Lista dos Nós.
 * @param valor Valor a ser procurado na lista.
 * @param n Quantidade de elementos da lista. *   
 * @return A posição de valor na lsita.
 */
int procurarValor(int lista[], int valor, int &n) {
    if (n != 0) {
        int i = 0;
        //Procura a posição do Nó na lista.
        //Compara o valor na lista ou até chegar no final da lista.
        while ((i < n) && (valor != lista[i])) {
            i = i + 1;
        }
        //Verifica se a posição esta dentro do intervalo da lista
        if (i < n) {
            return i;
        } else {
            return -1;
        }
    } else {
        cout << "Procurar valor - Lista vazia." << endl;
        return -1;
    }
}

/**
 * Lista os dados da lista.
 *
 * @param lista Lista dos Nós.
 * @param n Quantidade de Nós da lista.
 * @return Uma String com os dados da lista.
 */
string listar(int lista[], int n) {
    //String de retorno
    string temp = "";
    for (int i = 0; i < n; i++) {
        temp = temp + to_string(i) + "-" + to_string(lista[i]) + "\n";
    }
    return temp;
}

/**
 * Retorna se a lista está cheia.
 * @param n Quantidade de Nós da lista.
 * @return Verdadeiro ou falso se a lista está cheia.
 */
bool estaCheia(int n) {
    return (n == TAMANHO_LISTA);
}

/**
 * Retorna se a lista esta vazia.
 * @param n Quantidade de Nós da lista.
 * @return Verdadeiro ou falso se a lista está vazia.
 */
bool estaVazia(int n) {
    return n == 0;
}

/**
 * Retorna a quantidade de Nós da lista.
 * @param n Quantidade de Nós da lista.
 * @return A quantidade de Nós da lista.
 */
int getQuantidade(int n) {
    return n;
}

int main() {
    /**
     * Declaração da lista
     */
    int lista[TAMANHO_LISTA];
    // Controla o menu da lista
    int opcao = -1;

    /**
     * Tamanho atual da lista.
     */
    int n = 0;

    //Laço do menu de opções
    while (opcao != 99) {
        //Monta o menu de opções        
        cout << "\n\t### Lista Sequencial ###\n"
                << "Selecione a opção desejada:\n"
                << " 1- Listar Nós\n"
                << " 2- Inserir Nó no início\n"
                << " 3- Inserir Nó no fim\n"
                << " 4- Inserir Nó em uma posição especifica\n"
                << " 5- Inserir Nó ordenado\n"
                << " 6- Remover Nó do início\n"
                << " 7- Remover Nó do fim\n"
                << " 8- Remover Nó de uma posição específica\n"
                << " 9- Remover Nó pelo valor\n"
                << "10- Procurar o dado de uma posição específica\n"
                << "11- Procurar a posição de um dado\n"
                << "12- Mostrar a quantidade de Nós\n"
                << "13- Está cheia?\n"
                << "14- Está vazia?\n"
                << "99- Sair\n"
                << " Opcao:";
        cin >> opcao;
        switch (opcao) {
            case 1:
            {
                if (estaVazia(n)) {
                    cout << "\nLista vazia!" << endl;
                } else {
                    cout << "\nListagem \n" << listar(lista, n) << endl;
                }
                break;
            }
            case 2:
            {
                //Preenche o valor do dado
                int dado = leitura();
                if (inserirInicio(lista, dado, n) == true) {
                    cout << "\nNó inserido no início com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido no início!" << endl;
                }
                break;
            }
            case 3:
            {
                //Preenche o valor do dado
                int dado = leitura();
                if (inserirFim(lista, dado, n) == true) {
                    cout << "\nNó inserido no fim com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido no fim!" << endl;
                }
                break;
            }
            case 4:
            {
                int k;
                cout << "\nDigite a posição a ser inserido:";
                cin >> k;
                //Preenche o valor do dado
                int dado = leitura();
                if (inserirPosicao(lista, dado, k, n) == true) {
                    cout << "\nNó inserido na posição " << k << " com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido na posição " << k << "!" << endl;
                }
                break;
            }
            case 5:
            {
                //Preenche o valor do dado
                int dado = leitura();
                if (inserirOrdenado(lista, dado, n) == true) {
                    cout << "\nNó inserido ordenado com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido ordenado!" << endl;
                }
                break;
            }
            case 6:
            {
                if (excluirInicio(lista, n)) {
                    cout << "\nO Nó do início foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nNó do início não foi excluído!" << endl;
                }
                break;
            }
            case 7:
            {
                if (excluirFim(lista, n)) {
                    cout << "\nO Nó da fim foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nNó do fim não foi excluído!" << endl;
                }
                break;
            }
            case 8:
            {
                int k;
                cout << "\nDigite a posição a ser excluída:";
                cin >> k;
                if (excluirPosicao(lista, k, n)) {
                    cout << "\nO valor da posição " << k << " foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nValor não foi excluído!" << endl;
                }
                break;
            }
            case 9:
            {
                //Preenche o valor do dado                 
                int dado;
                cout << "\nDigite o valor do dado a ser excluído:";
                cin >> dado;
                if (excluirValor(lista, dado, n)) {
                    cout << "\nO valor " << dado << " foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nValor não foi excluído!" << endl;
                }
                break;
            }
            case 10:
            {
                int k;
                cout << "\nDigite a posição do dado a ser procurada:";
                cin >> k;
                int dado = procurarPosicao(lista, k, n);
                if (dado != -1) {
                    cout << "\nO valor da posição " << k << "  possui o dado = " << dado << endl;
                } else {
                    cout << "\nA posição " << k << " não está preenchida" << endl;
                }
                break;
            }
            case 11:
            {
                int chave;
                cout << "\nDigite o valor do dado a ser procurado:";
                cin >> chave;
                int posicao = procurarValor(lista, chave, n);
                cout << "\nO valor " << chave << " esta na posição " << posicao << endl;
                break;
            }
            case 12:
            {
                cout << "\nQuantidade de Nós na lista : " << getQuantidade(n) << endl;
                break;
            }
            case 13:
            {
                cout << "\nLista está cheia : " << estaCheia(n) << endl;
                break;
            }
            case 14:
            {
                cout << "\nLista está vazia : " << estaVazia(n) << endl;
                break;
            }
        }//Fim Switch
    }//Fim While
    return 0;
}