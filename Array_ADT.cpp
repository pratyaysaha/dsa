#include<iostream>
using namespace std;
class array{
	private: 
		int *a;
		int size;
		int length;
	public:
		array(int n);	
		void add(int x);
		void display();	
		void insert(int index, int data);
		void remove(int index);
		int get(int index){return a[index-1];}
		int set(int index, int data){a[index-1]=data;}
		int get_length(){return length;}
		bool isSort();
		int search(int low, int high, int data);
		int max();
		void frequency();
		void merge(array x, array y);
		void reverse();
		void copy(array x); 			//new_array.copy(old_array)
};
array::array(int n)
{
	size=n;
	length=0;
	a=new int[n];
}
void array::add(int x)
{
	a[length]=x;
	length++;
}
void array::insert(int index, int data)
{
	if(length==size)
	{
		cout<<"Overflow";
		return;
	}
	for(int b=length;b>index;b--)
	{
		a[b]=a[b-1];
	}
	length++;
	a[index]=data;
	display();
}
void array::remove(int index)
{
	if(length==0)
	{
		cout<<"empty";
		return;
	}
	for(int b=index-1;b<length;b++)
	{
		a[b]=a[b+1];
	}
	length--;
	display();
}
void array::display()
{
	for(int b=0;b<length;b++)
	{
		cout<<a[b]<<" ";
	}
	cout<<endl;
}
bool array::isSort()
{
	int g =INT_MAX;
	for(int b=0;b<length-1;b++)
	{
		if(a[b]>a[b+1])
		{
			return false;
			break;
		}
	}
	return true;
}
int array::search(int low, int high, int data)
{
	if(isSort()!=1)
		return INT_MAX;
		
	int mid=(low+high)/2;
	if(a[mid]==data)
		return mid+1;
	if(low<high)
	{
		if(data>a[mid])
			search(mid+1,high,data);
		else
			search(low,mid-1,data);
	}
	else
	{
		cout<<"Not Found!!";
		return INT_MAX;
	}
}
int array::max()
{
	int m=INT_MIN;
	for(int b=0;b<length;b++)
	{
		if(m<a[b])
		{
			m=a[b];
		}
	}
	return m;
}
void array::frequency()
{
	int *visited =new int[length];
	int count=0;
	for(int b=0;b<length;b++)
		visited[b]=0;
	for(int b=0;b<length;b++)
	{
		if(visited[b]!=1)
		{

			for(int c=0;c<length;c++)
			{
				if(a[b]==a[c])
				{
					visited[c]=1;
					count++;
				}	
			}
			cout<<"frequency of "<<a[b]<<" : "<<count<<endl;
			count=0;
		}
	}
	
}
void array::merge(array x, array y)
{
	if(x.isSort()!=1 || y.isSort()!=1)
	{
		cout<<"Sort first";
		return;
	}
	int i=1, j=1;
	while(i<=x.get_length() && j<=y.get_length())	
	{
		if(x.get(i)<y.get(j))
		{
			add(x.get(i));
			i++;
		}
		else
		{
			add(y.get(j));
			j++;
		}
		
	}
	while(i<=x.get_length())
	{
		add(x.get(i));
		i++;
	}
	while(j<=y.get_length())
	{
		add(y.get(j));
		j++;
	}
	display();
} 
void array::copy(array x)
{
	int i=1;
	while(i<=x.get_length())
	{
		add(x.get(i));
		i++;
	}
		
}

void array::reverse()
{
	int i=0,j=get_length()-1;
	while(i<j)
	{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		j--;
		i++;
	}
}
int main()
{
	array arr(10);
	arr.add(10);
	arr.add(20);
	arr.add(30);
	arr.add(50);
	arr.add(60);
	arr.display();
	arr.insert(2,10);
	arr.remove(2);
	cout<<arr.get(2)<<endl;
	arr.set(2,20);
	arr.display();
	if(arr.isSort()==1)
		cout<<"Sorted"<<endl;
	else
		cout<<"Not Sorted"<<endl;
	cout<<"Search index of 30 "<<arr.search(0,arr.get_length(),30)<<endl;
	cout<<"Length of array : "<<arr.get_length()<<endl;
	cout<<"MAX : "<<arr.max()<<endl;
	array arr1(10);
	arr1.add(40);
	arr1.add(80);
	arr1.add(90);
	arr1.add(100);
	arr1.add(120);
	arr1.add(130);
	arr1.display();
	arr1.frequency();
	cout<<"Search : "<<arr1.search(0,arr1.get_length(),120)<<endl;
	array arr2(20);
	arr2.merge(arr,arr1);
	array arr3(20);
	arr3.copy(arr2);
	arr3.display();
	arr3.reverse();
	arr3.display();
	
}
