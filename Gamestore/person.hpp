#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <vector>

// Forward declaration of Game class
class Game;

class Person {
private:
    std::string name;
    float budget;
    std::vector<Game*> games;

public:
    // Constructor
    Person(float b, const std::string& n);

    // Getters
    std::string getName() const;
    float getBudget() const;
    std::vector<Game*> getGames() const;

    // Setters
    void setName(const std::string& n);
    void setBudget(float b);
    void setGames(const std::vector<Game*>& newGames);

    // Buy/sell game methods
    void buyGame(Game* game);
    void sellGame(Game* game, Person* buyer);

    // Add/remove game methods
    void addGame(Game* game);
    void removeGame(Game* game);
};

#endif // PERSON_HPP