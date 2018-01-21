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

#include "waiter.h"
#include <unistd.h>
#include <iostream>
#include "restaurant.h"
#include "order.h"

using namespace std;

Waiter::Waiter(Bundle& bundle, string name, string catch_phrase) :
  bundle_(bundle), catch_phrase_(catch_phrase), name_(name)
{

}

Waiter::~Waiter()
{
  cancel();
}

void Waiter::start(void* args)
{
  Thread::start(args);
  pthread_detach(thread_);
}

void Waiter::run()
{
  int num_items = 1;
  vector<int> items = vector<int>(num_items);
  Order order(items, 1);
  while (1)
  {
    order.items_.clear();
    num_items = rand() % 3 + 1;
    for (int i = 0; i < num_items; ++i)
      order.items_.push_back(rand() % bundle_.menu_.getSize() + 1);
    order.priority_ = rand() % 5 + 1;
    order.createFrom(bundle_.menu_);
    bundle_.order_monitor_.put(order);
    usleep((rand() % 5 + 2) * timeMeasurementUnit);
  }
  pthread_exit(NULL);
}
