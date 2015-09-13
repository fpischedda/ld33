#define LOG_OUTPUT_ALL

#include <tmx/Log.h>
#include "test_scene.hpp"

KeyList TestScene::s_interested_keys = {
  sf::Keyboard::Left, sf::Keyboard::Right,
  sf::Keyboard::Up, sf::Keyboard::Down
};

TestScene::TestScene() :
  InputManager(TestScene::s_interested_keys),
  m_shape(100.f),
  m_velocity(50.f),
  m_direction(0.f, 0.f),
  m_map_loader("res/maps/"),
  m_map_view(sf::FloatRect(0, 0, 640, 480))
{
  m_shape.setFillColor(sf::Color::Green);

  tmx::Logger::SetLogLevel(tmx::Logger::Info | tmx::Logger::Warning | tmx::Logger::Error);
  
  std::cout << "Loading map..." << std::endl;
  const char *filename = "game.tmx";
  auto loaded = m_map_loader.Load(filename);
  std::cout << (loaded ? "success" : "failed!");
}

TestScene::~TestScene(){

}

void TestScene::on_update(const sf::Time &dt){

  auto vel_vect = m_direction * (dt.asSeconds() * m_velocity);
  m_shape.move(vel_vect);
  m_map_view.setCenter( m_shape.getPosition());
}

void TestScene::on_draw(sf::RenderWindow &window){

  window.clear();
  window.setView(m_map_view);
  window.draw(m_map_loader);
  window.draw(m_shape);
  window.display();
}

void TestScene::on_key_press(const sf::Keyboard::Key key) {

  if(key == sf::Keyboard::Left){
    m_direction.x = -1.f;
  }
  else if(key == sf::Keyboard::Right){
    m_direction.x = 1.f;
  }
}

void TestScene::on_key_release(const sf::Keyboard::Key key) {

  m_direction.x = 0.f;
}
