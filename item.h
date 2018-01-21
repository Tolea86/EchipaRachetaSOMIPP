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

#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <iostream>

class Item
{
public:

  Item(std::string name = "Mivina", int prep_time = 3, int complexity = 1, std::string cooking_app = "none");

  ~Item();

  std::string name_;
  int prep_time_;
  int complexity_;
  std::string cooking_app_;
  friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

#endif
