/*package whatever //do not write package name here */

import java.io.*;

class Countingsort {
	
	static void counting_sort(int arr[],int n)
	{
	    int mx = Integer.MIN_VALUE;
	    for(int i=0;i<n;i++)
	    mx = Integer.max(arr[i],mx);
	    
	    int c[] = new int[mx+1];
	    for(int i=0;i<=mx;i++)
	    c[i]=0;
	    int b[]= new int[n];
	    for(int i=0;i<n;i++)
	    c[arr[i]]+=1;
	    
	    for(int i=1;i<=mx;i++)
	    c[i]=c[i]+c[i-1];
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        b[c[arr[i]]-1]=arr[i];
	        c[arr[i]]--;
	    }
	    		for(int i=0;i<7;i++)
		System.out.println(b[i]);
	    
	}
	public static void main (String[] args) {
		
		int arr[] = {4,3,2,2,1,1,6};
// 		counting_sort(arr,7);
		counting_sort(arr,7);

		
	}
}
