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

#include "order.h"
#include <iostream>
#include "restaurant.h"

using namespace std;

Order::Order(vector<int>& items, int priority) : items_(items), priority_(priority)
{

}

Order::Order() : items_(vector<int>()), priority_(1)
{

}

Order::~Order()
{

}

void Order::createFrom(Menu& menu)
{
  int max_prep_time = (menu.getItem(items_[0])).prep_time_;
  for (vector<int>::iterator i = items_.begin(); i != items_.end(); ++i)
    if ((menu.getItem(*i)).prep_time_ > max_prep_time)
      max_prep_time = (menu.getItem(*i)).prep_time_;

  max_wait_time_ = max_prep_time * maxWaitTime;
  created_at_ = chrono::steady_clock::now();
  complexity_ = getComplexity(menu);
}

int Order::finish()
{
  finished_at_ = chrono::steady_clock::now();
  time_span_ = chrono::duration_cast<chrono::microseconds>(finished_at_ - created_at_);
  real_wait_time_ = (int) (time_span_.count() / timeMeasurementUnit);

  int rank = computeOrderRank();

  string items = to_string(items_[0]);
  for (unsigned int i = 1; i < items_.size(); ++i)
  {
    items += "," + to_string(items_[i]);
  }

  cout << endl << "Items : [" << items << "] Complexity : (" << complexity_
    << ") Max Wait Time: (" << max_wait_time_ << ") was done in "
    << real_wait_time_ << " t.u. "
    << rank << " stars.\t";
  return rank;
}

int Order::computeOrderRank()
{
  if (real_wait_time_ < max_wait_time_ * fiveStarsCoefficient) {
    return 5;
  } else if (real_wait_time_ < max_wait_time_ * fourStarsCoefficient) {
    return 4;
  } else if (real_wait_time_ < max_wait_time_ * threeStarsCoefficient) {
    return 3;
  } else if (real_wait_time_ < max_wait_time_ * twoStarsCoefficient) {
    return 2;
  } else if (real_wait_time_ < max_wait_time_ * oneStarCoefficient) {
    return 1;
  } else {
    return 0;
  }
}

int Order::getComplexity(Menu& menu)
{
  int max = (menu.getItem(items_[0])).complexity_;
  for (vector<int>::iterator i = items_.begin(); i != items_.end(); ++i)
    if ((menu.getItem(*i)).complexity_ > max)
      max = (menu.getItem(*i)).complexity_;
  return max;
}

ostream& operator<<(ostream& os, const Order& order)
{
  os << endl << "\tOrder:" << endl
    // << "Items: " << order.items_ << endl
    << "Priority: " << order.priority_ << endl
    << "Max-wait time: " << order.max_wait_time_ << endl;
  return os;
}

