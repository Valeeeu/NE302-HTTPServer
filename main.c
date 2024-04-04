#include "isX.h"


int main(int argc, char *argv[]) {
    
    if(argc != 2){
        printf("Erreur dans le nombre d'arguments\n");
        return 0;
    }

    FILE *ftest = fopen(argv[1], "r");
    if (ftest == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", argv[1]);
        return -1;
    }
    
    fseek(ftest, 0, SEEK_END);
    size_t len = ftell(ftest);
    char *line = (char *) malloc(len);
    char *tmp = NULL;
    fseek(ftest, 0, SEEK_SET);

    ssize_t read = 0;
    int count = 0;
    bool fst, snd = false;
    while((read = getline(&tmp, &len, ftest)) != -1) {
        if (fst == false && snd == false) { fst = true; }
        else if (fst == true && snd == false) { snd = true; continue; }
    
        strcpy(line+count, tmp); 
        count += read;
        fseek(ftest, count-1, SEEK_SET);
    }

    if (line != NULL) {
        Element *req = isHTTPMessage(line, len);

        if (req == NULL) {
            printf("Erreur dans la lecture du message\n");
            exit(1);
        } else { printArbre(req, 0); }
    }

    fclose(ftest);
    if (line) free(line);
    return 0;
}


