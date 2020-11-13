import java.util.Scanner;
public class osbank {
public static void main(String args[]) {
int n;//输入数据 进程数n
Scanner sc=new Scanner(System.in);
n=sc.nextInt();
int arrival[] = new int [n+1];//到达时间
int service[]=new int [n+1];//服务时间
for (int i=1;i<=n;i++) {
	arrival[i]=sc.nextInt();
} 
for (int i=1;i<=n;i++) service[i]=sc.nextInt();
System.out.println("Print ONE NUMBER you want to choose 1.fcfs 2.sjf");
switch(sc.nextInt()) {
case 1:fcfs(n,arrival,service);
break;
case 2:sjf(n,arrival,service);
break;
}
}

public static void sjf(int x,int y[],int z[]) {

	
	
}



public static void fcfs(int x,int y[],int z[]) {
	int time=0;
	int start[]=new int [x+1];//开始服务时间
	float used[]= new float [x+1];
	float weighted[]= new float [x+1];
	for(int i=1;i<=x;i++) {	
		System.out.print("进程号: "+ i +" ");
		start[i]=time;
		time+=z[i];
		used[i]=time-y[i];
		weighted[i]=used[i]/(float)(z[i]);
		System.out.println("完成时间: "+time+" 周转时间:"+used[i]+" 带权周转:"+weighted[i]);
	}
	for (int i=1;i<=x;i++) {
		used[0]+= used[i]/x;
		weighted[0]+=weighted[i]/(float)x;
		}
	System.out.println("平均周转时间:"+used[0]+" 平均带权周转时间: "+weighted[0]);
	
	
}

}
