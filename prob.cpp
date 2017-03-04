#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("question.txt");
	double median;
	char choice;
	int n;
	cout <<"Enter Sample size: "<<endl;
	cin>> n;
	double hold;
	double v[n];
	int k=1;
	while(!fin.eof())
	{
		fin>>v[k];
		k++;
	}
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	double mean;
	double sum=0;
	for(int i=0;i<n;i++)
	{
		sum = sum+  v[i];
	}
	cout<<"Sum: "<<sum<<endl;
	mean=sum/n;
	cout<<"Mean: "<<mean<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(v[j]<v[j+1])
			{
				double temp = v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
	cout<<endl;
	if(n%2==0)
	median = (v[n/2]+v[(n+2)/2])/2;
	else
	median = (v[(n+1)/2]);
	double Q1,Q2,Q3;
	Q3 = v[(n/4)];
	Q2 = median;
	Q1 = v[((3*n)/4)];
	cout<<"Q3: "<<Q1<<endl;
	cout<<"Median(Q2): "<<median<<endl;
	cout<<"Q1: "<<Q3<<endl;
	double IQR,minbound,maxbound;
	IQR = Q3-Q1;
	minbound = Q1-((1.5)*IQR);
	maxbound = Q3+((1.5)*IQR);
	cout<<"IQR: "<<IQR<<endl;
	cout<<"Minimum Bound: "<<minbound<<endl;
	cout<<"Maximum Bound: "<<maxbound<<endl;
	sum=0;
	cout<<"Xi"<<setw(5)<<"-"<<setw(5)<<"X"<<setw(10)<<"Xi-X"<<setw(10)<<"(Xi-X)^2"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<setw(5)<<"-"<<setw(7)<<mean<<setw(5)<<"="<<setw(5)<<v[i]-mean<<setw(7)<<"     "<<(v[i]-mean)*(v[i]-mean)<<endl;
		sum = sum+  ((v[i]-mean)*(v[i]-mean));
	}
	cout<<"Sum:"<<setw(27)<<sum<<endl;
	double var;
	var = (sum)/(n-1);
	double std;
	std = sqrt(var);
	cout<<"variance : "<< var;
	cout<<endl << "std : "<<std;
	double min = 1000000;
	double max = -1;
	for(int i=0;i<n;i++)
	{
		if(min>v[i])
		min=v[i];
		if(max<v[i])
		max=v[i];
	}
	cout<<endl<<"Maximum = "<<max<<endl;
	cout<<"Minimum = " <<min<<endl;
	double range = max-min;
	cout<<"Range = " <<range<<endl;
	int Noofinterval;
	cout<<endl<<"Enter Number of Intervals: "<<endl;
	cin>>Noofinterval;
	double num = 1.8;
	double no=0;
	int arr[Noofinterval];
	for(int i=0;i<Noofinterval;i++)
	{
		arr[i]=0;
	}
	int count =0;
	num =1.7;
	double midpoint,fm,lm,l,hm,c,cf=0,m,fx,sumf=0,sumfx=0,ffx;
	double mi,ma;
	ma = max;
	mi = min;		
	while(no <max)
	{
		no = min + num;  
		for(int i=0;i<n;i++)
		{
			if(v[i]>=min&&v[i]<=no)
			{
				arr[count]++;
			}
		}
		c = cf;
		cf = cf + arr[count];
		midpoint = (min + no)/2;
		m=no+1;
		l=min-((m-min)/2);
		hm= no -((m-min)/2);
		if(cf>median)
		{
			fm = arr[count];
			lm = l;
		}
		fx =midpoint*arr[count];
		sumf = sumf+fx;
		cout<<"Interval "<<"Mid point "<<"class boundaries "<<"Class Frequecy "<<"Comulatice frequency "<<"Fx  "<<endl; 
		cout<<min<<"-"<<no<<":   "<<midpoint<<"      "<<l<<"-"<<hm<<"  "<<arr[count]<<"      "<<cf<<"   "<<fx<<endl;
		min = no+0.1;
		count++;
	}
	no=1.7;
	double gmean,gmedian,gvariance,gstd;
	gmean=(sumf/cf);
	gmedian = lm +(num/fm)*((n/2)-c);
	for(int i=0;i<Noofinterval;i++)
	arr[i]=0;
	count=0;
	while(no <ma)
	{
		no = mi + num;  
		for(int i=0;i<n;i++)
		{
			if(v[i]>=mi&&v[i]<=no)
			{
				arr[count]++;
			}
		}
		midpoint = (mi + no)/2;
		ffx=arr[count]*((midpoint-gmean)*(midpoint-gmean));
		sumfx = sumfx+ffx;
		mi = no+0.1;
		count++;
	}
	cout<<"SumFX: "<<sumfx<<endl;
	gvariance = sumfx/(n-1);
	gstd = sqrt(sumfx/(n-1));
	cout<<"Grouped mean: "<<gmean<<endl;
	cout<<"Grouped Median: "<<gmedian<<endl;
	cout<<"lower class boundary of median class: "<<lm<<endl;
	cout<<"frequency of median class: "<<fm<<endl;
	cout<<"comulative frequency of the precending class: "<<c<<endl;
	cout<<"class width: "<<num<<endl;
	cout<<"gstd: "<<gstd<<endl;
	cout<<"gvariance: "<<gvariance<<endl;
	cout<<endl;
	for(int i=0;i<Noofinterval;i++)
	{
		cout<<i+1<<": ";
		for(int j=0;j<arr[i];j++)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
}
