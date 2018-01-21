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

#ifndef BUNDLE_H_
#define BUNDLE_H_

#include "order_monitor.h"
#include "menu.h"
#include "kitchen.h"
#include "star_counter.h"

// Bundle - a container class for restaurant's objects order monitor, menu, kitchen.
class Bundle
{
public:

  // JUST A CONSTRUCTOR
  Bundle(OrderMonitor&, Menu&, Kitchen&, StarCounter&);

  // JUST A DECONSTRUCTOR
  ~Bundle();

  // References to the restaurant's resources: order monitor, menu, kitchen.
  OrderMonitor& order_monitor_;
  Menu& menu_;
  Kitchen& kitchen_;
  StarCounter& star_counter_;
};

#endif
