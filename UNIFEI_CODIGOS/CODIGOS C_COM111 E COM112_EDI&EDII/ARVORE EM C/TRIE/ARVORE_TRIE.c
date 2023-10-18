// C implementation of search and insert operations
// on Trie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Alphabet size (# of symbols)
#define ALPHABET_SIZE (100)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'A')

// trie node

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)

struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof (struct TrieNode));

    if (pNode) {
        int i;

        pNode->isEndOfWord = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node

void insert(struct TrieNode *root, const char *key) {
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false

bool search(struct TrieNode *root, const char *key) {
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

void carregaDicionario(char nomeArquivoEntrada[], struct TrieNode *root) {

    FILE *arq;
    char palavra [30] = "";

    arq = fopen(nomeArquivoEntrada, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo :/");
    }


    while (!feof(arq)) {

        fscanf(arq, "%s", &palavra);
        insert(root, palavra);
    }

    printf("Dicionario Carregado com Sucesso! \n\n");

    fclose(arq);
}

int main() {

    char nome_arquivo[] = "dicionario.txt";
    char palavraUsuario[100];
    int i;
    bool LetraPermitida = true;


    struct TrieNode *root = getNode();

    carregaDicionario(nome_arquivo, root);

    while (1) {
        printf("\n\t --- Insira a palavra que deseja buscar ou insira /q para sair: --- \n\n");
        scanf("%s", &palavraUsuario);

        if (strcmp(palavraUsuario, "/q") == 0)
            break;

        if (strlen(palavraUsuario) > 30) {
            printf("\n\t DESCULPE, O TAMANHO MAXIMO PARA A PALAVRA É DE 30 LETRAS \n");
            continue;
        }

        for (i = 0; i < strlen(palavraUsuario); i++) {
            if ((palavraUsuario[i] != 'A') || (palavraUsuario[i] != 'B')
                    || (palavraUsuario[i] != 'M') || (palavraUsuario[i] != 'I')
                    || (palavraUsuario[i] != 'O')) {
                printf("\n\t DESCULPE, AS LETRAS PERMITIDAS SÃO: A - B - M - I -O \n");
                LetraPermitida = false;
                break;
            }
        }
        
        if(!LetraPermitida)
            continue;

        if (strlen(palavraUsuario) > 30) {
            printf("\n\t DESCULPE, O TAMANHO MAXIMO PARA A PALAVRA É DE 30 LETRAS \n");
            continue;
        }

        // Search for different keys
        if (search(root, palavraUsuario))
            printf("\n\tA palavra: %s --- %s\n\n", palavraUsuario, "Esta na árvore TRIE");
        else
            printf("\n\n\tA palavra: %s --- %s\n", palavraUsuario, "Não foi encontrada na árvore TRIE");
    }

    return 0;
}
