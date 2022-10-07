#include "key.h"

Key::Key(){
    rect = new sf::RectangleShape();
    sound = new sf::Sound();
    
    rect->setOutlineThickness(5);
    rect->setOutlineColor(sf::Color::Black);
    
    isPlaying = 0;
}

Key::~Key(){
    delete rect;
    delete sound;
}

void Key::draw(){
    window->draw(*rect);
}

void Key::play(){
    if (isPlaying == 0){
        sound->play();
        isPlaying = 2;

        if (rect->getFillColor() == sf::Color::White)
            rect->setFillColor(sf::Color(200, 200, 200));
        else if (rect->getFillColor() == sf::Color::Black)
            rect->setFillColor(sf::Color(50, 50, 50));
    }
}

void Key::stopPlaying(){
    if (rect->getFillColor() == sf::Color(200, 200, 200))
        rect->setFillColor(sf::Color::White);
    else if (rect->getFillColor() == sf::Color(50, 50, 50))
        rect->setFillColor(sf::Color::Black);

    isPlaying -= (isPlaying > 0) ? 1 : 0;
    if (isPlaying == 0)
        sound->stop();
}