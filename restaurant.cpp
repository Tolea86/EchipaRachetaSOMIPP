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

#include "restaurant.h"
#include <unistd.h>
#include <iostream>
#include "cook.h"
#include "waiter.h"

using namespace std;

OrderMonitor order_monitor = OrderMonitor(maxNumberClients);
Menu menu;
Kitchen kitchen;
StarCounter star_counter;
Bundle bundle = Bundle(order_monitor, menu, kitchen, star_counter);

int main()
{
  srand(time(NULL));

  Waiter waiter_1(bundle);
  Waiter waiter_2(bundle);

  Cook cook_1(bundle, "", "", 3, 3);
  Cook cook_2(bundle, "", "", 3, 3);
  Cook cook_3(bundle, "", "", 2, 3);
  Cook cook_4(bundle, "", "", 1, 3);
  Cook cook_5(bundle, "", "", 1, 3);
  Cook cook_6(bundle, "", "", 1, 3);

  waiter_1.start();
  // waiter_2.start();

  cook_1.start();
  cook_2.start();
  cook_3.start();
  cook_4.start();
  cook_5.start();
  cook_6.start();

  usleep(durationOfSimulation * timeMeasurementUnit);

  waiter_1.cancel();
  waiter_2.cancel();

  cook_1.cancel();
  cook_2.cancel();
  cook_3.cancel();
  cook_4.cancel();
  cook_5.cancel();
  cook_6.cancel();

  cout << "\n\nAverage number of stars: " << star_counter.average() << endl;

  return 0;
}
