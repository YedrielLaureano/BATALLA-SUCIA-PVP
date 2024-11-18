/*
        Universidad Interamericana de Puerto Rico, Recinto de Bayamon

                   Proyecto Intregador 2025-10
                          BATALLA SUCIA PVP
        Yedriel Laureano Marrero
        Francisco Dume Ortiz
        Carlos Rivera Santiago

        PROGRAMMING LOGIC
        Prof. Hacniel Cardona
*/

#include <iostream>
#include <string>
#include <cstdlib>//Para numeros aleatorios
#include <cmath>//Para redondear 
#include <list>//Para crear listas

using namespace std;

/*******************************************************************************/
 // Carlos Rivera Santiago

//Constantes de la vida de los jugadores
const int vidaInicialJugador = 100;
int vidaJugador1 = vidaInicialJugador;
int vidaJugador2 = vidaInicialJugador;


//Nombre de los jugadores
string Jugador1, Jugador2;

/*******************************************************************************/

/*******************************************************************************/
 // Francisco Dume Ortiz

//Arrays de inventario
string inventarioCura[3] = { "Pocion Especial", "Botiquin", "Escudo" };
string inventarioArmas[4] = { "Cuchillo", "Espada", "Arco y Flecha", "Lanza" };

//Arrays de los valores
int valorInventarioCura[3] = { 9, 9, 4 };
int valorInventarioArmas[4] = { 3, 7 , rand() % 7 + 1, 5 };

/*******************************************************************************/

/*******************************************************************************/
 // Yedriel Laureano Marrero



//Variables para almacenar las selecciones de los jugadores
string InventarioCura1, InventarioArma1P1, InventarioArma2P1;
string InventarioCuraP2, InventarioArma1P2, InventarioArma2P2;
int valorInventarioCura1, valorInventarioArma1P1, valorInventarioArma2P1;
int valorInventarioCura2, valorInventarioArma1P2, valorInventarioArma2P2;



//Lista
list <string> Notas{ "~ A medida que pasan las rondas, las curas se vuelven innecesarias.",
"~ A medida que pasan las rondas, las armas ejercen mas dano.",
"~ El jugador que pierda debe hacer un reto impuesto por el jugador que gane la batalla.","~ Que gane el mas astuto." };

/*******************************************************************************/

/*******************************************************************************/
// Yedriel Laureano Marrero 
// Francisco Dume Ortiz 

//Funcion para mostrar el inventario y permitir la eleccion
void elegirInventario() {
    int eleccion;

    //Eleccion de cura del Jugador 1
    cout << Jugador1 << ", escoja una cura." << "\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << inventarioCura[i] << endl;
    }
    cout << "Eleccion: ";
    cin >> eleccion;
    InventarioCura1 = inventarioCura[eleccion - 1];
    valorInventarioCura1 = valorInventarioCura[eleccion - 1];

    //Eleccion de los ataques del Jugador 1
    cout << Jugador1 << ", escoja dos armas para atacar." << "\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << inventarioArmas[i] << endl;
    }
    cout << "Eleccion 1: ";
    cin >> eleccion;
    InventarioArma1P1 = inventarioArmas[eleccion - 1];
    valorInventarioArma1P1 = valorInventarioArmas[eleccion - 1];
    cout << "Eleccion 2: ";
    cin >> eleccion;
    InventarioArma2P1 = inventarioArmas[eleccion - 1];
    valorInventarioArma2P1 = valorInventarioArmas[eleccion - 1];
    cout << "-----------------------------------------\n";

    //Eleccion de cura del Jugador 2
    cout << Jugador2 << ", escoja una cura." << "\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << inventarioCura[i] << endl;
    }
    cout << "Eleccion: ";
    cin >> eleccion;
    InventarioCuraP2 = inventarioCura[eleccion - 1];
    valorInventarioCura2 = valorInventarioCura[eleccion - 1];

    //Eleccion de los ataques del Jugador 2
    cout << Jugador2 << ", escoja dos armas para atacar." << "\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << inventarioArmas[i] << endl;
    }
    cout << "Eleccion 1: ";
    cin >> eleccion;
    InventarioArma1P2 = inventarioArmas[eleccion - 1];
    valorInventarioArma1P2 = valorInventarioArmas[eleccion - 1];
    cout << "Eleccion 2: ";
    cin >> eleccion;
    InventarioArma2P2 = inventarioArmas[eleccion - 1];
    valorInventarioArma2P2 = valorInventarioArmas[eleccion - 1];
}

/*******************************************************************************/

/*******************************************************************************/
 // Yedriel Laureano Marrero 

