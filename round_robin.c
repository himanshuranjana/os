#include<stdio.h>
struct Process{
	int P;
	int AT;
	int BT;
	int tempBT;
	int TAT;
	int WT;
	int completed;
};

int main(){
	int size;
	printf("Enter the number of process: ");
	scanf("%d", &size);
	struct Process process[size];
	for(int i=0; i<size; i++){
		process[i].P = i+1;
		printf("P%d Arrival Time: ", i+1);
		scanf("%d", &process[i].AT);
		printf("P%d Burst Time: ", i+1);
		scanf("%d", &process[i].BT);
		process[i].WT = 0;
		process[i].TAT= 0;
		process[i].completed = 0;
		process[i].tempBT = process[i].BT;
	}
	int quantum;
	printf("\n\ninput Quantum: ");
	scanf("%d", &quantum);
	
	printf("P\t\tAT\t\tBT\n");
	for(int i=0; i<size; i++){
		printf("P%d\t\t%d\t\t%d\n", process[i].P, process[i].AT, process[i].BT);
	}
	
	for(int i=0; i<size; i++){
		for(int j=i; j<size; j++){
			if(process[i].AT > process[j].AT){
				struct Process temp=process[i];
				process[i]=process[j];
				process[j]=temp;
			}
		}
	}
	printf("\n\nP\t\tAT\t\tBT\n");
	for(int i=0; i<size; i++){
		printf("P%d\t\t%d\t\t%d\n", process[i].P, process[i].AT, process[i].BT);
	}
	int time=0;
	int completeCount=0;
	while(1){
		for(int i=0; i<size; i++){
			if(process[i].tempBT==0) continue;
			if(process[i].tempBT<quantum || process[i].tempBT==quantum){
				time+=process[i].tempBT;
				process[i].tempBT=0;
				process[i].TAT=time-process[i].AT;
				completeCount+=1;
			}
			else{
				process[i].tempBT-=quantum;
				time+=quantum;
			}
		}
		if(completeCount==size) break;
	}
	
	float avgTAT=0;
	float avgWT=0;
	for(int i=0; i<size; i++){
		process[i].WT=process[i].TAT-process[i].BT;
		avgTAT+=process[i].TAT;
		avgWT+=process[i].WT;
	}
	avgTAT/=size;
	avgWT/=size;
	
	printf("\n\nP\t\tAT\t\tBT\t\tWT\t\tTAT\n");
	for(int i=0; i<size; i++){
		printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i].P, process[i].AT, process[i].BT, process[i].WT, process[i].TAT);
	}
	printf("\n\nAverage Turnaround Time is: %f", avgTAT);
	printf("\nAverage Waiting Time is: %f\n\n", avgWT);
}
