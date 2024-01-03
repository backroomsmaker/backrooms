// File: main.cpp

#include <iostream>
#include <limits>  // Aggiungi questo include per risolvere l'errore
#include "narration.cpp"
#include "event_generator.cpp"
#include "data_manager.cpp"

// Funzione per attendere l'input del giocatore prima di continuare
void waitForPlayerInput() {
    std::cout << "\nPremi un tasto per continuare...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora eventuali caratteri residui
    std::cin.get(); // Attendi l'input del giocatore
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Inizializza il generatore di numeri casuali

    Narration::intro();

    int playerHealth = 50; // Salute iniziale del giocatore
    int monsterHealth = 0; // Salute del mostro (inizializzata successivamente)

    for (int i = 0; i < 5; ++i) {
        int chosenRoom = Narration::chooseRoom();
        std::string roomDescription = Narration::generateRandomRoomDescription();
        Narration::showText(roomDescription);

        waitForPlayerInput(); // Attendi l'input del giocatore prima di procedere

        std::string event = EventGenerator::generateEvent(playerHealth);
        Narration::showText(event);
        DataManager::saveData(event);

        waitForPlayerInput(); // Attendi l'input del giocatore prima di procedere

        if (Narration::isExitRoom(chosenRoom)) {
            Narration::showText("Hai trovato la porta per la fine del livello!");
            break;
        }

        if (event.find("mostro") != std::string::npos) {
            monsterHealth = DataManager::generateRandomMonsterHealth();
            Narration::showText("Un combattimento inizia con il mostro!");
            
            while (playerHealth > 0 && monsterHealth > 0) {
                int playerAttack = DataManager::generateRandomAttack();
                monsterHealth -= playerAttack;
                Narration::showText("Hai attaccato il mostro causando " + std::to_string(playerAttack) + " danni.");

                if (monsterHealth <= 0) {
                    Narration::showText("Hai sconfitto il mostro!");
                    break;
                }

                int monsterAttack = DataManager::generateRandomAttack();
                playerHealth -= monsterAttack;
                Narration::showText("Il mostro ti ha attaccato causando " + std::to_string(monsterAttack) + " danni.");

                if (playerHealth <= 0) {
                    Narration::showText("Sei stato sconfitto dal mostro. Game Over.");
                    return 0;
                }

                waitForPlayerInput(); // Attendi l'input del giocatore prima di procedere al turno successivo
            }
        } else if (event.find("personaggio misterioso") != std::string::npos) {
            Narration::showText("Il personaggio misterioso ti sta osservando.");

            waitForPlayerInput(); // Attendi l'input del giocatore prima di procedere

            char choice;
            std::cout << "Vuoi attaccare il personaggio misterioso? (s/n): ";
            std::cin >> choice;

            if (choice == 's' || choice == 'S') {
                int mysteriousCharacterHealth = 30; // Salute del personaggio misterioso
                Narration::showText("Un combattimento inizia con il personaggio misterioso!");

                while (playerHealth > 0 && mysteriousCharacterHealth > 0) {
                    int playerAttack = DataManager::generateRandomAttack();
                    mysteriousCharacterHealth -= playerAttack;
                    Narration::showText("Hai attaccato il personaggio misterioso causando " + std::to_string(playerAttack) + " danni.");

                    if (mysteriousCharacterHealth <= 0) {
                        Narration::showText("Hai sconfitto il personaggio misterioso!");
                        break;
                    }

                    int mysteriousCharacterAttack = DataManager::generateRandomAttack() + 5; // Personaggio misterioso più forte
                    playerHealth -= mysteriousCharacterAttack;
                    Narration::showText("Il personaggio misterioso ti ha attaccato causando " + std::to_string(mysteriousCharacterAttack) + " danni.");

                    if (playerHealth <= 0) {
                        Narration::showText("Sei stato sconfitto dal personaggio misterioso. Game Over.");
                        return 0;
                    }

                    waitForPlayerInput(); // Attendi l'input del giocatore prima di procedere al turno successivo
                }
            } else {
                Narration::showText("Hai scelto di non attaccare il personaggio misterioso.");
            }
        }
    }

    return 0;
}
