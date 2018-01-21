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

#include "kitchen.h"

Kitchen::Kitchen()
{
  pthread_mutex_init(&stove_mutex_, NULL);
  pthread_mutex_init(&oven_mutex_, NULL);
}

Kitchen::~Kitchen()
{
  pthread_mutex_destroy(&oven_mutex_);
  pthread_mutex_destroy(&stove_mutex_);
}

void Kitchen::useOven()
{
  pthread_mutex_lock(&oven_mutex_);
}

void Kitchen::useStove()
{
  pthread_mutex_lock(&stove_mutex_);
}

void Kitchen::releaseOven()
{
  pthread_mutex_unlock(&oven_mutex_);
}

void Kitchen::releaseStove()
{
  pthread_mutex_unlock(&stove_mutex_);
}
