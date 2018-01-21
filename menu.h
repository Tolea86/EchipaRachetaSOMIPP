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

#ifndef MENU_H_
#define MENU_H_

#include <map>
#include <iostream>
#include "item.h"

// Menu - stores information about the dishes available 
class Menu
{
public:

  Menu();
  ~Menu();
  Item getItem(int id);
  int getSize();
  friend std::ostream& operator<<(std::ostream& os, const Menu& menu);

private:
  std::map<int, Item> items_;
};

#endif
