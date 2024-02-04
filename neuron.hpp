#include <SFML/Graphics.hpp>

class Neuron
{
public:
    sf::CircleShape shape{20};

    void setPosition(float x, float y);
    void setFillColor(const sf::Color &color);
    static std::vector<Neuron> generateNeurons(const sf::Vector2f &initialPosition, int count, const sf::Color &color);
    static void connectNeurons(sf::RenderWindow &window, const std::vector<Neuron> &neurons1, const std::vector<Neuron> &neurons2);
};
