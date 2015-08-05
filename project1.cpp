#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;


class Job {
private:
	int startTime, size;
public:
	int id;

	Job(int,int,int);
	int decSize();
	int getStart();
	int getSize();
};

void insertSort(Job**,Job*);

int main(int argc, char *argv[]){
	int cTime = 0, completion = 0;  // current time
	int numInstr, tStart, tSize, instr, best_index, best_finish;

	bool done;

	Job *tmp;
	Job *jobs[256]; // array for jobs

	for(int i=0;i<256;i++)
		jobs[i] = NULL;

	cin >> numInstr;
	for(int i=0;i<numInstr;i++){
		cin >> instr;
		cin >> tStart;
		cin >> tSize;

		tmp = new Job(tStart,tSize,instr);
		insertSort(jobs,tmp);
	}
	while(true){
		for (int i = 0; jobs[i] != NULL; i++){
			if(jobs[i]->getSize() > 0){
			//cout << "Job " << jobs[i]->id << "is not done";
				done = false;
				break;
			}
			done = true;
		}
		if(done)
			break;


		best_finish = -1;
		for(int i=0; jobs[i] != NULL && jobs[i]->getStart() <= cTime;i++){
			if(jobs[i]->getSize() < 1)
				continue;
			else {
				if(best_finish == -1){
					best_finish = jobs[i]->getSize() + cTime;
					best_index = i;
				}

				if(best_finish >= jobs[i]->getSize() + cTime){
					best_finish = jobs[i]->getSize() + cTime;
					best_index = i;
				}
			}
		}
		if(best_finish == -1){
			cTime++;
			continue;
		}

		jobs[best_index]->decSize();
		cTime++;
		if(jobs[best_index]->getSize() == 0){
			completion += cTime;
		}
		cerr << jobs[best_index]->id << endl;
	}

	cout << completion;
}


Job::Job(int sTime, int tSize, int tId){
	startTime = sTime;
	size = tSize;
	id = tId;
}
int Job::decSize(){
	size--;
	return size;
}
int Job::getSize(){
	return size;
}
int Job::getStart(){
	return startTime;
}

void insertSort(Job** jobs, Job* newJob){
	int i;
	Job* tmp;
	if(jobs[0] == NULL){
		jobs[0] = newJob;
		return;
	}
	for(i=0;jobs[i] != NULL;i++){
		if(jobs[i]->getStart() < newJob->getStart())
			continue;
		else if(jobs[i]->getStart() == newJob->getStart()){	
	        // take job with earliest finish time
			if(jobs[i]->getSize() < newJob->getSize())
	            		continue;
			else{
		            	tmp = jobs[i];
		            	jobs[i] = newJob;
		            	newJob = tmp;
			}

		}
		else{
			tmp = jobs[i];
			jobs[i] = newJob;
			newJob = tmp;
		}
	}
	jobs[i] = newJob;
}