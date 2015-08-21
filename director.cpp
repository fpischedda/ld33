#include "director.hpp"

Director::Director(){
}

Director::~Director(){}

sf::Time Director::restart_clock(){
  return m_clock.restart();
}

Scene* Director::set_scene(Scene *scene){
  Scene *old_scene = m_current_scene;
  m_current_scene = scene;
  
  return old_scene;
}

void Director::push_scene(Scene *scene){

  m_scene_stack.push_back(scene);
  m_current_scene = scene;
}

Scene* Director::pop_scene(){

  Scene *last_scene = m_current_scene;
  m_scene_stack.pop_back();
  
  if(m_scene_stack.size() > 0){
    m_current_scene = m_scene_stack.back();
  }
  else{
    m_current_scene = NULL;
  }
  
  return last_scene;
}

void Director::update(){

  sf::Time dt = restart_clock();

  if(m_current_scene != NULL){
    m_current_scene->on_update(dt);
  }
}

void Director::draw(sf::RenderWindow &window){

  if(m_current_scene != NULL){
    m_current_scene->on_draw(window);
  }
}
