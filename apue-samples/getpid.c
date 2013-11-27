
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

//#define PATH_MAX             1024  

int main(){
  int static_var;
  static_var=7;
  int pid;
  int fOUT;
  pid=getpid();
  printf("hello world %i\n", pid);


  char filename[PATH_MAX];
  snprintf(filename, sizeof(filename), "hello-world-%d.txt", pid);


  //char[] filename;
  //char* filename=sprintf("hello-world-%i.txt", pid);
  //char* filename="here.txt";
  fOUT= open (filename, O_RDWR | O_CREAT | O_SYNC);

  //fOUT= open ("test-1.txt", O_RDWR | O_CREAT | O_SYNC);
  write (fOUT, "hello", 4);
  close(fOUT);

  int new_pid;
  if((new_pid=fork()) < 0){
    printf("there was an error\n");
  }else if(new_pid==0){
    printf("you are 0\n");
  }else{
    static_var++;
    sleep(2);
    printf("no error\n");
  }
  

  printf("pid %i and new_pid %i and static_var %i \n", pid, new_pid, static_var);
  //printf("new_pid %i \n", new_pid);
  return pid;
}
