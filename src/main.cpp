#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

int main(){
  ftxui::Element doc = ftxui::hbox(
    ftxui::text( "abi" ) | ftxui::border,
    ftxui::text( "stinky" ) | ftxui::border,
  );
  ftxui::Screen screen = ftxui::Screen::Create(
    ftxui::Dimension::Full(),
    ftxui::Dimension::Fit(doc)
  );

  ftxui::Render(screen, doc);
  screen.Print();
  std::cout << '\n';
  return 0;
}
