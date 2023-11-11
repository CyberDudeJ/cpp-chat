// Copyright 2021 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSED file.
#include <cmath>                   // for sin, cos
#include <ftxui/dom/elements.hpp>  // for canvas, Element, separator, hbox, operator|, border
#include <ftxui/screen/screen.hpp>  // for Pixel
#include <memory>   // for allocator, shared_ptr, __shared_ptr_access
#include <string>   // for string, basic_string
#include <utility>  // for move
#include <vector>   // for vector, __alloc_traits<>::value_type

#include "ftxui/component/component.hpp"  // for Renderer, CatchEvent, Horizontal, Menu, Tab
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/event.hpp"               // for Event
#include "ftxui/component/mouse.hpp"               // for Mouse
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

int main() {
  using namespace ftxui;
 
  int selected_tab = 1;
  auto tab = Container::Tab(
      {
          test,
      },
      &selected_tab);

  std::vector<std::string> tab_titles = {
      "test",
  };
  auto tab_toggle = Menu(&tab_titles, &selected_tab);

  auto component = Container::Horizontal({
      tab_with_mouse,
      tab_toggle,
  });

  // Add some separator to decorate the whole component:
  auto component_renderer = Renderer(component, [&] {
    return hbox({
               tab_with_mouse->Render(),
               separator(),
               tab_toggle->Render(),
           }) |
           border;
  });

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(component_renderer);

  return 0;
}
