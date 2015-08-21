#include "test_scene.hpp"

TestScene::TestScene() : m_shape(100.f) {
    m_shape.setFillColor(sf::Color::Green);
}

TestScene::~TestScene(){}

void TestScene::on_update(const sf::Time &dt){

}

void TestScene::on_draw(sf::RenderWindow &window){

  window.clear();
  window.draw(m_shape);
  window.display();
}
