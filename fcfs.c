#include<stdio.h>
int main(){
	printf("Input the no. of processes: ");
	int n=0;
	scanf("%d", &n);
	
	int process[n][5];
	printf("\nEnter %d process details\n",n);
	for(int i=0; i<n; i++){
		printf("P%d Burst Time: ", i+1);
		scanf("%d",&process[i][0]);
		printf("P%d Arrival Time: ", i+1);
		scanf("%d",&process[i][1]);
	}
	
	for(int i=0; i<n; i++){
		printf("P%d Burst Time: %d\n", i+1,process[i][0]);
		printf("P%d Arrival Time: %d\n", i+1,process[i][1]);
	}
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(process[i][1]>process[j][1]){
				int tempBT=process[i][0];
				int tempAT=process[i][1];
				
				process[i][0]=process[j][0];
				process[i][1]=process[j][1];
				
				process[j][0]=tempBT;
				process[j][1]=tempAT;
				
			}
		}
	}

	int wt=process[0][1]+process[0][0];
	process[0][2]=0;
	for(int i=1; i<n; i++){
		int cwt=wt-process[i][1];
		process[i][2]=cwt;
		wt+=process[i][0];
	}
	for(int i=0; i<n; i++){
		int tt=process[i][0]+process[i][2];
		process[i][3]=tt;
	}
	
	//	printf("\n\nAfter sorting as per AT\n");
	printf("Process\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
	printf("-------------------------------------------------------------------------\n");
	for(int i=0; i<n; i++){
		printf("  P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1,process[i][0], process[i][1], process[i][2], process[i][3]);
	}
	
	float totalWT=0, totalTT=0;
	for(int i=0; i<n; i++){
		totalWT+=process[i][2];
		totalTT+=process[i][3];
	}
	float avgWT, avgTT;
	avgWT=totalWT/n;
	avgTT=totalTT/n;
	
	printf("\n\nAverage Waiting Time: %f",avgWT);
	printf("\nAverage Turnaround Time: %f\n\n", avgTT);
	
	return 0;
}