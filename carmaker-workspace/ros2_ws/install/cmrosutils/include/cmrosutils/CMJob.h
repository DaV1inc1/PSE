/*!
 * @file CMJob.h
 * @author Fabian Häußler
 *
 * @brief Library for providing a generic interface to handle jobs
 */

#pragma once

#include <atomic>
#include <chrono>
#include <functional>
#include <memory>
#include <vector>

namespace CMJob {

/*!
 *  \addtogroup CMJob
 *  @{
 */

/*!
 * \enum JobType
 *
 * These are the available job types
 *
 * \anchor JobType
 */
enum class JobType {
  Cyclic,  ///< called periodically at the end of the job
  Trigger  ///< called immediately
};

/*!
 * \enum JobState
 *
 * These are the states of the statemachine
 *
 * \anchor JobState
 */
enum class JobState { New, Active, Ready, Idle, Suspended, Timeout, Disabled };

/*!
 * These callback hooks are used within the scheduler for executing the job
 * function at a certain position
 *
 * \anchor CallbackHook
 */
enum class CallbackHook {
  Manual = -1,
  StartCycle,  ///< associated jobs are executed automatically in \p
               ///< startCycle()
  In,
  DrivMan,
  Traffic,
  VehicleControl,
  Brake,
  Calc,
  Out,
  EndCycle,  ///< associated jobs are executed automatically in \p
             ///< startCycle()
  User1 = 32,
  User2,
  User3,
  User4,
  User5
};
/*! @} */

/*!
 * The AbstractJob class provides an interface for jobs
 */

class AbstractJob {
 public:
  /*!
   * AbstractJob
   *
   * \param name is the job name
   * \param type is the type Cyclic or Trigger
   * \param sync is the flag if the job should get syncronized
   */
  AbstractJob(const std::string& name, JobType type, bool sync);
  virtual ~AbstractJob();

  /* Configuration */
  /* Can only be set, when the job is in state JobState::New */

  /*!
   * Sets the cycle time of the job.
   * (e.g. job is called every 100 cycles)
   *
   * \param[in] cycle
   */
  void setCycleTime(unsigned long cycle);

  /*!
   * Sets the cycle offset within the cycle time of the job.
   * (e.g. job is called every 100 cycles + 50 cycles)
   *
   * \param[in] cycle (default = 0)
   */
  void setCycleOffset(unsigned long cycle);

  /*!
   * Sets the timeout time for syncronizazion jobs.
   * (e.g. scheduler waits for 5s for the job \p preparation() until it gets
   * timedout)
   *
   * \param[in] time_s in seconds (default = infinite)
   */
  void setTimeoutTime(double time_s);

  /*!
   * Sets the count on how often the job is executed.
   *
   * \param[in] count (default = infinite)
   */
  void setExecutionCounter(int count);

  /*!
   * Sets the count on how many job cycles are skipped in the beginning.
   *
   * \param[in] count (default = 0)
   */
  void skipFirstCycles(unsigned count);

  /*!
   * Sets the callback hock for when the job gets executed by the scheduler.
   *
   * \param[in] hook (default = In)
   */
  void setCallbackHook(CallbackHook hook);

  /* State machine */

  /*!
   * Initialization of the job
   *
   * Function init() **can** be provided in the inherited class.
   * Then AbstractJob::init() has to be called.
   *
   * Use it to
   *   - set default job settings
   *   - external initialization
   */
  virtual void init();

  /*!
   * Activation of the job
   *
   * Function activate() **can** be provided in the inherited class.
   * Then AbstractJob::activate() has to be called.
   *
   * Use it to
   *   - activate an idle job
   *   - reset variables
   */
  virtual void activate();

  /*!
   * Preperation of the job
   *
   * Function prepare() **can** be provided in the inherited class.
   * Then AbstractJob::prepare() has to be called.
   *
   * Useful when you use a cyclic job, because then the execution is scheduled
   * and uses data provided by this function
   *
   * Use it to
   *   - update variables used for execution
   */
  virtual void prepare();

