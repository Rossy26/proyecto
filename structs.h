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

int existePer(Persona *p, ConjuntoPersonas *cp) {
    for (int i = 0; i < cp->n; i++) {
        if(cp->personas[i]->id == p->id) {
            return 1;
        }
    }
    return 0;
}

Persona *buscarPer(int id, ConjuntoPersonas *cp){
    for (int i = 0; i < cp->n; i++)
    {
        if (cp->personas[i]->id == id) {
            return cp->personas[i];
        }
        
    }
    return NULL;
}

void imprimirPer(Persona *p) {
    printf("%d %s %d %s\n", 
    p->id, 
    p->nombre,  
    p->edad,  
    p->nacionalidad); 
}

void mostrar(ConjuntoPersonas *cp) {
    for (int i = 0; i < cp->n; i++) {
        imprimirPer(cp->personas[i]);
    }
}

int borrarPer(int id, ConjuntoPersonas *cp) {
    for (int i = 0; i < cp->n; i++) {
        if(cp->personas[i]->id == id) {
            for (int j = 0; j < cp->n-1; j++)
            {
                cp->personas[j] = cp->personas[j+1];
            }
            cp->n--;
            return 1;
            
        }
    }
    return 0;
}

void ordenarPorEdad(ConjuntoPersonas *cp) {
    Persona *temp;
    for (int i = 0; i < cp->n; i++)
    {
        for (int j = 0; j < cp->n-1; j++)
        {
            if(cp->personas[j]->edad > cp->personas[j+1]->edad) {
                temp = cp->personas[j];
                cp->personas[j] = cp->personas[j+1];
                cp->personas[j+1] = temp; 
            }
        }
        
    }
    
}

void ordenarAlfa(ConjuntoPersonas *cp) {
    Persona *temp;
    for (int i = 0; i < cp->n; i++)
    {
        for (int j = 0; j < cp->n-1; j++)
        {
            if(strcmp(cp->personas[j]->nombre, cp->personas[j+1]->nombre) > 0) {
                temp = cp->personas[j];
                cp->personas[j] = cp->personas[j+1];
                cp->personas[j+1] = temp;
            }
        }
        
    } 
}

void filtrarNac(char *nac, ConjuntoPersonas *cp) {
    int cont = 0;
    for (int i = 0; i < cp->n; i++)
    {
        if(strcmp(cp->personas[i]->nacionalidad, nac) == 0) {
            imprimirPer(cp->personas[i]);
            cont++;
        }
    }
    if(cont == 0) {
        printf("No hay personas con nacionalidad %s\n", nac);
    }
}