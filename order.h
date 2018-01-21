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

#ifndef ORDER_H_
#define ORDER_H_

#include <chrono>
#include <iostream>
#include <vector>
#include "menu.h"


class Order
{
public:

 
  Order(std::vector<int>& items, int priority = 1);
  Order();

  ~Order();

  
  void createFrom(Menu&);

  
  int finish();


  std::vector<int> items_;

  int priority_;

  int complexity_;

  friend std::ostream& operator<<(std::ostream& os, const Order& order);

private:


  int computeOrderRank();

  int getComplexity(Menu&);

  int max_wait_time_;

  int real_wait_time_;

  std::chrono::steady_clock::time_point created_at_;

  std::chrono::steady_clock::time_point finished_at_;

  std::chrono::microseconds time_span_;
};

#endif