  /*!
   * Execution of the job
   *
   * Function execute() **has** to be provided in the inherited class.
   * Then AbstractJob::execute() has to be called.
   *
   * Use it to
   *   - call the job functionality
   */
  virtual void execute() = 0;

  /*!
   * Suspension of the job
   *
   * Function suspend() **can** be provided in the inherited class.
   * Then AbstractJob::suspend() has to be called.
   *
   * Use it to
   *   - suspend a job, which doesn't meet certain criteria
   */
  virtual void suspend();

  /*!
   * Putting job into timeout
   *
   * Function timeout() **can** be provided in the inherited class.
   * Then AbstractJob::timeout() has to be called.
   */
  virtual void timeout();

  /*!
   * Disable the job
   *
   * Function disable() **can** be provided in the inherited class.
   * Then AbstractJob::disable() has to be called.
   *
   * Use it to
   *   - disable the job
   */
  virtual void disable();

  /*!
   * Reset the job
   *
   * Function reset() **can** be provided in the inherited class.
   * Then AbstractJob::reset() has to be called.
   *
   * Use it to
   *   - reset the job ( AbstractJob::init() gets called )
   */
  virtual void reset();

  /* Job functions */

  /*!
   * \brief Set Job ID
   * \param id
   */
  void setID(size_t id) const;

  /*!
   * Prints job details
   *
   * Prints name, cycletime and cycleoffset
   */
  void info() const;

  /*!
   * Function returns if the job is scheduled at \p cycle
   *
   * \param[in] cycle
   * \return bool if job is scheduled
   */
  bool isJobScheduled(unsigned long cycle) const;

  /*!
   * Function checks if current callback is scheduled at \p cycle
   *
   * \param[in] cycle
   * \return bool if callback is scheduled
   */
  bool isCallbackScheduled(unsigned long cycle) const;

  /*!
   * Funktion checks if the job is timedout
   *
   * \return bool if job is in timeout
   */
  bool isJobTimeout() const;

  /* Getter */
  std::string getJobName() const;
  unsigned long getCycleTime() const;
  unsigned long getCycleOffset() const;
  bool isSynchronized() const;
  unsigned long getCycle() const;

  JobType getJobType() const;
  std::string getJobTypeName() const;

  CallbackHook getCallbackHook() const;
  std::string getCallbackHookName() const;

  JobState getJobState() const;
  std::string getJobStateName() const;

  /* Setter */

  /*!
   * Sets the current cycle of the simulation for internal usage
   *
   * \param[in] cycle of the current simulation
   */
  void setCycle(unsigned long cycle);

  /*!
   * Sets a job name instead of the argument in constructor
   *
   * with the same argument in the constructor, there can be multiple jobs
   * with the same name.
   *
   * \param[in] name of the new job
   */
  void setJobName(const std::string& name);

 protected:
  /* State setters */
  void setReady();
  void setIdle();
  void setActive();
  void setSuspended();
  void setTimeout();
  void setDisabled();

 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

/*!
 * The singleton JobScheduler class handles \p AbstractJobs
 */

class JobScheduler {
 public:
  /*!
   * Initialization of the singleton
   *
   * \return singleton instance of the class JobScheduler
   */
  static JobScheduler& instance() {
    static JobScheduler instance;
    return instance;
  }

  /*!
   * Updates the current cycle time of all registered jobs and executes jobs
   * with the \p CallbackHook::StartCycle callback hook.
   *
   * Use it in the beginning of the simulation cycle
   */
  void startCycle();

  /*!
   * Function returns the current cycle time of the scheduler
   *
   * \return Current relative cycle number
   */
  unsigned long getCycle() const;