int main() {
    int ronda = 1;
    cout << " _  o  _             _      o  _   _   _    _" << endl;
    cout << "| ) | |_ |\\ | \\   / |_ |\\ | | | \\ | | (    /_\\" << endl;
    cout << "|_) | |_ | \\|  \\ /  |_ | \\| | |_/ |_| _)  /   \\" << endl;

    cout << " _    _  ___  _           _      _       __ o   _" << endl;
    cout << "| )  /_\\  |  /_\\  |  |   /_\\    (  |  | |   |  /_\\" << endl;
    cout << "|_) /   \\ | /   \\ |_ |_ /   \\   _) |__| |__ | /   \\" << endl;

    cout << " _        _ " << endl;
    cout << "|_| \\  / |_|" << endl;
    cout << "|    \\/  |  " << endl;


    cout << "Presiona 'ENTER' para continuar.\n";
    getchar ();

    //Mostrar la lista creada
    for (string Nota : Notas) {
        cout << Nota << "\n";
    }
    cout << "\nPresiona 'ENTER' para continuar.\n";
    getchar ();

    /*******************************************************************************/

    /*******************************************************************************/
     // Carlos Rivera Santiago

    cout << "Entra el nombre del jugador 1: ";
    getline(cin, Jugador1);
    cout << "-------------------------------------------------------\n";
    cout << "Entra el nombre del jugador 2: ";
    getline(cin, Jugador2);
    cout << "-------------------------------------------------------\n";

    elegirInventario();

    //Loop del juego para el Jugador 1
    while (vidaJugador1 > 0 && vidaJugador2 > 0) {
        cout << "\n";
        cout << "     Ronda " << ronda << "\n";
        cout << "     Turno de " << Jugador1 << "\n";
        cout << "-----------------------------------------\n";
        cout << "     Vida de " << Jugador1 << ": " << vidaJugador1 << "\n";
        cout << "     Vida de " << Jugador2 << ": " << vidaJugador2 << "\n";
        cout << "------------------------------------------\n";

        int inventario;
        cout << "\nEntre 1 para atacar.\n";
        cout << "Entre 2 para curarte.\n";
        cin >> inventario;

        switch (inventario) {
        case 1:
            cout << "------------------------------------------\n";
            cout << "Entre 1 para usar " << InventarioArma1P1 << " o entre 2 para usar " << InventarioArma2P1 << ": ";
            cin >> inventario;
            if (inventario == 1) {
                cout << "------------------------------------------\n";
                cout << Jugador1 << " usa " << InventarioArma1P1 << " para atacar a " << Jugador2 << "\n";
                vidaJugador2 -= round(valorInventarioArma1P1 * 1.6) + ronda;
            }
            else if (inventario == 2) {
                cout << "------------------------------------------\n";
                cout << Jugador1 << " usa " << InventarioArma2P1 << " para atacar a " << Jugador2 << "\n";
                vidaJugador2 -= round(valorInventarioArma2P1 * 1.6) + ronda;
            }
            else {
                cout << "------------------------------------------\n";
                cout << "No selecionaste nada, pierdes tu turno.\n";
            }
            break;
        case 2:
            cout << "------------------------------------------\n";
            cout << Jugador1 << " usa " << InventarioCura1 << " para curarse.\n";
            vidaJugador1 += round(valorInventarioCura1 / ronda) + 1;
            break;
        default:
            cout << "------------------------------------------\n";
            cout << "No selecionaste nada, pierdes tu turno.\n";

        }

        //Loop del juego para el Jugador 2 
        cout << "\n";
        cout << "     Turno de " << Jugador2 << "\n";
        cout << "------------------------------------------\n";
        cout << "     Vida de " << Jugador1 << ": " << vidaJugador1 << "\n";
        cout << "     Vida de " << Jugador2 << ": " << vidaJugador2 << "\n";
        cout << "------------------------------------------\n";

        cout << "\nEntre 1 para atacar.\n";
        cout << "Entre 2 para curarte.\n";
        cin >> inventario;

        switch (inventario) {
        case 1:
            cout << "Entre 1 para usar " << InventarioArma1P2 << " o entre 2 para usar " << InventarioArma2P2 << ": ";
            cin >> inventario;
            if (inventario == 1) {
                cout << "------------------------------------------\n";
                cout << Jugador2 << " usa " << InventarioArma1P2 << " para atacar a " << Jugador1 << "\n";
                vidaJugador1 -= round(valorInventarioArma1P2 * 1.6) + ronda;
            }
            else if (inventario == 2) {
                cout << "------------------------------------------\n";
                cout << Jugador2 << " usa " << InventarioArma2P2 << " para atacar a " << Jugador1 << "\n";
                vidaJugador1 -= round(valorInventarioArma2P2 * 1.6) + ronda;
            }
            else {
                cout << "------------------------------------------\n";
                cout << "No selecionaste nada, pierdes tu turno.\n";
            }
            break;
        case 2:
            cout << "------------------------------------------\n";
            cout << Jugador2 << " usa " << InventarioCuraP2 << " para curarse.\n";
            vidaJugador2 += round(valorInventarioCura2 / ronda) + 1;
            break;
        default:
            cout << "------------------------------------------\n";
            cout << "No selecionaste nada, pierdes tu turno.\n";
        }
        cout << "\n************************************************************************************\n";
        ronda++;
    }

    //Ganador
    if (vidaJugador1 <= 0) {
        cout << "\n";
        cout << " " << Jugador2 << " gano el juego. Debido a que esto es una BATALLA SUCIA. (gana el primero en llegar a cero o meno)\n";
    }
    else if (vidaJugador2 <= 0) {
        cout << "\n";
        cout << " " << Jugador1 << " gano el juego. Debido a que esto es una BATALLA SUCIA. (gana el primero en llegar a cero o meno)\n";
    }

    /*******************************************************************************/

    return 0;
}
