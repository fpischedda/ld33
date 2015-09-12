#include "input_manager.hpp"

InputManager::InputManager(const KeyList& key_list)
  : m_key_status(0), m_key_list(key_list){

  int index = 0;
  for(auto k : m_key_list){
    m_key_map[k] = index;
    ++ index;
  }
}

InputManager::~InputManager() {}

void InputManager::on_key_press(const sf::Keyboard::Key key) {}
void InputManager::on_key_release(const sf::Keyboard::Key key) {}

bool InputManager::key_pressed(sf::Keyboard::Key key){

  try {
    auto idx = m_key_map[key];

    auto mask = 1 << idx;
    if(m_key_status & mask) return false;

    m_key_status |= mask;
    on_key_press(key); // "signal" real key press event
    return true;
  }
  catch(...){
    return false;
  }
}

bool InputManager::key_released(sf::Keyboard::Key key){
  try {
    auto idx = m_key_map[key];

    auto mask = 1 << idx;
    if(m_key_status & mask){
      m_key_status &= ~mask;
      on_key_release(key); // "signal" real key release event
      return true;
    }
  }
  catch(...){}

  return false;
}
