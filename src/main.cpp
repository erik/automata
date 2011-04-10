#include <SFML/Window.hpp>

#include "automata.hpp"
#include "grid.hpp"
#include "cell.hpp"

#include <iostream>
#include <sstream>

int main(void) {
  double scalex = WINDOW_WIDTH / 600.0;
  double scaley = WINDOW_HEIGHT / 600.0;

  sf::RenderWindow App(sf::VideoMode(600, 600, 32), "Automata");
  App.UseVerticalSync(true);

  sf::View view(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
  App.SetView(view);

  App.Clear(sf::Color(255, 255, 255));
  
  Grid g(WINDOW_WIDTH, WINDOW_HEIGHT, App);

  bool mouseDown = false;

  CellType selection = RED;

  const sf::Input& input = App.GetInput();
  
  // limit the number of draws per second 
  double drawTimer = 1.0 / 20;

  while (App.IsOpened()) {
    double time = App.GetFrameTime();
    drawTimer -= time;


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
        } else if(Event.Key.Code == '6') {
          selection = YELLOW;
        }
      }
    }
    
    if(mouseDown) {
      int x = input.GetMouseX() * scalex;
      int y = input.GetMouseY() * scaley;

      if( x > WINDOW_WIDTH - 1) {
        x = WINDOW_WIDTH - 1;
      } else if( x < 0 ) {
        x = 0;
      }

      if(y > WINDOW_HEIGHT - 1) {
        y = WINDOW_HEIGHT - 1;
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
        break;
      case BLACK:
        tmp = new BlackCell(x, y);
        break;
      case YELLOW:
        tmp = new YellowCell(x, y);
        break;
      default:
        break;
      }

      g.SetCell(tmp, x, y);      
    }
    
    g.Update(time);
    
    if(drawTimer <= 0) {
      App.Clear(sf::Color(255, 255, 255));
      g.Draw();
      drawTimer = 1.0 / 20;
    }
    
    App.Display();
  }

  return 0;
}
