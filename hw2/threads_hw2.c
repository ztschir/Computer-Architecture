#include <stdio.h>
#include <pthread.h>

void printThread(void *threadNumber){
   int count;
   for(count = 1; count <= 10; ++count){
      printf("%d: %d \n", (int)(threadNumber), count);
   }
}

int main(){
	pthread_t thread1, thread2, thread3;
	int t1 = 1;
	int t2 = 2;
	int t3 = 3;

	pthread_create(&thread1, NULL, (void *) &printThread, (void*) t1);
	pthread_create(&thread2, NULL, (void *) &printThread, (void*) t2);
   pthread_create(&thread3, NULL, (void *) &printThread, (void*) t3);


	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
   pthread_join(thread3, NULL);

	printf("All threads are finished\n");
   return 0;
}
