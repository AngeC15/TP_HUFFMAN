
#include "arbrebin.h"
#include "bfile.h"
#include "fap.h"
#include "huffman_code.h"
#include <assert.h>
#include <stdio.h>

typedef struct {
    int tab[256];
} TableOcc_t;

struct code_char HuffmanCode[256];

void ConstruireTableOcc(FILE *fichier, TableOcc_t *TableOcc) {

    int c;

    /* A COMPLETER ... */
    printf("Programme non realise (ConstruireTableOcc)\n");

    c = fgetc(fichier);
    while (c != EOF) {
        /* A COMPLETER ... */
        //les char sont des entier donc à l'indice de l'entier on ajoute 1 pour chaque occurence
        //if( 0<c && c < 255){
            printf("%d \n ", c);
            TableOcc->tab[c]++;
        c = fgetc(fichier);
    };


    int i;
    for (i = 0; i < 256; i++) {
        if (TableOcc->tab[i] != 0)
            printf("Occurences du caractere %c (code %d) : %d\n", i, i,
                   TableOcc->tab[i]);
    }
}

fap InitHuffman(TableOcc_t *TableOcc) {
    /* A COMPLETER */
    //je parcours le tableau et je mets chaque élément à 0
    //printf("Programme non realise (InitHuffman)\n");
    //nouvelle FAP:
    fap new_fap;
    //pour chaque element de la tableOcc
    for(int i =0; i<256; i++){
        
        if(TableOcc->tab[i] > 0) {
            //si le nombre d'occurence est trop petit( 0 ou moins) on ne le mets pas dans la fap
            //on cree un arbe à partir de i
            Arbre n_elem = {i, NULL, NULL};
            //on ajoute cet arbre dans la FAP
            inserer(new_fap, n_elem , TableOcc->tab[i]);
        }
    }
    //on doit return une struct fap
    return new_fap;
}

Arbre ConstruireArbre(fap file) {
    /* A COMPLETER */
    printf("Programme non realise (ConstruireArbre)\n");
    //on doit return un struct Arbre
    return ArbreVide();
}


void ConstruireCode(Arbre huff) {
    /* A COMPLETER */
    printf("Programme non realise (ConstruireCode)\n");
}

void Encoder(FILE *fic_in, FILE *fic_out, Arbre ArbreHuffman) {
    /* A COMPLETER */
    printf("Programme non realise (Encoder)\n");
}

int main(int argc, char *argv[]) {

    TableOcc_t TableOcc;
    FILE *fichier;
    FILE *fichier_encode;

    //on ouvre le fichier
    fichier = fopen(argv[1], "r");
    /* Construire la table d'occurences */
    ConstruireTableOcc(fichier, &TableOcc);
    //il ferme le fichier
    fclose(fichier);

    /* Initialiser la FAP */
    fap file = InitHuffman(&TableOcc);

    /* Construire l'arbre d'Huffman */
    Arbre ArbreHuffman = ConstruireArbre(file);

        AfficherArbre(ArbreHuffman);

    /* Construire la table de codage */
    ConstruireCode(ArbreHuffman);

    /* Encodage */
    fichier = fopen(argv[1], "r");
    fichier_encode = fopen(argv[2], "w");

    Encoder(fichier, fichier_encode, ArbreHuffman);

    fclose(fichier_encode);
    fclose(fichier);

    return 0;
}
