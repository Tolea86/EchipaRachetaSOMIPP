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

#ifndef  KITCHEN_H_
#define KITCHEN_H_

#include <pthread.h>

// Kitchen - simulates how cooks use the cooking apparatus

class Kitchen
{
public:

  Kitchen();
  ~Kitchen();
  void useOven();
  void useStove();
  void releaseOven();
  void releaseStove();

private:

  pthread_mutex_t oven_mutex_;
  pthread_mutex_t stove_mutex_;
};

#endif
