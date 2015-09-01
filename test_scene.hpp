#ifndef TEST_SCENE_HPP
#define TEST_SCENE_HPP

#include <tmx/MapLoader.h>
#include "scene.hpp"
#include "input_manager.hpp"

class TestScene : public Scene, public InputManager {

public:
  TestScene();
  virtual ~TestScene();

  virtual void on_update(const sf::Time &dt);
  virtual void on_draw(sf::RenderWindow &window);

protected:
  sf::CircleShape m_shape;
  sf::View m_map_view;
  tmx::MapLoader m_map_loader;
  static KeyMap s_interested_keys;
};

#endif
