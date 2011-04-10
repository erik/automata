#include "automata.hpp"
#include "cell.hpp"
#include "grid.hpp"

Cell::Cell(int x, int y, int life) {
  m_x = x;
  m_y = y;
  m_life = life;
}

void Cell::SetGrid(Grid* g) {
  m_grid = g;
}

Cell* Cell::GetRandomNeighbor() {
  int rand = sf::Randomizer::Random(0, 8);
  int x = m_x;
  int y = m_y;

  /* going clockwise from direct left */
  switch (rand) {
  case 0:
    x--;
    break;
  case 1:
    x--;
    y--;
    break;
  case 2:
    y--;
    break;
  case 3:
    x++;
    y--;
    break;
  case 4:
    x++;
    break;
  case 5:
    x++;
    y++;
    break;
  case 6:
    y++;
    break;
  case 7:
    x--;
    y++;
    break;
  }
  
  int w = m_grid->GetWidth();
  int h = m_grid->GetHeight();
  
  if(x < 0) {
    x = m_x + 1;
  } else if(x > w - 1) {
    x = m_x - 1;
  }

  if( y < 0) {
    y = m_y + 1;
  } else if(y > h - 1) {
    y = m_y - 1;
  }

  return m_grid->GetCell(x, y);
}

int Cell::CalcColor() {
  int color =  (255 - (255 / ( m_life <= 0 ? 1 : m_life)));
  return color < 128 ? 128 : color;
}

/* Blank Cell */

BlankCell::BlankCell(int x, int y, int ignored) {
  m_x = x;
  m_y = y;
}

void BlankCell::Update(int dt) {
}

void BlankCell::Draw() {
  //  m_grid->DrawCell(m_x, m_y, sf::Color::White);
}

/* Red Cell */

RedCell::RedCell(int x, int y, int life) {
  m_x = x;
  m_y = y;
  m_life = life;
}

void RedCell::Update(int dt) {
  Cell* c = GetRandomNeighbor();
  if(c->GetType() == BLANK) {
    if(m_life <= 0) {
      m_life = 0;
      return;
    }
    Cell* tmp = new RedCell(c->GetX(), c->GetY(), m_life);
    m_grid->SetCell(tmp, c->GetX(), c->GetY());
  } else if(c->GetType() == GREEN) {
    Cell* tmp = new RedCell(c->GetX(), c->GetY(), m_life = 10);
    m_grid->SetCell(tmp, c->GetX(), c->GetY());
  }
  m_life--;
}

void RedCell::Draw() {
  m_grid->DrawCell(m_x, m_y, sf::Color(CalcColor(), 0, 0));
}

/* Green Cell */

GreenCell::GreenCell(int x, int y, int life) {
  m_x = x;
  m_y = y;
  m_life = life;
}

void GreenCell::Update(int dt) {
  Cell* c = GetRandomNeighbor();
  if(c->GetType() == BLANK) {
    if(m_life <= 0) {
      m_life = 0;
      return;
    }
    Cell* tmp = new GreenCell(c->GetX(), c->GetY(), m_life);
    m_grid->SetCell(tmp, c->GetX(), c->GetY());
  } else if(c->GetType() == BLUE) {
    Cell* tmp = new GreenCell(c->GetX(), c->GetY(), m_life = 10);
    m_grid->SetCell(tmp, c->GetX(), c->GetY());
  }
  m_life--;
}

void GreenCell::Draw() {
  m_grid->DrawCell(m_x, m_y, sf::Color(0, CalcColor(), 0));
}

/* Blue Cell */

BlueCell::BlueCell(int x, int y, int life) {
  m_x = x;
  m_y = y;
  m_life = life;
}

void BlueCell::Update(int dt) {
  Cell* c = GetRandomNeighbor();
  if(c->GetType() == BLANK) {
    if(m_life <= 0) {
      m_life = 0;
      return;
    }
    Cell* tmp = new BlueCell(c->GetX(), c->GetY(), m_life);
    m_grid->SetCell(tmp, c->GetX(), c->GetY());
  } else if(c->GetType() == RED) {
    Cell* tmp = new BlueCell(c->GetX(), c->GetY(), m_life = 10);
    m_grid->SetCell(tmp, c->GetX(), c->GetY());
  }
  m_life--;
}

void BlueCell::Draw() {
  m_grid->DrawCell(m_x, m_y, sf::Color(0, 0, CalcColor()));
}
