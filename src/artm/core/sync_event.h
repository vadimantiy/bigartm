// Copyright 2011 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: nadavs@google.com <Nadav Samet>

#ifndef SRC_ARTM_CORE_SYNC_EVENT_H_
#define SRC_ARTM_CORE_SYNC_EVENT_H_

#include "boost/thread/thread.hpp"
#include "boost/thread/condition_variable.hpp"
#include "boost/utility.hpp"

namespace artm {
namespace core {

// sync_event provides a mechanism for threads to wait for an event.
class SyncEvent : boost::noncopyable {
 public:
  SyncEvent();

  // Blocks the current thread until another thread calls signal().
  void wait();

  // Signals that the event has occured. All threads that called wait() are
  // released.
  void signal();

 private:
  bool ready_;
  boost::mutex mu_;
  boost::condition_variable cond_;
};

}  // namespace core
}  // namespace artm

#endif  // SRC_ARTM_CORE_SYNC_EVENT_H_
