#include<bits/stdc++.h>
#include<fstream>
using namespace std;
struct semaphore 
{
int value;
bool wrt;
int readcount;
int mutex; 
};

wait( semaphore *s)
{
	s->value--;
	if(s->value<0)
	{
		add(s->value);
		block();
	}
}
signal( semaphore *s)
{
	s->value++;
	if(s->value<=0)
	{
		remove(p);
		wakeup(p)
	}
}
void *write_f(void *)
{
	ofstraem fout;
	string line;
	fout.open("red_write.txt");
	while(fout)
	{
		getline(cin,line);
		if(line=="-1")
		{
			break;
		}
		fout<<line<<endl;
	}
	fout.close();
}
void * read_f(void *)
{
	ifstream fin;
	fin.open("red_write.txt");
	while(fin)
	{
		getline(fin,line);
		cout<<line<<endl;
	}
	fin.close();
}
int main()
{
	pthread_t t1,t2,t3,t4,t5; 
  
        pthread_create(&t1, NULL, write_f,NULL); 
	pthread_join(t1,NULL);
	 pthread_create(&t2, NULL, write_f,NULL); 
	pthread_join(t2,NULL);
	 pthread_create(&t3, NULL, write_f,NULL); 
	pthread_join(t3,NULL);
	pthread_create(&t4, NULL, read_f,NULL);
    pthread_exit(NULL); 
    pthread_create(&t5, NULL,read_f,NULL);
    pthread_exit(NULL); 
	int wrt=1,readcount=0;
	int mutex=1; 
	
	do {
             wait (wrt) ;
                
            //    writing is performed

                signal (wrt) ;
        } while (TRUE);


        do {
                       wait (mutex) ;
                       readcount ++ ;
                       if (readcount == 1)  
			          wait (wrt) ;
                       signal (mutex)
                                               // reading is performed
                        wait (mutex) ;
                        readcount  - - ;
                        if (readcount  == 0)  
			         signal (wrt) ;
                        signal (mutex) ;
              } while (TRUE);


              return 0; 

}
