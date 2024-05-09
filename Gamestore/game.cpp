#include <ctime>
#include <iostream>

#include "game.hpp"

// Constructor definition
Game::Game(const std::string& t, int rd, float op)
    : title(t), releaseDate(rd), originalPrice(op) {}

// Getter definitions
std::string Game::getTitle() const {
    return title;
}

int Game::getReleaseDate() const {
    return releaseDate;
}

float Game::getOriginalPrice() const {
    return originalPrice;
}

// Setter definitions
void Game::setTitle(const std::string& t) {
    title = t;
}

void Game::setReleaseDate(int rd) {
    releaseDate = rd;
}

void Game::setOriginalPrice(float op) {
    originalPrice = op;
}

#include <ctime> // Include for std::time_t, std::tm, std::localtime, std::mktime

// Function to calculate the current price with yearly depreciation
float Game::calculateCurrentPrice() const {
    // Get the current year
    std::time_t currentTime = std::time(nullptr);
    std::tm* currentLocalTime = std::localtime(&currentTime);
    int currentYear = currentLocalTime->tm_year + 1900;

    // Calculate the number of years since the release date
    int yearsSinceRelease = currentYear - releaseDate;

    // Calculate the current price with depreciation
    float currentPrice = originalPrice;
    for (int i = 0; i < yearsSinceRelease; ++i) {
        currentPrice *= 0.7; // Apply 30% depreciation each year
    }

    return currentPrice;
}