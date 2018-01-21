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

#include "item.h"
#include <string>

using namespace std;

Item::Item(string name, int prep_time, int complexity, string cooking_app)
  : name_(name), prep_time_(prep_time), complexity_(complexity), cooking_app_(cooking_app)
{

}

Item::~Item()
{

}

ostream& operator<<(ostream& os, const Item& item)
{
  os << item.name_ << endl
    << "\tPreparation time: " << item.prep_time_ << endl
    << "\tComplexity: " << item.complexity_ << endl
    << "\tCooking apparatus: " << item.cooking_app_ << endl;
  return os;
}
