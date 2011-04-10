#ifndef _GRID_H_
#define _GRID_H_

#include <SFML/Graphics.hpp>

#include "cell.hpp"

class Grid {
public:
  Grid(int width, int height, sf::RenderWindow& w);
  ~Grid();

  void SetCell(Cell*, int x, int y);
  void Update(int delta);
  void Draw();
  void DrawCell(int x, int y, sf::Color c);

  Cell* GetCell(int x, int y);
  int GetWidth() { return m_width; }
  int GetHeight() { return m_height; }

private:
  bool m_drawEvens;
  int m_width;
  int m_height;
  Cell* m_cells[250 * 250];
  sf::RenderWindow &m_window;
};

#endif /* _GRID_H_ */
