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

#include "order_monitor.h"
#include <iostream>
#include <pthread.h>

OrderMonitor::OrderMonitor(int size)
{
  max_size_ = size;
  size_ = 0;
  pthread_cond_init(&not_empty_cond_, NULL);
  pthread_cond_init(&not_full_cond_, NULL);
  pthread_mutex_init(&queue_mutex_, NULL);
}

OrderMonitor::~OrderMonitor()
{
  pthread_cond_destroy(&not_empty_cond_);
  pthread_cond_destroy(&not_full_cond_);
  pthread_mutex_destroy(&queue_mutex_);
}

Order &OrderMonitor::get()
{
  pthread_mutex_lock(&queue_mutex_);
  if (orders_.empty())
    pthread_cond_wait(&not_empty_cond_, &queue_mutex_);
  order_ = orders_.top();
  --size_;
  orders_.pop();
  pthread_cond_signal(&not_full_cond_);
  pthread_mutex_unlock(&queue_mutex_);
  return order_;
}

void OrderMonitor::put(Order &new_order)
{
  pthread_mutex_lock(&queue_mutex_);
  if (size_ == max_size_)
    pthread_cond_wait(&not_full_cond_, &queue_mutex_);
  ++size_;
  orders_.push(new_order);
  pthread_cond_signal(&not_empty_cond_);
  pthread_mutex_unlock(&queue_mutex_);
}
