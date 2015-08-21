#ifndef TEST_SCENE_HPP
#define TEST_SCENE_HPP

#include "scene.hpp"

class TestScene : public Scene {

public:
  TestScene();
  virtual ~TestScene();

  virtual void on_update(const sf::Time &dt);
  virtual void on_draw(sf::RenderWindow &window);

protected:
  sf::CircleShape m_shape;
};

#endif
