/*package whatever //do not write package name here */

import java.io.*;

class GFG {
    
    static void swap(int arr[],int i,int j)
    {
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    static void selection_sort(int arr[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            int mn = arr[i];
            int idx = i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<mn)
                {
                    mn = arr[j];
                    idx=j;
                }
            }
            swap(arr,i,idx);
        }
    }
	public static void main (String[] args) {
		int arr[] = {1,2,3,4,5};
		selection_sort(arr,5);
		for(int i=0;i<5;i++)
		System.out.println(arr[i]);
	}
}
