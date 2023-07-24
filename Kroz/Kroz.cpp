// Kroz.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <vector>
#include "Game.h"

void tokenize(const std::string& input, std::vector<std::string>& args) {
    char delimiter = ' ';
    size_t start = 0;
    size_t end = input.find(delimiter);

    while (end != std::string::npos)
    {
        args.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find(delimiter, start);
    }

    args.push_back(input.substr(start));
}

int main()
{
    std::cout << "Wellcom to Kroz!\n";
    std::string input;
    std::vector<std::string> args;
    
    Game game("testWorld.txt");

    input = "look";

    do {
        tokenize(input, args);
        
        
        if (args.size() > 0)
        {
            if (args.at(0) == "quit") {
                std::cout << "Are you sure? (Y/n)";
                std::string yes_no;
                std::cin >> yes_no;
                if (yes_no == "yes" or yes_no == "Y" or yes_no == "yes") {
                    std::cout << "Bye";
                    break;
                }
            }
            game.ParseCommand(args);
            //game.tick(args);
            args.clear();
            input = "";
            std::cout << "> ";
        } 
    } while (std::getline(std::cin, input));
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
