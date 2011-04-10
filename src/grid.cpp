#include "automata.hpp"
#include "grid.hpp"
#include "cell.hpp"

#include <cstdlib>
#include <iostream>

Grid::Grid(int width, int height, sf::RenderWindow& w) :
  m_width(width),
  m_height(height),
  m_window(w),
  m_frame(WINDOW_WIDTH, WINDOW_HEIGHT, sf::Color(255, 255, 255)),
  m_sprite(m_frame)
{
  for(int y = 0; y < height; ++y) {
    for(int x = 0; x < width; ++x) {
      Cell* tmp = new BlankCell(x, y);
      tmp->SetGrid(this);
      m_cells[y * width + x] = tmp;
    }
  }
}

Grid::~Grid() {
  for(int i = 0; i < m_height * m_width; ++i) {
    delete m_cells[i];
  }
}

void Grid::SetCell(Cell* c, int x, int y) {
  if(m_cells[y * m_width + x]) {
    delete m_cells[y * m_width + x];
  }
  c->SetGrid(this);
  m_cells[y * m_width + x] = c;
}

void Grid::Update(int dt) {
  for(int i = 0; i < m_width * m_height; i++) {
    m_cells[i]->Update(dt);
  }
}

void Grid::Draw() {

  for(int i= 0; i < m_width * m_height; i++) {
    m_cells[i]->Draw();
  }
  
  m_window.Draw(m_sprite);

}

void Grid::DrawCell(int x, int y, sf::Color c) {
    m_frame.SetPixel(x, y, c);
}

Cell* Grid::GetCell(int x, int y) {
  return m_cells[y * m_width + x];
}
