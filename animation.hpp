////////////////////////////////////////////////////////////
//
// Copyright (C) 2015 Francesco Pischedda (francesco.pischedda@google.com)
// Based on the previous work of
// Copyright (C) 2014 Maximilian Wagenbach (aka. Foaly) (foaly.f@web.de)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

struct FrameInfo {

  sf::Vector2f tex_coords[4];
  sf::Vector2f frame_size[4];
  sf::FloatRect local_bounds;
};

class Animation
{
public:
  Animation(const sf::Texture* tex=NULL);

  template <typename T>
  void addFrameRect(const sf::Rect<T> rect);
  void addFrame(const std::vector<sf::Vector2f>& points);
  void setSpriteSheet(const sf::Texture& texture);
  const sf::Texture* getSpriteSheet() const;
  std::size_t getSize() const;
  const FrameInfo& getFrame(std::size_t n) const;

private:
  std::vector<FrameInfo> m_frames;
  const sf::Texture* m_texture;
};

#endif // ANIMATION_INCLUDE
