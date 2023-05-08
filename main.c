#include <stdio.h>
#include <string.h>
//Nicolas Cajas

int login() {
    // Preestablecer usuarios y contraseñas
    char usuarios[3][20] = {"jose", "nico", "juan"};
    char contrasenas[3][20] = {"clave1", "clave2", "clave3"};
    
    char usuario[20], contrasena[20];
    int intentos = 0;
    int valido = 0;
    
    while (intentos < 3 && !valido) {
        printf("Ingrese su usuario: ");
        scanf("%s", usuario);
        printf("Ingrese su contrasena: ");
        scanf("%s", contrasena);
          //compra dos string (strcmp) son iguales devuelve 0

        for (int i = 0; i < 3; i++) {
            if (strcmp(usuario, usuarios[i]) == 0 && strcmp(contrasena, contrasenas[i]) == 0) {
                printf("Bienvenido, %s\n", usuario);
                valido = 1;
                break;
            }
        }
        
        if (!valido) {
            intentos++;
            printf("Usuario o contrasena incorrectos. Intento #%d\n", intentos);
        }
    }
    
    if (!valido) {
        printf("Imposible ingresar\n");
        return 0;
    }
    
    return 1;
}



//calcula el costo de una ruta según el tipo de ruta y la distancia en kilómetros.
float calcularPrecioRuta(int tipoRuta, float distancia) {
    float precioPorKm;
    switch (tipoRuta) {
        case 1: // Urbana
            precioPorKm = 0.10;
            break;
        case 2: // Interurbana
            precioPorKm = 0.15;
            break;
        case 3: // Internacional
            precioPorKm = 0.20;
            break;
        default:
            printf("Tipo de ruta no válido.\n");
        break;
    }
    return (precioPorKm * distancia);
}
// funcion en la cual se hace el descuento
float calcularDescuento(float costoTotal, float distancia) {
    float descuento;
    if (distancia >= 500.0) {
        descuento = 0.20;
    } else if (distancia >= 100.0) {
        descuento = 0.10;
    } else if (distancia >= 50.0) {
        descuento = 0.05;
    }
    return descuento * costoTotal;
}

void redSocial() {
    //simula la publicación de 5 mensajes en una red social
    int i, categoria, contadorNoticias = 0, contadorEventos = 0, contadorPreguntas = 0;
    char mensaje[150];
    for (i = 1; i <= 5; i++) {
        printf("Mensaje %d\n", i);
        printf("Ingrese el contenido del mensaje: ");
        scanf(" %[^\n]", mensaje);//cadena de formato utilizada en la función scanf para leer una línea completa de texto ingresada por el usuario, incluyendo espacios en blanco.
        printf("Ingrese la categoría del mensaje:\n");
        printf("1 = Noticias\n");//menu
        printf("2 = Eventos\n");
        printf("3 = Preguntas\n");
        scanf("%d", &categoria);
        switch (categoria) {
            case 1:
                printf("Mensaje de Noticias: %s\n", mensaje);
              contadorNoticias++;
                break;
            case 2:
                printf("Mensaje de Eventos: %s\n", mensaje);
              contadorEventos++;
                break;
            case 3:
                printf("Mensaje de Preguntas: %s\n", mensaje);
              contadorPreguntas++;
                break;
            default:
                printf("Categoría no válida.\n");
        }
    }
    printf("Cantidad de mensajes de Noticias: %d\n", contadorNoticias);
    printf("Cantidad de mensajes de Eventos: %d\n", contadorEventos);
    printf("Cantidad de mensajes de Preguntas: %d\n", contadorPreguntas);
}

float operacionTransporte() {
    //función principal que se encarga de gestionar la operación de transporte para un total de 5 clientes.
    int i, tipoRuta;
    float distancia, costoSinDescuento, descuento, costoTotal;
    for (i = 1; i <= 5; i++) {
        printf("Cliente %d\n", i);
        printf("Ingrese el tipo de ruta:\n ");
        printf("1= urbana\n");
        printf("2= interurbana\n ");
        printf("3= internacional\n");
        scanf("%d", &tipoRuta);
        printf("Ingrese la distancia en km: ");
        scanf("%f", &distancia);
        costoSinDescuento=calcularPrecioRuta(tipoRuta,distancia);
        descuento=calcularDescuento(costoSinDescuento, distancia);
        //calcula el costo de la ruta sin descuento y el monto del descuento.
      float costoFinal = costoSinDescuento - descuento;
    printf("Subtotal: %.2f\n", costoSinDescuento);//$%.2f se utiliza para imprimir valores de punto flotante (floats) con dos decimales. 
    printf("Descuento: %.2f\n", descuento);
    printf("Precio total: %.2f\n", costoFinal);
    return costoFinal;
    }
    
}


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

// tenga piedad porfavor ;)