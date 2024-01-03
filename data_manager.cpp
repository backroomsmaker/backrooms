// File: data_manager.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class DataManager {
public:
    static void saveData(const std::string& data) {
        std::ofstream file("game_data.txt", std::ios::app);
        if (file.is_open()) {
            file << data << "\n";
            file.close();
        } else {
            std::cerr << "Impossibile aprire il file per la scrittura dei dati.\n";
        }
    }

    static int generateRandomAttack() {
        return rand() % 10 + 1; // Genera un valore casuale tra 1 e 10 per l'attacco del giocatore
    }

    static int generateRandomMonsterHealth() {
        return rand() % 20 + 10; // Genera un valore casuale tra 10 e 30 per la salute del mostro
    }
};
