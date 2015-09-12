#include "scene.hpp"

Scene::Scene() {}
Scene::~Scene() {}
void Scene::on_update(const sf::Time &dt){}
void Scene::on_draw(sf::RenderWindow &window){}
InputManager* Scene::get_input_manager(){ return NULL;}


