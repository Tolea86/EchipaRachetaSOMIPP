# Copyright 2017 Alexei Sersun <alex.sersun@yahoo.com>

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#     http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

CXX=g++
RM=rm -f
CPPFLAGS = -std=c++11 -g -Wall -Werror
SRCS=$(wildcard ./*.cpp)
OBJS=$(subst .cpp,.o,$(SRCS))
TARGET = a.out

all: restaurant

restaurant: $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJS)
	clear
	./$(TARGET)

depend: .makefile

.makefile: $(SRCS)
	$(RM) ./.makefile
	$(CXX) $(CPPFLAGS) -MM $^>>./.makefile;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .makefile

include .makefile