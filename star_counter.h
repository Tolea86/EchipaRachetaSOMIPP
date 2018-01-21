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

#ifndef STAR_COUNTER_H_
#define STAR_COUNTER_H_

#include <pthread.h>

// StarCounter - count the stars (aka rating)
class StarCounter
{
public:

  StarCounter(int max_star = 5);

  ~StarCounter();

  void add(int new_star);

  float average();

private:

  int max_star_;

  int counter_;

  unsigned long sum_;

  pthread_mutex_t sum_mutex_;
};

#endif
