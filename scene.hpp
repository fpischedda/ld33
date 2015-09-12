#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include "input_manager.hpp"

class Scene {

public:
  Scene();
  virtual ~Scene();
  virtual void on_update(const sf::Time &dt);
  virtual void on_draw(sf::RenderWindow &window);
  virtual InputManager* get_input_manager();
};

#endif
