#include <SFML/Graphics.hpp>
#include "director.hpp"
#include "test_scene.hpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
  Director director;
  TestScene scene;
  director.set_scene(&scene);

  while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
	switch (event.type){
	  case sf::Event::Closed:
	  window.close();
	  break;
	case sf::Event::KeyPressed:
	  director.key_pressed(event.key.code);
	  break;
	case sf::Event::KeyReleased:
	  director.key_released(event.key.code);
	  break;
	}
      }

      director.update();
      director.draw(window);
    }

  return 0;
}
