/*
  SpikeFilter.cpp - Library for Filtering spikes and noises in sensor reading
  Created by Vikrant Z. Fernandes, January 9, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SpikeFilter.h"

SpikeFilter::SpikeFilter(int pin)
{
	pinMode(pin, INPUT);
	_pin = pin;
}

int SpikeFilter::filter(){
  int a[25];
  for (int i=0;i<25;i++)
  {
    a[i]=analogRead(_pin);
    delay(5);
  }
  reduce(a,0,24);
  float res = 0;
  for(int k = 3;k<22;k++)
  {
    res += a[k];
  }
  res = res/19;
  
  return res;
}

void SpikeFilter::reduce(int arr[],int mn,int mx)
{
	int mid;
	if(mn<mx)
	{
		mid=(mn+mx)/2;
		reduce(arr,mn,mid);
		reduce(arr,mid+1,mx);
		merge(arr,mn,mid,mx);
	}
}

void SpikeFilter::merge(int arr[],int mn,int mid,int mx)
{
	int temp[30];
	int i,j,k,m;
	j=mn;
	m=mid+1;
	for(i=mn;j<=mid && m<=mx; i++)
	{
		if(arr[j]<=arr[m])
		{
		temp[i]=arr[j];
		j++;
		}
		else
		{
		temp[i]=arr[m];
		m++;
		}
	}
	if(j>mid)
	{
		for(k=m;k<=mx;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=j;k<=mid;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}
	for(k=mn;k<=mx;k++)
	{arr[k]=temp[k];}
}
