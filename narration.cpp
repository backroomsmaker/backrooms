// File: narration.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Narration {
private:
    static const int MAX_ROOMS = 50;
    static const int EXIT_ROOM_INDEX = 48;

public:
    static void intro() {
        std::cout << "Benvenuto nel nostro gioco testuale!\n";
        // Puoi aggiungere ulteriori dettagli introduttivi qui
    }

    static void showText(const std::string& text) {
        std::cout << text << "\n";
    }

    static int chooseRoom() {
        int choice;
        std::cout << "Scegli una stanza:\n";
        for (int i = 1; i <= MAX_ROOMS; ++i) {
            std::cout << i << ". Stanza " << i << "\n";
        }
        std::cin >> choice;

        return choice;
    }

    static std::string generateRandomRoomDescription() {
        std::string roomDescriptions[MAX_ROOMS] = {
            "Sei in una stanza buia con un odore strano nell'aria.",
            "La stanza è illuminata da una luce tenue, e senti un suono sottile.",
            "Ci sono vecchi mobili rotti sparsi per la stanza.",
            // Aggiungi altre descrizioni di stanze
        };

        int randomIndex = rand() % MAX_ROOMS;
        return roomDescriptions[randomIndex];
    }

    static bool isExitRoom(int roomIndex) {
        return roomIndex == EXIT_ROOM_INDEX;
    }
};
