//Old Program using pthreads
//Illustrates the global problem


#include <pthread.h>//Obviously threads!
#include <stdlib.h>//general purpose functions, 
//including dynamic memory management, 
//random number generation, communication with the environment,
#include <unistd.h>//standard symbolic constants and types, 
//i.e. POSIX versions, etc....  such as sleep()
#include <stdio.h>//printf function

//A global variable both threads are trying to modify
int myglobal;

//The function utilized in its own thread
 void *thread_function(void *arg) {
  int i,j;
  for ( i=0; i<20; i++ ) {
    j=myglobal;
    j=j+1;
    printf(".");
    fflush(stdout);
    sleep(1);
    myglobal=j;
  }
  return NULL;
}

int main(void) {

  //Declare my thread and a counter
  pthread_t mythread;
  int i;

  //Start the thread
  if ( pthread_create( &mythread, NULL, thread_function, NULL) ) {
    printf("error creating thread.");
    abort();
  }
  
  //Continue with updating the global which the thread is doing as well
  for ( i=0; i<20; i++) {
    myglobal+=1;
    printf("o");
    fflush(stdout);
    sleep(1);
  }

  //Come back together
  if ( pthread_join ( mythread, NULL ) ) {
    printf("error joining thread.");
    abort();
  }

  //What the heck happened
  printf("\nmyglobal equals %d\n",myglobal);
  printf("Why not 40, both are incrementing?");

  //Time to exit
  exit(0);
}