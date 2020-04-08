#include "../../../types.h"
#include "../../../stat.h"
#include "../../../user.h"
#include "test_signal.h"

/**
* variable used in the test
*/
sig_atomic_t i = 0;

/**
 * signal handler that exits
 * @param sig the signal being raised
 */
void test(int sig) {
  exit();
}

/**
 * signal handler that increments and prints out the variable i
 * and exit when i reaches 10
 * @param sig the signal being raised
 */
void test2(int sig) {
  i++;
  printf(1, "Need to press %d more\n", 10 - i);
  if (i == 10) {
    exit();
  }
}

/**
 * test the handler
 * sets the exit handler and then block
 */
void test_handler() {
  signal(SIGINT, test);
  for (;;) {
  }
}

/**
 * test the kill2
 * child will block
 * parent will sleep for some time and use kill2 to send the SIGTERM to the
 * child process, the child process will then exit once the signal is fulfilled
 */
void test_kill2() {
  int pid;
  if ((pid = fork()) == 0) {
    for (;;) {
    }
  } else {
    sleep(100);
    if (kill2(pid, SIGTERM) < 0) {
      printf(1, "kill 2 failed\n");
    } else {
      printf(1, "kill 2 success\n");
    }
    wait();
  }
}

/**
 * test the SIG_DFL handler
 * the signal should return the last signal handler
 */
int test_signal_DFL() {
  void(*prev)(int) = signal(SIGINT, test);
  signal(SIGINT, SIG_DFL);
  void(*dfl)(int) = signal(SIGINT, test);
  signal(SIGINT, SIG_DFL);
  if (prev == dfl) {
    return 1;
  }
  return 0;
}

/**
 * test the SIG_IGN handler
 * the SIGINT signal should be ignored
 */
void test_signal_IGN() {
  int pid;
  if ((pid = fork()) == 0) {
    signal(SIGINT, SIG_IGN);
    for (;;) {
    }
  } else {
    sleep(100);
    if (kill2(pid, SIGINT) < 0) {
      printf(1, "kill 2 failed\n");
    }
    sleep(500);
    kill2(pid, SIGTERM);
    wait();
  }
}

/**
 * the child process will set up the signal handler and raise the signal
 * then block
 * @return
 */
int test_signal_handler(){
  if (fork() == 0) {
    signal(SIGINT, test);
    raise(SIGINT);
    for(;;);
  } else {
    wait();
  }
  return 1;
}

/**
 * the test2 handler will count how many times the SIGINT has been triggered
 * once there are 10 triggers, the handler will exit, use control + c to
 * trigger the console to send SIGINT
 * @return
 */
int test_sig_atomic_t(){
  if (fork() == 0) {
    signal(SIGINT, test2);
    for (;;);
  } else {
    wait();
  }
  return 1;
}
