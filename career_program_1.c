#include<stdio.h>
#include<stdlib.h>

void nextLargerElement(int arr[],int N);//function to find next larger elements

int main(void)
{
    int N;
    printf("Enter the no. of terms");
    scanf("%d",&N);

    int arr[N];//array of N terms

    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]); //getting inputs of N elements and storing into arr array

    }

    nextLargerElement(arr,N);//calling the function

}

void nextLargerElement(int arr[],int N) //defining the function
{
    int stack[N];//Declaring stack of N values
    int final[N]; //array which stores greater element of each value of arr
    int top=-1;

   for(int i=N-1;i>=0;i--)
   {
       if(top==-1)
       {
           stack[++top]=arr[i];
           final[i]=-1;
       }
       else if(arr[i]<stack[top])
       {
           final[i]=stack[top];
           stack[++top]=arr[i];

       }
       else
       {
           while(arr[i]>stack[top] && top!=-1)
           {
               top--;
           }
           if(top==-1)
           {
               final[i]=-1;
           }
           else
           {
               final[i]=stack[top];
           }
           stack[++top]=arr[i];
       }
   }

   for(int i=0;i<N;i++)
   {
     printf("%d ",final[i]);
   }

}

// The time complexity of the code is still O(n) and not O(n^2) even though there is a while loop nested.
// This is because the while loop is conditional and acts like more of a "if" statement than a loop.
// while loop only triggers if the value in stack is less than that of the new element. hence
// at worst case it may trigger "n" times or the size of array times. hence the time complexity will be
// 2n at worst. hence the asymptotic notation will be O(n) only.