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

#include "star_counter.h"

StarCounter::StarCounter(int max_star) : max_star_(max_star), counter_(0), sum_()
{
  pthread_mutex_init(&sum_mutex_, NULL);
}

StarCounter::~StarCounter()
{
  pthread_mutex_destroy(&sum_mutex_);
}

void StarCounter::add(int new_star)
{
  if (new_star < 0) return;
  pthread_mutex_lock(&sum_mutex_);
  sum_ += (new_star > max_star_) ? max_star_ : new_star;
  ++counter_;
  pthread_mutex_unlock(&sum_mutex_);
}

float StarCounter::average()
{
  if (counter_ == 0) return -1;
  return (float) sum_ / counter_;
}
