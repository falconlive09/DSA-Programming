#include <bits/stdc++.h>
using namespace std;

//Brute Force O(kxn)+O(n) gives TLE
double minimiseMaxDistance(vector<int> &arr, int k){
	int n=arr.size();
	vector<int> howMany(n-1,0);
	for(int gasStations=1;gasStations<=k;gasStations++){
		long double maxSection=-1;
		int maxIndex=-1;
		for(int i=0;i<n-1;i++){
			long double diff=(arr[i+1]-arr[i]); //array is sorted
			long double sectionLength=diff/(long double)(howMany[i]+1);
			if(sectionLength>maxSection){
				maxSection=sectionLength;
				maxIndex=i;
			}
		}
		howMany[maxIndex]++;
	}    	
	long double maxAns=-1;
	for(int i=0;i<n-1;i++){
		long double diff=(arr[i+1]-arr[i]);
		long double sectionLength=diff/(long double)(howMany[i]+1);
		maxAns=max(maxAns,sectionLength);
	}
	return maxAns;
}

//Optimised Max Heap O(nlog n)+O(klog n) S.C.-> O(n-1)
double minimiseMaxDistance(vector<int> &arr, int k){
	int n=arr.size();
	vector<int> howMany(n-1,0);
	priority_queue<pair<long double,int>> pq;
	for(int i=0;i<n-1;i++)	pq.push({arr[i+1]-arr[i],i}); //priority queue contains section length & index
	for(int gasStations=1;gasStations<=k;gasStations++){
		auto tp=pq.top();	pq.pop();
		int sectionIndex=tp.second;
		howMany[sectionIndex]++;
		long double initalDiff=arr[sectionIndex+1]-arr[sectionIndex];
		long double newSectionLength=initalDiff/(long double)(howMany[sectionIndex]+1);
		pq.push({newSectionLength,sectionIndex});
	}    	
	return pq.top().first;
}

//Most Optimal
int numberOfGasStationsRequired(long double &dist,vector<int> &arr){
	int count=0;
	for(int i=1;i<arr.size();i++){
		int numberInBetween=(arr[i]-arr[i-1])/dist;
		if((arr[i]-arr[i-1])==(numberInBetween*dist)) //if properly divides -1 the value 
			numberInBetween--;
		count+=numberInBetween;
	}
	return count;
}
double minimiseMaxDistance(vector<int> &arr, int k){
	int n=arr.size();
	long double low=0;
	long double high=0;
	for(int i=0;i<n-1;i++)
		high=max(high,(long double)(arr[i+1]-arr[i]));
	long double diff=1e-6;
	while(high-low>diff){
		long double mid=(low+high)/(2.0);
		int count=numberOfGasStationsRequired(mid,arr);
		if(count>k)
			low=mid;
		else
			high=mid;
	}
	return high;
}