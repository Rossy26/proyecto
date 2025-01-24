#include "lectura_archivos.h"
/*
ya añadir persona
ya mostrar persona
buscar perosna
borrar
ordenar por edad
ordenar por nombre
filtrar por nacionalidad
ya salir
*/
void menu() {
    printf("Este es el menu principal\n");
    printf("1 - añadir persona\n");
    printf("2 - mostrar personas\n");
    printf("3 - buscar persona\n");
    printf("4 - borrar\n");
    printf("5 - ordenar por edad\n");
    printf("6 - ordenar por nombre\n");
    printf("7 - filtrar por nacionalidad\n");
    printf("0 - salir\n");
    printf("Ingrese su opción: ");
}

int main() {
    char *nombre_archivo = "archivo.txt";
    ConjuntoPersonas *con = leerPersonas(nombre_archivo);
    int op = 0;
    do {
        menu();
        scanf("%d", &op);
        switch (op) {
        case 1: {
            int id, edad;
            char nombre[20], nacionalidad[20];
            printf("Ingrese el id: ");
            scanf("%d", &id);
            printf("Ingrese el nombre: ");
            scanf("%s", nombre);
            printf("Ingrese la edad: ");
            scanf("%d", &edad);
            printf("Ingrese la nacionalidad: ");
            scanf("%s", nacionalidad);
            Persona *p = crearPersona(id, edad, nombre, nacionalidad);
            addPersona(p, con);
            break;
        }
        case 2:
            mostrar(con);
            break;
        case 3: {
            int id;
            printf("Ingrese el id de la persona: ");
            scanf("%d", &id);
            Persona *p = buscarPer(id, con);
            if(p != NULL) {
                imprimirPer(p);
            }else {
                printf("No se encontró la persona\n");
            }
            break;
        }
        case 4: {
            int id;
            printf("Ingrese el id de la persona a eliminar: ");
            scanf("%d", &id);
            int r = borrarPer(id, con);
            if(r == 0) {
                printf("No habia una persona con este id\n");
            }else{
                printf("Persona eliminada exitósamente\n");
            }
            break;
        }
        case 5:
            ordenarPorEdad(con);
            break;
        case 6:
            ordenarAlfa(con);
            break;
        case 7:{
            char nacionalidad[20];
            printf("Por cual nacionalidad desea filtrar: ");
            scanf("%s", nacionalidad);
            filtrarNac(nacionalidad, con);
            break;
        } 
        case 0:
            guardarPersona(con, nombre_archivo);
            break;
        
        default:
        printf("La opción ingresada es invalida\n");
            break;
        }

    } while(op != 0);

    printf("***Gracias por usar el programa***\n");
    
    return 0;    
}