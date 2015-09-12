#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "scene.hpp"

class Director {

public:
  Director();
  virtual ~Director();
  void push_scene(Scene* scene);
  Scene* pop_scene();
  Scene* set_scene(Scene* scene);
  sf::Time restart_clock();
  void update();
  void draw(sf::RenderWindow &window);

  bool key_pressed(sf::Keyboard::Key key);
  bool key_released(sf::Keyboard::Key key);

protected:
  std::vector<Scene*> m_scene_stack;
  Scene* m_current_scene;
  sf::Clock m_clock;
  InputManager* m_current_input_manager;
};

#endif
