#include <ctime>
#include <iostream>
#include "person.hpp"
#include "game.hpp"

int main()
{
    std::time_t result = std::time(NULL);
    std::cout << std::asctime(std::localtime(&result));
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int releaseDate1 = tm_local->tm_year + 1899; // 1 jaar geleden
    int releaseDate2 = tm_local->tm_year + 1898; // 2 jaar geleden
    
    Game g1("Just Cause 3", releaseDate1 , 49.98);
    Game g2("Need for Speed: Rivals", releaseDate2 , 45.99);
    Game g3("Need for Speed: Rivals", releaseDate2 , 45.99);
    
    Person p1(200, "Eric");
    Person p2(55, "Hans");
    Person p3(185, "Arno");
    
    // Print the transactions
    std::cout << "Transactions:" << std::endl;
    std::cout << "-------------------------" << std::endl;
    p1.buyGame(&g1);
    p1.buyGame(&g2);
    p1.buyGame(&g3);
    p2.buyGame(&g2);
    p2.buyGame(&g1);
    p3.buyGame(&g3);
    
    // Print persons p1, p2, and p3
    std::cout << "\nPersons:" << std::endl;
    std::cout << "-------------------------" << std::endl;
    
    //person 1
    std::cout << "Person p1: " << p1.getName() << ", Budget: " << p1.getBudget() << std::endl;
    for (const auto& game : p1.getGames()) {
        std::cout << game->getTitle() << ", released " << game->getReleaseDate() << "; "
                  << "original price: " << game->getOriginalPrice() << " now: " << game->calculateCurrentPrice() << std::endl;
    }
    std::cout << std::endl;

    //person 2
    std::cout << "Person p2: " << p2.getName() << "'s budget is " << p2.getBudget() << " and owns:" << std::endl;
    for (const auto& game : p2.getGames()) {
        std::cout << game->getTitle() << ", released " << game->getReleaseDate() << "; "
                  << "original price: " << game->getOriginalPrice() << " now: " << game->calculateCurrentPrice() << std::endl;
    }
    std::cout << std::endl;

    //person 3
    std::cout << "Person p3: " << p3.getName() << "'s budget is " << p3.getBudget() << " and owns:" << std::endl;
    for (const auto& game : p3.getGames()) {
        std::cout << game->getTitle() << ", released " << game->getReleaseDate() << "; "
                  << "original price: " << game->getOriginalPrice() << " now: " << game->calculateCurrentPrice() << std::endl;
    }
    std::cout << std::endl;
    
    // Print the transactions
    p1.sellGame(&g1, &p3);
    p2.sellGame(&g2, &p3);
    p2.sellGame(&g1, &p1);
    
    // Print persons p1, p2, and p3 after transactions
    std::cout << "Persons after transactions:" << std::endl;
    std::cout << "-------------------------" << std::endl;
    
    //person 1
    std::cout << "Person p1: " << p1.getName() << "'s budget is " << p1.getBudget() << " and owns:" << std::endl;
    for (const auto& game : p1.getGames()) {
        std::cout << game->getTitle() << ", released " << game->getReleaseDate() << "; "
                  << "original price: " << game->getOriginalPrice() << " now: " << game->calculateCurrentPrice() << std::endl;
    }
    std::cout << std::endl;

    //person 2
    std::cout << "Person p2: " << p2.getName() << "'s budget is " << p2.getBudget() << " and owns:" << std::endl;
    for (const auto& game : p2.getGames()) {
        std::cout << game->getTitle() << ", released " << game->getReleaseDate() << "; "
                  << "original price: " << game->getOriginalPrice() << " now: " << game->calculateCurrentPrice() << std::endl;
    }
    std::cout << std::endl;

    //person 3
    std::cout << "Person p3: " << p3.getName() << "'s budget is " << p3.getBudget() << " and owns:" << std::endl;
    for (const auto& game : p3.getGames()) {
        std::cout << game->getTitle() << ", released " << game->getReleaseDate() << "; "
                  << "original price: " << game->getOriginalPrice() << " now: " << game->calculateCurrentPrice() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
