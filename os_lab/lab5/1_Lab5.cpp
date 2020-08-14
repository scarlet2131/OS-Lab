#include<iostream>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<fstream>
#include <sstream>
#include <string>

using namespace std;

sem_t mutex,writeblock;
int writ = 0,reader_counter = 0,t,count=0;

int wF(){

  ofstream myfile;
  myfile.open ("ans.txt", std::ios_base::app);
  if(writ==0)
  myfile <<"Hey!!"<<endl;
  if(writ==1)
  myfile<<"Stronger are those who don't have option to be weak."<<endl;
  if(writ==2)
  myfile<<"And explore the unknown"<<endl;
  writ++;
  myfile.close();
  return 0;

}

void readFile(){

std::ifstream file("ans.txt");
    string str; 
    if(count==0)
		{

		if(getline(file, str))
		    cout << str<<endl;
		    
		    return;
}
     else{
			    string s;
			    while (std::getline(file, str))
			    
			    while (std::getline(file, s))
			    cout<<s<<endl;
			   
			   return;
			   	    
			    
		}
}

void *MyReader(void *arg)
{
  int f;

  sem_wait(&mutex);
  reader_counter = reader_counter + 1;
  if(reader_counter==1)
   sem_wait(&writeblock);
  sem_post(&mutex);
  printf("Data read by the MyReader 4 is\n");

  readFile();
   count++;
  sleep(1);
  sem_wait(&mutex);
  reader_counter = reader_counter - 1;
  if(reader_counter==0)
   sem_post(&writeblock);
  sem_post(&mutex);
}
void *MyReader5(void *arg)
{
  int f;

  sem_wait(&mutex);
  reader_counter = reader_counter + 1;
  if(reader_counter==1)
   sem_wait(&writeblock);
  sem_post(&mutex);
  printf("Data read by the MyReader 5 is\n");

  readFile();
   count++;
  sleep(1);
  sem_wait(&mutex);
  reader_counter = reader_counter - 1;
  if(reader_counter==0)
   sem_post(&writeblock);
  sem_post(&mutex);
}

void *writer(void *arg)
{
  int f;
  sem_wait(&writeblock);
  cout<<"Thread 1 is writing into the file"<<endl;
  wF(); 
  sleep(1);
  sem_post(&writeblock);
}
void *writer2(void *arg)
{
  int f;
  sem_wait(&writeblock);
  cout<<"Thread 2 is writing into the file"<<endl;
  wF(); 
  sleep(1);
  sem_post(&writeblock);
}
void *writer3(void *arg)
{
  int f;
  sem_wait(&writeblock);
  cout<<"Thread 3 is writing into the file"<<endl;
  wF(); 
  sleep(1);
  sem_post(&writeblock);
}

int main()
{
  int b; 
 //thread_t rtid[5],wtid[5];
  pthread_t t1,t2,t3,t4,t5;
  sem_init(&mutex,0,1);
  sem_init(&writeblock,0,1);

  cout<<"Enter which thread should read first:"<<endl;
  cin>>t;
  pthread_create(&t1,NULL,writer,NULL);
	pthread_join(t1,NULL);
  pthread_create(&t2,NULL,writer2,NULL);
	pthread_join(t2,NULL);
  pthread_create(&t3,NULL,writer3,NULL);
	pthread_join(t3,NULL);
  pthread_create(&t4,NULL,MyReader,NULL);
		pthread_join(t4,NULL);
  pthread_create(&t5,NULL,MyReader5,NULL);
		pthread_join(t5,NULL);
 /*for(int i=0;i<3;i++){
    pthread_create(&wtid[i],NULL,writer,(void *)i);
	pthread_join(wtid[i],NULL);
	}
   
  
  for(int i=0;i<2;i++){
		  pthread_create(&rtid[i],NULL,MyReader,(void *)i);
		pthread_join(rtid[i],NULL);
  }
  
*/
/*
  for(int i=0;i<3;i++)
    
  for(int i=0;i<2;i++)
    */
  

  return 0;
}

