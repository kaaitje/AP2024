#ifndef GAME_HPP
#define GAME_HPP

#include <string>

class Game {
private:
    std::string title;
    int releaseDate;
    float originalPrice;

public:
    // Constructor
    Game(const std::string& t, int rd, float op);

    // Getters
    std::string getTitle() const;
    int getReleaseDate() const;
    float getOriginalPrice() const;

    // Setters
    void setTitle(const std::string& t);
    void setReleaseDate(int rd);
    void setOriginalPrice(float op);

    // Function to calculate the current price
    float calculateCurrentPrice() const;
};

#endif // GAME_HPP