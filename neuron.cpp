#include "neuron.hpp"

void Neuron::setFillColor(const sf::Color &color)
{
    shape.setFillColor(color);
}

void Neuron::setPosition(float x, float y)
{
    shape.setPosition(x, y);
}

std::vector<Neuron> Neuron::generateNeurons(const sf::Vector2f &initialPosition, int count, const sf::Color &color)
{
    std::vector<Neuron> neurons;

    for (int i = 0; i < count; ++i)
    {
        Neuron neuron;
        neuron.setPosition(initialPosition.x, initialPosition.y + i * 120);
        neuron.setFillColor(color);
        neurons.emplace_back(neuron);
    }

    return neurons;
}

void Neuron::connectNeurons(sf::RenderWindow &window, const std::vector<Neuron> &neurons1, const std::vector<Neuron> &neurons2)
{
    sf::VertexArray lines(sf::Lines);

    for (const auto &neuron1 : neurons1)
    {
        for (const auto &neuron2 : neurons2)
        {
            sf::Vector2f center1 = neuron1.shape.getPosition() + sf::Vector2f(neuron1.shape.getRadius(), neuron1.shape.getRadius());
            sf::Vector2f center2 = neuron2.shape.getPosition() + sf::Vector2f(neuron2.shape.getRadius(), neuron2.shape.getRadius());

            sf::Vertex vertex1(center1, sf::Color::Green);
            sf::Vertex vertex2(center2, sf::Color::Green);

            lines.append(vertex1);
            lines.append(vertex2);
        }
    }

    window.draw(lines);
}