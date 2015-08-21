#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>

class Scene {

public:
  Scene();
  virtual ~Scene();
  virtual void on_update(const sf::Time &dt);
  virtual void on_draw(sf::RenderWindow &window);
};

#endif
