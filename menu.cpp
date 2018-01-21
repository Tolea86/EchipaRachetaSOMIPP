// Copyright 2017 Echipa Racheta <Facebook: Echipa Racheta>

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "menu.h"

Menu::Menu()
{
  items_ = {
    {1, Item("Pizza", 20, 2, "oven")},
    {2, Item("Salad", 10, 1, "none")},
    {3, Item("Zeama", 7, 1, "stove")},
    {4, Item("Scallop Sashimi with Meyer Lemon Confit", 32, 3, "none")},
    {5, Item("Island Duck with Mulberry Mustard", 35, 3, "oven")},
    {6, Item("Waffles", 10, 1, "stove")},
    {7, Item("Aubergine", 20, 2, "none")},
    {8, Item("Lasagna", 30, 2, "oven")},
    {9, Item("Sandwich", 5, 1, "none")},
    {10, Item("Sushi", 20, 2, "none")},
    {11, Item("DeltaSquad Special Tea", 2, 1, "none")}
  };
}

Menu::~Menu()
{

}

Item Menu::getItem(int id)
{
  return items_.at(id);
}

int Menu::getSize()
{
  return items_.size();
}

std::ostream& operator<<(std::ostream& os, const Menu& menu)
{
  os << "Today in our menu:" << std::endl;

  for (auto it = menu.items_.cbegin(); it != menu.items_.cend(); ++it)
    os << (*it).first << ". " << (*it).second << std::endl;
  return os;
}
