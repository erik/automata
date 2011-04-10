#ifndef _CELL_H_
#define _CELL_H_

class Grid;

enum CellType {
  NONE,
  BLANK,
  RED,
  GREEN, 
  BLUE
} ;

// base cell type
class Cell {
public:
  Cell() : m_x(0), m_y(0) {}
  Cell(int x, int y, int life = 10);

  void SetGrid(Grid* g);

  Cell* GetRandomNeighbor();

  int CalcColor();

  int GetX() { return m_x; }
  int GetY() { return m_y; }

  virtual ~Cell() {}

  virtual void Update (int delta) = 0;
  virtual void Draw () = 0;
  virtual CellType GetType() = 0;

protected:
  Grid *m_grid;
  int m_x;
  int m_y;
  int m_life;
};

// empty cell
class BlankCell : public Cell {
public:
  BlankCell(int x, int y, int ignored = 10);

  void Update(int delta);
  void Draw();

  CellType GetType() { return BLANK; }
};

class RedCell : public Cell {
public:
  RedCell(int x, int y, int life=10);

  void Update(int delta);
  void Draw();

  CellType GetType() { return RED; }
private:
};

class GreenCell : public Cell {
public:
  GreenCell(int x, int y, int life = 10);

  void Update(int delta);
  void Draw();

  CellType GetType() { return GREEN; }
};

class BlueCell : public Cell {
public:
  BlueCell(int x, int y, int life = 10);

  void Update(int delta);
  void Draw();

  CellType GetType() { return BLUE; }
};

#endif /* _CELL_H_ */
