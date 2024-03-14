// Levi Josué Candeias de Figueiredo
// Juego del tres en raya (Tick-tack-toe)
#include <stdio.h>

//Prototipos
int seleccionarJugador(void);
char seleccionarReglas(void);
void reglas(void);
char seleccionarCelda(void);
void buscarCelda(char, char tablero[3][3]);
int verificarCelda(char, char tablero[3][3]);
void graciasPorJugar(void);
void modificarRegistro(FILE *historialDeJuegos, int);


int jugadorActual = 1; // Variable global para seguir al jugador actual
int main()
{
    printf("\n|Bienvenido al juego del tres en raya|\n");
    FILE *historialDeJuegos;
    historialDeJuegos = fopen("historialDeJuegos.txt", "a");

    char tablero[3][3] ={
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
    };

    printf("¿Quieres leer las reglas? (s/n): ");
    char respuestaReglas = seleccionarReglas(); //Selecciona si quiere leer las reglas
    if (respuestaReglas == 's')
        reglas(); //Muestra las reglas

    while (1)
    {

        char celdaSeleccionada = seleccionarCelda(); //Selecciona la celda

        buscarCelda(celdaSeleccionada, tablero); //Encuentra la celda

        int vistaGanador = verificarCelda(celdaSeleccionada, tablero); //Verifica la celda

        printf("\n|Tablero|\n");
        for (int i = 0; i < 3; i++)
        {
            printf("|");
            for (int j = 0; j < 3; j++)
            {
                printf("%c|", tablero[i][j]);
            }
            printf("\n");
        }
        if (vistaGanador == 1)
        {
            printf("El jugador %d gana\n", jugadorActual);
            fprintf(historialDeJuegos, "El jugador %d gana\n", jugadorActual);
            fprintf(historialDeJuegos, "Total de partidas jugadas: %d\n", 1);
            while(feof(historialDeJuegos))
            {
                modificarRegistro(historialDeJuegos, 1);
            }
            fclose(historialDeJuegos);
            break;
        }else if (vistaGanador == 2)
        {
            printf("Empate\n");
            break;
        }

        // Cambiar el jugador actual
        if (jugadorActual == 1)
        {
            jugadorActual = 2;
        } else {
            jugadorActual = 1;
        }
    }
    graciasPorJugar();
    return 0;
}

int seleccionarJugador(void)
{
    int jugador;
    printf("Selecciona el jugador: ");
    scanf("%d", &jugador);
    while(jugador < 1 || jugador > 2)
    {
        printf("Jugador inválido, por favor selecciona de nuevo: ");
        scanf("%d", &jugador);
    }
    return jugador; //Devuelve el jugador
}

char seleccionarReglas(void)
{
    char reglas;
    scanf(" %c", &reglas);
    while(reglas != 's' && reglas != 'n')
    {
        printf("Entrada inválida, por favor selecciona de nuevo: ");
        scanf(" %c", &reglas);
    }
    return reglas;
}

void reglas(void)
{
    printf("\n|Reglas|\n");
    printf("1. El juego se juega en una cuadrícula de 3 cuadrados por 3 cuadrados.\n");
    printf("2. Tú eres X, tu amigo es O. Los jugadores se turnan para poner sus marcas en cuadrados vacíos.\n");
    printf("3. El primer jugador en conseguir 3 de sus marcas en una fila (arriba, abajo, a través, o en diagonal) es el ganador.\n");
    printf("4. Cuando los 9 cuadrados están llenos, el juego termina. Si ningún jugador tiene 3 marcas en una fila, el juego termina en un empate.\n");
    printf("5. A JUGAR\n");
}
char seleccionarCelda(void)
{
    char celda;
    printf("Selecciona la celda: ");
    scanf(" %c", &celda);
    fflush(stdin);
    while(celda < '1' || celda > '9') {
        printf("Celda inválida, por favor selecciona de nuevo: ");
        scanf(" %c", &celda);
        fflush(stdin);
    }
    return celda;
}

void buscarCelda(char celda, char tablero[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tablero[i][j] == celda)
            {
                printf("Celda encontrada en la posición %d, %d\n", i, j);
                if (jugadorActual == 1)
                {
                    tablero[i][j] = 'X';
                } else {
                    tablero[i][j] = 'O';
                }
            }
        }
    }
}

int verificarCelda(char celda, char tablero[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i <= 1 && tablero[i][j] == tablero[i+1][j] && tablero[i+1][j] == tablero[i+2][j]) {
                printf("Ganador\n");
                return 1;
            }
            if (j <= 1 && tablero[i][j] == tablero[i][j+1] && tablero[i][j+1] == tablero[i][j+2]) {
                printf("Ganador\n");
                return 1;
            }
        }
    }
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
    {
        printf("Ganador\n");
        return 1;
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
    {
        printf("Ganador\n");
        return 1;
    }

    if (tablero[0][0] != '1' && tablero[0][1] != '2' && tablero[0][2] != '3' && tablero[1][0] != '4' && tablero[1][1] != '5' && tablero[1][2] != '6' && tablero[2][0] != '7' && tablero[2][1] != '8' && tablero[2][2] != '9')
    {
        printf("Empate\n");
        return 2;
    }
    return 0;
}

void graciasPorJugar(void)
{
    FILE *gracias;
    gracias = fopen("gracias.txt", "w");
    if (gracias == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }
    fprintf(gracias, "Gracias por jugar este juego del 3 en raya\n");
    fprintf(gracias, "Juego realizado por: Levi Josué Candeias de Figueiredo\n");
    fprintf(gracias, "Fecha: 10/10/2021\n");
    fprintf(gracias, "Curso: 1 DAW 23/24\n");
    fclose(gracias);
}

void modificarRegistro(FILE *historialDeJuegos, int partidasJugadas)
{
    int partidas;
    rewind(historialDeJuegos); // Go to the start of the file
    fscanf(historialDeJuegos, "Total de partidas jugadas: %d\n", &partidas);
    partidas += partidasJugadas;
    freopen(NULL, "w", historialDeJuegos); // Clear the file
    fprintf(historialDeJuegos, "Total de partidas jugadas: %d\n", partidas);
}