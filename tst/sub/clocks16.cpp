#include <iostream>
#include <time.h>
using namespace std;
 
timespec diff(timespec start, timespec end);
 
int main()
{
	timespec time1, time2;

	int x[1000];
	for(int i=0;i<1000;i++) x[i]=i+1;
	int s=5; // some scalar

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	for (int i = 0; i< 2000; i++)
		for(int j=999;j>=0;j-=16)
		{
			x[j]=x[j]+s;
			x[j-1]=x[j-1]+s;
			x[j-2]=x[j-2]+s;
			x[j-3]=x[j-3]+s;
			x[j-4]=x[j-4]+s;
                        x[j-5]=x[j-5]+s;
                        x[j-6]=x[j-6]+s;
                        x[j-7]=x[j-7]+s;
			x[j-8]=x[j-8]+s;
                        x[j-9]=x[j-9]+s;
                        x[j-10]=x[j-10]+s;
                        x[j-11]=x[j-11]+s;
			x[j-12]=x[j-12]+s;
                        x[j-13]=x[j-13]+s;
                        x[j-14]=x[j-14]+s;
                        x[j-15]=x[j-15]+s;
		}
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout<<(diff(time1,time2).tv_sec/2000000)<<":"<<(diff(time1,time2).tv_nsec/2000000)<<endl;
	return 0;
}
 
timespec diff(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}
