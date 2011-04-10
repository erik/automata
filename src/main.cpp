#include <SFML/Window.hpp>

#include "automata.hpp"
#include "grid.hpp"
#include "cell.hpp"

#include <iostream>
#include <sstream>

int main(void) {
  double scalex = 200.0 / 800;
  double scaley = 200.0 / 600;

  sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Automata");
  App.UseVerticalSync(true);
  App.SetFramerateLimit(12);

  sf::View view(sf::FloatRect(0, 0, 200, 200));
  App.SetView(view);

  App.Clear(sf::Color(255, 255, 255));
  
  Grid g(200, 200, App);

  bool mouseDown = false;

  CellType selection = RED;

  const sf::Input& input = App.GetInput();

  while (App.IsOpened()) {
    float time = App.GetFrameTime();

    sf::Event Event;
    while (App.GetEvent(Event)) {
      if(Event.Type == sf::Event::Closed) {
        App.Close();
      } else if((Event.Type == sf::Event::KeyPressed) && 
                (Event.Key.Code == sf::Key::Escape)) {
        App.Close();
      } else if(Event.Type == sf::Event::MouseButtonPressed) {
        mouseDown = true;
      } else if(Event.Type == sf::Event::MouseButtonReleased) {
        mouseDown = false;
      } else if(Event.Type == sf::Event::KeyPressed) {
        if(Event.Key.Code == '1') {
          selection = RED;
        } else if(Event.Key.Code == '2') {
          selection = GREEN;
        } else if(Event.Key.Code == '3') {
          selection = BLUE;
        } else if(Event.Key.Code == '4') {
          selection = PURPLE;
        } else if(Event.Key.Code == '5') {
          selection = BLACK;
        }
      }
    }
    
    if(mouseDown) {
      int x = input.GetMouseX() * scalex;
      int y = input.GetMouseY() * scaley;

      if( x > 199) {
        x = 199;
      } else if( x < 0 ) {
        x = 0;
      }

      if(y > 199) {
        y = 199;
      } else if( y < 0 ) {
        y = 0;
      }
      Cell* tmp = NULL;
      switch(selection) {
      case RED:
        tmp = new RedCell(x, y);
        break;
      case GREEN:
        tmp = new GreenCell(x, y);
        break;
      case BLUE:
        tmp = new BlueCell(x, y);
        break;
      case PURPLE:
        tmp = new PurpleCell(x, y);
      case BLACK:
        tmp = new BlackCell(x, y);
      default:
        break;
      }

      g.SetCell(tmp, x, y);      
    }
    
    g.Update(time);
    g.Draw();
    
    App.Display();
  }

  return 0;
}
