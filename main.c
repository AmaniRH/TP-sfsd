#include<stdio.h>
#include<stdlib.h>
//part one 
// Structure pour représenter un enregistrement
struct Record {
    int key;
    // Ajouter d'autres champs si nécessaire
};

// Fonction pour créer un nouveau fichier
void createFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Erreur lors de la création du fichier");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

// Fonction pour insérer un enregistrement dans le fichier
void insertRecord(const char *filename, const struct Record *record) {
    FILE *file = fopen(filename, "ab");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier pour l'insertion");
        exit(EXIT_FAILURE);
    }
    fwrite(record, sizeof(struct Record), 1, file);
    fclose(file);
}




int main() {
    const char *filename = "datafile.dat";

    // Exemple : Créer un fichier 
    createFile(filename);

    // Exemple : Insérer des enregistrements
    struct Record record1 = {1};
    struct Record record2 = {2};
    insertRecord(filename, &record1);
    insertRecord(filename, &record2);

    // Exemple : Rechercher un enregistrement
    searchRecord(filename, 1);

    // Exemple : Supprimer un enregistrement
    deleteRecord(filename, 1);

    return 0;
}