  /*!
   * Locks the simulation, when a job is suspended and releases
   * it, when this job gets prepared() within \p fptr()
   *
   * Use it in the beginning of the simulation cycle after \p startCycle()
   *
   * \param[in] fptr function pointer, which prepares the suspended job to be
   * ready
   *
   * \param[in] microseconds duration in microseconds the locking mechanism
   * should wait until \p fptr() is called again (default = 10)
   */
  void lock(const std::function<void(void)>& fptr,
            unsigned int microseconds = 10) const;

  /*!
   * AddJob adds the job to the internal job container to handle it
   *
   * \param job has to be a derived class of AbstractJob
   * \param priority sets the priority the jobs are getting executed.
   *        Jobs with high priority are getting executed earlier.
   *
   * \return unique identifier for added job
   */
  size_t addJob(const std::shared_ptr<AbstractJob>& job, size_t priority = 1);

  /*!
   * The function iterates through all jobs and checks if they are ready, if not
   * the function suspends them
   *
   * \return bool, if all jobs are ready at current timestamp
   */
  bool areJobsReady() const;

  /*!
   * The function iterates through all jobs and checks if they are
   * timedout
   *
   * \return bool, if any job is in overtime
   */
  bool areJobsTimeout() const;

  /*!
   * Executes jobs at the defined hook point
   *
   * Use it in every function you want to execute jobs
   *
   * \param[in] hook
   */
  void executeJobs(CallbackHook hook);

  /*!
   * Activates idle jobs, increments the current cycle time of the scheduler and
   * executes jobs with the \p CallbackHook::EndCycle callback hook.
   *
   * Use it in the end of the simulation cycle
   */
  void endCycle();

  /*!
   * Iterates through all jobs, sets them all to active and resets the internal
   * cycles
   *
   * Use it before the simulation starts
   */
  void resetJobs();

  /*!
   * Iterates through all jobs and sets them all to disabled
   *
   * Use it after the simulation
   */
  void disableJobs();

  /*!
   * Removes all jobs from the scheduler
   */
  void deleteJobs();

  /*!
   * Removes a specific job from the scheduler
   *
   * \param[in] name of the job
   */
  void deleteJob(const std::string& name);

  /*!
   * Removes a specific job from the scheduler
   *
   * \param[in] id of the job
   */
  void deleteJob(size_t id);

  /*!
   * Returns the job
   *
   * \param name of the job
   * \return reference to the job
   */
  std::shared_ptr<CMJob::AbstractJob> getJob(const std::string& name) const;

  /*!
   * Returns the job
   *
   * \param id of the job
   * \return reference to the job
   */
  std::shared_ptr<CMJob::AbstractJob> getJob(size_t id) const;

  /*!
   * Prints all jobs from the scheduler
   */
  void printJobs() const;

 private:
  JobScheduler();
  ~JobScheduler();

  JobScheduler(const JobScheduler&);
  JobScheduler& operator=(const JobScheduler&);

  struct Impl;
  std::unique_ptr<Impl> impl_;
};

/*!
 * The Log class
 *
 * This is a wrapper to register CarMaker Log functions.
 * If no CarMaker Log function is registered, it uses the std::cout output
 * stream
 */
class Log {
 public:
  /* set CM Log */
  static void setLog(void (*pLog)(const char* format, ...));
  static void setLogWarn(void (*pLogWarn)(unsigned ECId, const char* format,
                                          ...));
  static void setLogErr(void (*pLogErr)(unsigned ECId, const char* format,
                                        ...));

  /* Use these, if you want to print output depending on the registered output
   * stream */
  static void printLog(const std::string& out);
  static void printWarn(unsigned ECId, const std::string& out);
  static void printError(unsigned ECId, const std::string& out);

 private:
  static void (*cm_log)(const char* format, ...); /*! Log callback */
  static void (*cm_log_warn_f)(unsigned ECId, const char* format,
                               ...); /*! LogWarn callback */
  static void (*cm_log_err_f)(unsigned ECId, const char* format,
                              ...); /*! LogErr callback */
};

}  // namespace CMJob
