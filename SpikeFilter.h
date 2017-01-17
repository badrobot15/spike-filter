
#ifndef SpikeFilter_h
#define SpikeFilter_h

#include "Arduino.h"

class SpikeFilter
{
	public :
		SpikeFilter(int pin);
		int filter();
	private:		
		void reduce(int arr[],int mn,int mx);
		void merge(int arr[],int mn,int mid,int mx);
		int _pin;
};

#endif

