Este programa es una implementación del juego clásico "Tres en raya" (también conocido como "Tic Tac Toe") en el lenguaje de programación C. 
El juego se juega en una cuadrícula de 3x3, donde los jugadores se turnan para colocar sus marcas (X u O) en las celdas vacías.
El primer jugador en conseguir 3 de sus marcas en una fila (ya sea horizontal, vertical o diagonal) es el ganador.
Si todos los cuadrados están llenos y ningún jugador ha conseguido 3 marcas en una fila, el juego termina en un empate.

El programa comienza mostrando un mensaje de bienvenida y preguntando al usuario si desea leer las reglas del juego. 
Después de esto, el juego comienza y los jugadores se turnan para seleccionar una celda en la que colocar su marca.
Después de cada turno, el programa verifica si alguno de los jugadores ha ganado o si el juego ha terminado en un empate.

Además, el programa mantiene un registro del número total de partidas jugadas en un archivo llamado historialDeJuegos.txt.
Cada vez que se juega una partida, el programa incrementa el número total de partidas jugadas y actualiza el archivo.

Finalmente, cuando el juego termina, el programa muestra un mensaje de agradecimiento y guarda este mensaje en un archivo llamado gracias.txt.

Autor: Levi Josué Candeias de Figueiredo
