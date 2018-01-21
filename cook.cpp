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

#include "cook.h"
#include <unistd.h>
#include <iostream>
#include <vector>
#include "restaurant.h"
#include "order.h"

using namespace std;

Cook::Cook(Bundle& bundle, string name, string phrase, int rank, int proficiency)
  : bundle_(bundle), name_(name), catch_phrase_(phrase),
    rank_(rank), proficiency_(proficiency)
{

}

Cook::~Cook()
{
  cancel();
}

void Cook::start(void* args)
{
  Thread::start(args);
  pthread_detach(thread_);
}

void Cook::run()
{
  vector<int> items = vector<int>();
  Order order(items, 1);
  int stars;

  while (1)
  {
    order = bundle_.order_monitor_.get();

    if (rank_ < order.complexity_ or proficiency_ < (int) order.items_.size())
    {
      bundle_.order_monitor_.put(order);
      usleep(timeMeasurementUnit);
    }
    else
    {
      prepareItems(order);
      stars = order.finish();
      bundle_.star_counter_.add(stars);
    }
  }
  pthread_exit(NULL);
}

void Cook::prepareItems(Order& order)
{
  Item item;
  string cookingApparatus;
  vector<Worker*> workList;

  for (int i = 0; i < proficiency_; ++i) {
    workList.push_back(new Worker(*this, item));
  }

  for (uint i = 0; i < order.items_.size(); ++i)
  {
    item = bundle_.menu_.getItem(order.items_[i]);
    workList[i]->item_ = item;
    workList[i]->start();
  }

  for (int i = 0; i < proficiency_; ++i)
  {
    auto worker = workList[i];
    workList.pop_back();
    worker->join();
    delete worker;
  }
}

Cook::Worker::Worker(Cook& cook, Item& item) : cook_(cook), item_(item)
{

}

Cook::Worker::~Worker()
{
  cancel();
}

void Cook::Worker::run()
{
  string cookingApparatus = item_.cooking_app_;
  if (cookingApparatus == "oven") cook_.bundle_.kitchen_.useOven();
  else if (cookingApparatus == "stove") cook_.bundle_.kitchen_.useStove();

  usleep(item_.prep_time_ * timeMeasurementUnit);

  if (cookingApparatus == "oven") cook_.bundle_.kitchen_.releaseOven();
  else if (cookingApparatus == "stove") cook_.bundle_.kitchen_.releaseStove();
  pthread_exit(NULL);
}
