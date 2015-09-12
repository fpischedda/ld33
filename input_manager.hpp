#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <vector>
#include <map>
#include <SFML/Window/Keyboard.hpp>

typedef std::map<sf::Keyboard::Key, unsigned int> KeyMap;
typedef std::vector<sf::Keyboard::Key> KeyList;

class InputManager {

public:
  InputManager(const KeyList& key_list);
  virtual ~InputManager();

  bool key_pressed(sf::Keyboard::Key key);
  bool key_released(sf::Keyboard::Key key);
  
  virtual void on_key_press(const sf::Keyboard::Key key);
  virtual void on_key_release(const sf::Keyboard::Key key);

private:
  unsigned int m_key_status;
  KeyList m_key_list;
  KeyMap m_key_map;
};

#endif
