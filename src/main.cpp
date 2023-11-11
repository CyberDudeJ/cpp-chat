#include <memory>  // for allocator, __shared_ptr_access
#include <string>  // for char_traits, operator+, string, basic_string
 
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/component_options.hpp"  // for InputOption
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border
#include "ftxui/util/ref.hpp"  // for Ref
 
int main() {
  using namespace ftxui;
 
  // The data:
  std::string username;
  std::string password;
 
  // The basic input components:
  Component input_username = Input(&username, "username"); 
  // The password input component:
  InputOption password_option;
  password_option.password = true;
  Component input_password = Input(&password, "password", password_option);
 
  // The phone number input component:
  // We are using `CatchEvent` to filter out non-digit characters.
 
  // The component tree:
  auto component = Container::Vertical({
      input_username,
      input_password,
});
 
  // Tweak how the component tree is rendered:
  auto renderer = Renderer(component, [&] {
    return vbox({
               hbox(text(" Username: "), input_username->Render()),
               hbox(text(" Password: "), input_password->Render()),
               separator(),
               text("Hello " + username + "!"),
           }) |
           border;
  });
 
  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(renderer);
}
