#include<iostream>
#include<algorithm>
typedef struct{
	int id;
	int arr;
	int ser;
	int fin;//finished time
	bool flag=0;
}process;
bool cmp(process a,process b){ //按照抵达时间排序，从而找出当前时间的最短job
	return a.arr<b.arr;
}
bool cmp2(process a,process b){ //按照id排序 ，符合输出格式
	return a.id<b.id;
}
int sjf(int x,int y[],int z[]) {
process * p= new process[x+1];
for (int i=1;i<=x;i++){
	p[i].id=i;
	p[i].arr=y[i];
	p[i].ser=z[i];
}
int check=0;
std::sort((p+1),(p+x+1),cmp);
int time=p[1].arr;
for (int i=1;i<=x;i++){
	int check=1;//从1开始检查
int	min=10000;//每次循环最大化 最小值
int minn;//最短作业对应的id
while (p[check].arr<=time){//查看当前时间最小作业
   if( (p[check].ser<min)and (p[check].flag==false)){ 
    min=p[check].ser;
	minn=p[check].id;
	}
		   check++;
}
time +=p[minn].ser;

p[minn].fin=time;

//std::cout<<"id:"<<p[minn].id<<" finish:"<<(p[minn].fin)<<" minn"<<minn<<std::endl;
p[minn].flag=true;
}
	std::sort((p+1),(p+x+1),cmp2);
	double averu,averw;
	for (int i=1;i<=x;i++){
	std::cout<<"id:"<<p[i].id<<" finished time:"<<p[i].fin<<" used time:"<<p[i].fin-p[i].arr<<" weighted:"<<((p[i].fin-p[i].arr)/(float)(p[i].ser))<<std::endl;
averu+=((p[i].fin-p[i].arr)/float(x));
averw+=((p[i].fin-p[i].arr)/(float)(p[i].ser))/x;
	}
printf("Average used time:%f Average weighted time:%f   \n",averu,averw);
	return 0;
}



int fcfs(int x,int y[],int z[]) {
	int time=0;
	int * start=new int [x+1];//开始服务时间
	float * used= new float [x+1];
	float*  weighted= new float [x+1];
	for(int i=1;i<=x;i++) {	

		printf("Number: %d ", i);
		*(start+i)=time;
		time+=*(z+i);
		(used[i])=time-*(y+i);
		*(weighted+i)=*(used+i)/((float)*(z+i));
		std::cout<<"Finish time"<<time<<" Running time:"<<used[i]<<" Weighted:"<<weighted[i]<<std::endl;
	}
	for (int i=1;i<=x;i++) {
		used[0]+= used[i]/x;
		weighted[0]+=weighted[i]/(float)x;
		}
std::cout<<"Average"<<used[0]<<" Weighted:"<<weighted[0];
//printf("\n   test %f",weighted[1]); //TESTTTTTTTTT
	return 0;
	
}

int main() {
int n;//输入数据 进程数n
printf("Number of pcb: n =");
scanf("%d",&n);
int * arrival = new int [n+1];//到达时间
int * service=new int [n+1];//服务时间
printf("Arrival time:");
for (int i=1;i<=n;i++) {
	scanf("%d",arrival+i);
} 
printf("Service time:");
for (int i=1;i<=n;i++) 
 scanf("%d",service+i);
printf("Print ONE NUMBER you want to choose 1.fcfs 2.sjf \n");
int a;
scanf("%d",&a);
switch(a) {
case 1:fcfs(n,arrival,service);
break;
case 2:sjf(n,arrival,service);
break;
}
}

