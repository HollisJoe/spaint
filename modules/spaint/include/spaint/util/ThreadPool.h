/**
 * spaint: ThreadPool.h
 * Copyright (c) Torr Vision Group, University of Oxford, 2016. All rights reserved.
 */

#ifndef H_SPAINT_THREADPOOL
#define H_SPAINT_THREADPOOL

#include <string>

#include <boost/asio.hpp>
#include <boost/thread.hpp>

namespace spaint {

/**
 * \brief This class represents a pool of threads that can be used to asynchronously execute
 *        arbitrary functions.
 */
class ThreadPool
{
  //#################### PUBLIC STATIC MEMBER FUNCTIONS ####################
public:
  static ThreadPool& instance();

  ~ThreadPool();

  template<typename F>
  void start_asynch(F task)
  {
    m_scheduler.post(task);
  }

private:
  ThreadPool();

  // Kill copy and assignment operations
  ThreadPool(const ThreadPool &);
  const ThreadPool& operator=(const ThreadPool &);


  //#################### MEMBER VARIABLES ####################
private:
  boost::asio::io_service m_scheduler;
  boost::asio::io_service::work m_worker;

  boost::thread_group m_threadpool;

};

}

#endif
