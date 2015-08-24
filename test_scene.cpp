#define LOG_OUTPUT_ALL

#include <tmx/Log.h>
#include "test_scene.hpp"

TestScene::TestScene() : m_shape(100.f),
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

  m_shape.move( 25.f * dt.asSeconds(), 0.f);
  m_map_view.setCenter( m_shape.getPosition());
}

void TestScene::on_draw(sf::RenderWindow &window){

  window.clear();
  window.setView(m_map_view);
  window.draw(m_map_loader);
  window.draw(m_shape);
  window.display();
}
