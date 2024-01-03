// File: event_generator.cpp

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

class EventGenerator {
public:
    static std::string generateEvent(int& playerHealth) {
        std::vector<std::string> events = {
            "Hai trovato un kit medico! La tua salute aumenta di 20.",
            "Incontri un personaggio misterioso.",
            generateMonsterEvent(),
            // Aggiungi altri eventi
        };

        int randomIndex = rand() % events.size();
        std::string event = events[randomIndex];

        // Se l'evento è il kit medico, aumenta la salute del giocatore
        if (event.find("kit medico") != std::string::npos) {
            playerHealth += 20;
        }

        return event;
    }

private:
    static std::string generateMonsterEvent() {
        std::vector<std::string> monsters = {
            "Un ragno gigante compare!",
            "Un lupo mannaro si avvicina minaccioso!",
            "Trovi un gruppo di zombie!",
            // Aggiungi altri tipi di mostri
        };

        int randomMonsterIndex = rand() % monsters.size();
        return "Nella stanza trovi: " + monsters[randomMonsterIndex];
    }
};
