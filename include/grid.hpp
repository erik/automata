#ifndef _GRID_H_
#define _GRID_H_

#include <SFML/Graphics.hpp>

#include "automata.hpp"
#include "cell.hpp"

class Grid {
public:
  Grid(int width, int height, sf::RenderWindow& w);
  ~Grid();

  void SetCell(Cell* c);
  void Update(int delta);
  void Draw();
  void DrawCell(int x, int y, sf::Color c);

  Cell* GetCell(int x, int y);
  int GetWidth() { return m_width; }
  int GetHeight() { return m_height; }

private:
  int m_width;
  int m_height;
  Cell* m_cells[WINDOW_WIDTH * WINDOW_HEIGHT];
  sf::RenderWindow &m_window;
  sf::Image m_frame;
  sf::Sprite m_sprite;
};

#endif /* _GRID_H_ */
