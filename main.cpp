#include "window.hpp"
#include "neuron.cpp"
#include <SFML/Graphics/Color.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Neural Networks");

    std::vector<Neuron> input_layer = Neuron::generateNeurons(sf::Vector2f(100, 50), 5, sf::Color::Yellow);
    std::vector<Neuron> hidden1_layer = Neuron::generateNeurons(sf::Vector2f(250, 100), 3, sf::Color::Red);
    std::vector<Neuron> hidden2_layer = Neuron::generateNeurons(sf::Vector2f(400, 100), 3, sf::Color::Magenta);
    std::vector<Neuron> output_layer = Neuron::generateNeurons(sf::Vector2f(500, 50), 5, sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        Neuron::connectNeurons(window, input_layer, hidden1_layer);
        Neuron::connectNeurons(window, hidden1_layer, hidden2_layer);
        Neuron::connectNeurons(window, hidden2_layer, output_layer);

        for (const auto &neuron : input_layer)
        {
            window.draw(neuron.shape);
        }

        for (const auto &neuron : hidden1_layer)
        {
            window.draw(neuron.shape);
        }
        for (const auto &neuron : hidden2_layer)
        {
            window.draw(neuron.shape);
        }
        for (const auto &neuron : output_layer)
        {
            window.draw(neuron.shape);
        }
        window.display();
    }

    return 0;
}