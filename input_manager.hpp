#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <vector>
#include <SFML/Window/Keyboard.hpp>

typedef std::vector<sf::Keyboard::Key> KeyMap;

class InputManager {

private:
  unsigned int m_key_status;
  KeyMap m_key_map;

public:
  InputManager(const KeyMap& key_map);
  virtual ~InputManager();

  virtual bool on_key_press(sf::Keyboard::Key key);
  virtual bool on_key_release(sf::Keyboard::Key key);
};

#endif
