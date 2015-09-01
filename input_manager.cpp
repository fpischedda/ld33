#include "input_manager.hpp"

InputManager::InputManager(const KeyMap& key_map)
  : m_key_status(0), m_key_map(key_map){}

InputManager::~InputManager() {}

bool InputManager::on_key_press(sf::Keyboard::Key key){
  return false;
}

bool InputManager::on_key_release(sf::Keyboard::Key key){
  return false;
}
