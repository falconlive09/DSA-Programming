/* Problem statement
The Road Department is planning to make some new traffic regulations. But to make the regulations they need to analyze the current situation of the traffic.
The traffic can be analyzed from an array 'VEHICLE' of length 'N' , which consists of ‘0’ if there is no vehicle at that point and ‘1’ if there is a vehicle at the point.
Unfortunately the array ‘VEHICLE’ got corrupted as at most 'M' '1' got flipped to ‘0’.
Traffic jam is defined as the length of consecutive vehicles on the road.
The Road Department wants to know the worst possible scenario for the traffic jam. Return the maximum possible length of the consecutive vehicles.
Example:
Input: ‘N’ = 3, ‘M’ = 1, VEHICLE’ = [0, 1, 1]
Output: 3
Explanation:
As there is at most one 1 that got flipped to 0, so for the worst-case scenario we can reflip the first(1-based ) index to 1, resulting in a length of 3.
*/
#include <bits/stdc++.h>
using namespace std;
//variation of max consecutive one's
int traffic(int n, int m, vector<int> vehicle) {
	int left=0,right=0;
    while(right<n) {
        if(vehicle[right]==0){
            m--;
        }
        if(m<0){
            if(vehicle[left]==0)
                m++;
            left++;
        }
        right++;
    }
    return right-left;
}

int traffic(int n, int m, vector<int> vehicle) {
	// Create ans, count and right, and assign with 0.
	int ans = 0, count = 0, right = 0 ;
	// For loop to move the left pointer.
	for(int left = 0; left < n; left++)
    {
        // while right is less than n and count is <= m.
        while(right < n && count <= m)
        {
            // If vehicle at right is 0.
            if(vehicle[right] == 0)
            {
                count++ ;
                // Break if count exceeds m.
                if(count > m)
                {
                    count-- ;
                    break ;
                }
            }
            right++ ;
        }
        // Update answer.
        ans = max(ans, right-left) ;
        // If vehicle at left is 0.
        if(vehicle[left] == 0)
        {
            count-- ;
        }
    }
    // Return answer.
    return ans ;
}