/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(void)
{
   int *input_array;
   int arraylength = 0;
   int i=0;
   int target_value=0;
   int *indices;
   int returnsize;
   printf("Enter the array size\n");
   scanf("%d",&arraylength);
   input_array = (int*)malloc(sizeof(int)*arraylength);
   printf("Enter the %d elements\n",arraylength);
   for(i=0;i<arraylength;i++)
   {
       scanf("%d",&input_array[i]);
   }
   printf("Enter the target value");
   scanf("%d",&target_value);
   indices = twoSum(input_array,arraylength,target_value,&returnsize);
   printf("The indices are\n");
   for(i=0;i<returnsize;i++)
   {
       printf("%d\n",indices[i]);
   }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    static int *indices;
    unsigned int i =0,j=0;
    indices = (int *) malloc((sizeof(int))*2);
    for(j=0;j<numsSize;j++)
    {
        for(i=j+1;i<numsSize;i++)
        {
            if(nums[j]+nums[i]==target)
            {
                indices[0]=j;                
                indices[1]=i;              
                break;
            }
        }
    }
    *returnSize = 2;    
    return (indices);
}