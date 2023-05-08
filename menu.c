#include <stdio.h>
#include <string.h>
#include "operaciones.h"
//Nicolas Cajas
int main() {
    int opcion;
    while (1) {
        printf("********************************\n");
        printf("***Seleccione una opción********:\n");
        printf("**1. Operación de transporte****\n");
        printf("*2. Interactuar en la red social*\n");
        printf("*3. Salir*************************\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        printf("\n");
        switch (opcion) {   
            case 1:
                operacionTransporte();
                break;
            case 2:
                redSocial();
                break;
            case 3:
                return 0;
            default:
                printf("Opción no válida.\n\n");
        }
    }
}
