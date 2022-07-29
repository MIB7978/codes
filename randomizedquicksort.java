/*package whatever //do not write package name here */

import java.io.*;



class GFG {
    
    static void quicksort(int arr[],int l,int h)
    {
        if(l<h)
        {
            int pivot = getPivot(arr,l,h);
            quicksort(arr,l,pivot-1);
            quicksort(arr,pivot+1,h);
        }
    }
    static int getPivot(int arr[],int l,int h)
    {
        int random_pivot = l+(int)(Math.random()*10)%(h-l+1);
        int temp = arr[l];
        arr[l] = arr[random_pivot];
        arr[random_pivot]=temp;
        int i=l;
        int x = arr[l];
        
        for(int j=l+1;j<=h;j++)
        {
            if(arr[j]<=x)
            {
                i++;
                 temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                
            }
        }
         temp = arr[i];
        arr[i]=x;
        arr[l]=temp;
        return i;
    }
	public static void main (String[] args) {
     
        int arr[] = {3,2,1,4,5,6};
        quicksort(arr,0,5);
        for(int i=0;i<6;i++)
        System.out.println(arr[i]);
	}
}
