#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona {
    int id;
    int edad;
    char nombre[20];
    char nacionalidad[20];
} Persona;

Persona *crearPersona(int id, int edad,  char *nom, char *nac) {
    Persona *p = (Persona*) malloc(sizeof(Persona));
    p->id = id;
    p->edad = edad;
    strcpy(p->nombre, nom);
    strcpy(p->nacionalidad, nac);
    return p;
}

typedef struct conjuntoPersonas {
    int n;
    Persona **personas;
} ConjuntoPersonas;

ConjuntoPersonas *crearConPer(int tam) {
    ConjuntoPersonas *cp = (ConjuntoPersonas*) malloc(sizeof(ConjuntoPersonas));
    cp->n = 0;
    cp->personas = (Persona**) malloc(sizeof(Persona) * tam);
    return cp;
}

void addPersona(Persona *p, ConjuntoPersonas *cp) {
    cp->personas[cp->n++] = p;
}

int buscarPer(Persona *p, ConjuntoPersonas *cp) {
    for (int i = 0; i < cp->n; i++) {
        if(cp->personas[i]->id == p->id) {
            return 1;
        }
    }
    return 0;
}

void mostrar(ConjuntoPersonas *cp) {
    for (int i = 0; i < cp->n; i++) {
        printf("%d %s %d %s\n", 
        cp->personas[i]->id, 
        cp->personas[i]->nombre, 
        cp->personas[i]->edad, 
        cp->personas[i]->nacionalidad);
    }
}
