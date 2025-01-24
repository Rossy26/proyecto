#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <string.h>

void guardarPersona(ConjuntoPersonas *con, char *archivo) {
    Persona *p;
    FILE *file;
    file = fopen(archivo, "w");
    
    if (file) {
        for (int i = 0; i < con->n; i++) {
            p = con->personas[i];
            char id_char[5];
            char edad_char[5];

            sprintf(id_char, "%d", p->id);
            sprintf(edad_char, "%d", p->edad);

            fwrite(id_char, sizeof(char), strlen(id_char), file);
            fwrite(",", sizeof(char), 1, file);

            fwrite(p->nombre, sizeof(char), strlen(p->nombre) , file);
            fwrite(",", sizeof(char), 1, file);

            fwrite(edad_char, sizeof(char), strlen(edad_char), file);
            fwrite(",", sizeof(char), 1, file);

            fwrite(p->nacionalidad, sizeof(char), strlen(p->nacionalidad), file);
            fwrite("\n", sizeof(char), 1, file);            
        }
        fclose(file);
    }
}

ConjuntoPersonas * leerPersonas(char * archivo) {
    ConjuntoPersonas * con = crearConPer(100);
    Persona * p;
    char linea[50]; 
    FILE *file;
    file = fopen(archivo, "r");
    fgets(linea, sizeof(linea), file);

    while (!feof(file)) {

        int id, edad;
        char nombre[20], nacionalidad[20];

        char *token = strtok(linea, ",");
        id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(nombre, token);
        
        token = strtok(NULL, ",");
        edad = atoi(token);
        
        token = strtok(NULL, ",");
        strcpy(nacionalidad, token);
        nacionalidad[strlen(nacionalidad) - 1] = '\0';
        p = crearPersona(id, edad, nombre, nacionalidad);

        addPersona(p, con);
        fgets(linea, sizeof(linea), file);
    }
    fclose(file);
    return con;
}


