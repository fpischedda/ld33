#include <SFML/Graphics.hpp>
#include "director.hpp"
#include "test_scene.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    Director director;
    TestScene scene;
    director.set_scene(&scene);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

	director.update();
	director.draw(window);
    }

    return 0;
}
