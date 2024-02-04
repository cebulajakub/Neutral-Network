// window.hpp
#pragma once

#include <SFML/Graphics.hpp>

class Window
{
public:
    Window(sf::VideoMode mode, const sf::String &title)
        : window(mode, title)
    {
    }

    void clear(const sf::Color &color = sf::Color::Black)
    {
        window.clear(color);
    }

    void draw(const sf::Drawable &drawable)
    {
        window.draw(drawable);
    }

    void display()
    {
        window.display();
    }

    bool isOpen()
    {
        return window.isOpen();
    }

    void close()
    {
        window.close();
    }

    bool pollEvent(sf::Event &event)
    {
        return window.pollEvent(event);
    }

private:
    sf::RenderWindow window;
};
