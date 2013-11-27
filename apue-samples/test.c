
#include "apue.h"
#include <stdio.h>
#include <pthread.h>

pthread_t ntid;

void printids(const char *s){
  pid_t pid;
  pthread_t tid;
  pid=getpid();
  tid=pthread_self();
  //printf("%s pid %u tid %u (0x%x) \n", s, (unsigned int)pid, (unsigned int)tid, (unsigned int) tid);
  printf("%s  pid %u tid %08x \n", s, (unsigned int) pid, (unsigned int) tid);
}

void *thr_fn(void *arg){
  printids("new thread: ");
  return((void *) 0);
}

int main(void){
  printf("hello world\n");
  int err;
  err=pthread_create(&ntid, NULL, thr_fn, NULL);
  if(err!=0){
    printf("can't create thread");
  }
  printids("main thread:");
  sleep(1);
  exit(0);
}
