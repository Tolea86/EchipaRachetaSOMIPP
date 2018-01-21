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

#ifndef COOK_H_
#define COOK_H_

#include <string>
#include "thread.h"
#include "bundle.h"
#include "order_monitor.h"
#include "menu.h"
#include "item.h"

// Cook - takes orders from order queue and executes them.
class Cook : public Thread
{
public:

  Cook(Bundle&, std::string name = "Test", std::string phrase = "Testing test",
    int rank = 1, int proficiency = 1);

  ~Cook();

  void start(void* args = NULL);

  void run();

private:

  // Worker - process items in parallel.
  class Worker : public Thread
  {
  public:

    Worker(Cook&, Item&);

    ~Worker();

    void run();

    Cook& cook_;

    Item& item_;
  };

  void prepareItems(Order& order);

  Bundle& bundle_;

  std::string name_;

  std::string catch_phrase_;

  int rank_;
  int proficiency_;
};

#endif
