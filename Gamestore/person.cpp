#include "person.hpp"
#include "game.hpp" // Include the definition of Game class
#include <iostream> // Include for std::cout

// Constructor definition
Person::Person(float b, const std::string& n) : budget(b), name(n) {}

// Getter definitions
std::string Person::getName() const {
    return name;
}

float Person::getBudget() const {
    return budget;
}

std::vector<Game*> Person::getGames() const {
    return games;
}

// Setter definitions
void Person::setName(const std::string& n) {
    name = n;
}

void Person::setBudget(float b) {
    budget = b;
}

void Person::setGames(const std::vector<Game*>& newGames) {
    games = newGames;
}

// Buy game method
void Person::buyGame(Game* game) {
    float currentPrice = game->calculateCurrentPrice(); // Get current price
    if (budget >= currentPrice) {
        // Check if the person doesn't already own the game
        bool alreadyOwnsGame = false;
        for (Game* ownedGame : games) {
            if (ownedGame == game) {
                alreadyOwnsGame = true;
                break;
            }
        }

        if (!alreadyOwnsGame) {
            // Deduct the game price from the budget
            budget -= currentPrice;
            // Add the game to the person's collection
            games.push_back(game);
            std::cout << "Transaction successful. Bought " << game->getTitle() << "." << std::endl;
        } else {
            std::cout << "You already own this game." << std::endl;
        }
    } else {
        std::cout << "Not enough budget to buy the game." << std::endl;
    }
}

// Sell game method
void Person::sellGame(Game* game, Person* buyer) {
    // Check if the seller owns the game
    bool hasGame = false;
    for (Game* ownedGame : games) {
        if (ownedGame == game) {
            hasGame = true;
            break;
        }
    }

    if (hasGame) {
        float currentPrice = game->calculateCurrentPrice(); // Get current price
        // Check if the buyer has enough budget
        if (buyer->getBudget() >= currentPrice) {
            // Check if the buyer doesn't already own the game
            bool alreadyOwnsGame = false;
            for (Game* ownedGame : buyer->getGames()) {
                if (ownedGame == game) {
                    alreadyOwnsGame = true;
                    break;
                }
            }

            if (!alreadyOwnsGame) {
                // Remove the game from the seller's collection
                removeGame(game);
                // Add the game to the buyer's collection
                buyer->addGame(game);
                // Transfer money from the buyer to the seller
                setBudget(getBudget() + currentPrice);
                buyer->setBudget(buyer->getBudget() - currentPrice);
                std::cout << "Transaction successful. Sold " << game->getTitle() << " to " << buyer->getName() << "." << std::endl;
            } else {
                std::cout << "Buyer already owns this game." << std::endl;
            }
        } else {
            std::cout << "Buyer does not have enough budget to buy the game." << std::endl;
        }
    } else {
        std::cout << "You do not own this game." << std::endl;
    }
}


// Add game method
void Person::addGame(Game* game) {
    games.push_back(game);
}

// Remove game method
void Person::removeGame(Game* game) {
    bool gameRemoved = false;
    for (auto it = games.begin(); it != games.end(); ++it) {
        if (*it == game) {
            games.erase(it);
            gameRemoved = true;
            break;
        }
    }
}
