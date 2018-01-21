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

#ifndef ORDER_MONITOR_H_
#define ORDER_MONITOR_H_

#include <pthread.h>
#include <queue>
#include <vector>
#include "order.h"
#include "order_comparator.h"

// OrderMonitor - taking order from queue
class OrderMonitor
{

public:


  OrderMonitor(int size);

  ~OrderMonitor();

  Order &get();

  void put(Order &);

private:
  Order order_;

  int size_;

  int max_size_;
  std::priority_queue<Order, std::vector<Order>, OrderComparator> orders_;

  pthread_mutex_t queue_mutex_;
  pthread_cond_t not_full_cond_;
  pthread_cond_t not_empty_cond_;
};

#endif
