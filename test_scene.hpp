#ifndef TEST_SCENE_HPP
#define TEST_SCENE_HPP

#include <tmx/MapLoader.h>
#include "scene.hpp"

class TestScene : public Scene, public InputManager {

public:
  TestScene();
  virtual ~TestScene();

  virtual void on_update(const sf::Time &dt);
  virtual void on_draw(sf::RenderWindow &window);
  virtual InputManager* get_input_manager(){ return this; }
  
  virtual void on_key_press(const sf::Keyboard::Key key);
  virtual void on_key_release(const sf::Keyboard::Key key);

protected:
  sf::CircleShape m_shape;
  float m_direction;
  sf::View m_map_view;
  tmx::MapLoader m_map_loader;
  static KeyList s_interested_keys;
};

#endif
