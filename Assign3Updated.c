#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

    void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }


    int LinearSearch(int Data_Array[],int Keys_Array[],int Size1,int Size2){
        printf("Now running Sequential Search...\n");
        int i,n,search;
            for(n=0;n<Size2;n++){
                search=Keys_Array[n];
                for(i=0;i<Size1;i++){
                    
                    if(Data_Array[i]==Keys_Array[n]){
                        printf("%d from Keys Array found at position %d in Data array\n",search,i);
                        break;
                    }
                    
                    
                    
                    
                }
            
            
                if(i==Size1){
                    printf("");
                }
            }
                
    return 1;
    }
    
    int BinarySearch(int Data_Array[],int Size1,int Data,int Size2){
        int left,right,mid;
        left=0;
        right=Size1-1;
            while(left<right){
                mid=((left+right)/2);
                if(Data==Data_Array[mid]){
                    return mid;
                }
                if(Data<Data_Array[mid]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }    
                
            
            }
        return -1;
    }
    
    int partition(int Data_Array[],int LB,int UB){
        int pivot,start,end;
        pivot=Data_Array[LB];
        start=LB;
        end=UB;
        while(start<end){
            while(Data_Array[start]<=pivot){
                start++;
            }
            while(Data_Array[end]>pivot){
                end--;
            }
            if(start<end){
                swap(&Data_Array[start],&Data_Array[end]);
            }
        }
    swap(&Data_Array[LB],&Data_Array[end]);
    return end;
        
    }

    void QuickSort(int Data_Array[],int LB, int UB){
        int location;
        if(LB<UB){
            location=partition(Data_Array,LB,UB);
            QuickSort(Data_Array,LB,location-1);
            QuickSort(Data_Array,location+1,UB);
            
        }
    }






int main() { int count=0; //tracks size of arr

// Creation of arrays
int Size1, Size2;
// the srand function allows for all values of the array to be different every time
srand( time( NULL ) );
// scanning the user values 
printf("Please Enter a Number over 1000 for the Data Array\n");
scanf("%d",&Size1);

printf("Please Enter the Number 100 for the Key Array\n");
scanf("%d",&Size2);

//creation of arrays wiht given user inputs
int Data_Array[Size1];
int Keys_Array[Size2];

//adding random integers in the array by looping through with a simple for loop
for(int i=0 ; i < Size1 ; i++){
    Data_Array[i]= rand()%99998 + 1;
}

for(int i=0; i < Size2; i++){
    Keys_Array[i]= rand()%99998 + 1;   
}
//writing to files 
FILE *yp;
yp=fopen("Experimental Data1","w");
fprintf(yp,"Data_Array");
for(int i=0;i<Size1;i++){
fprintf(yp,"%d\n",Data_Array[i]);
}
fclose(yp);

FILE *fp;
fp=fopen("Experimental Data2","w");
fprintf(fp,"Keys_Array Data\n");
for(int i=0;i<Size2;i++){

fprintf(fp,"%d\n",Keys_Array[i]);
}
fclose(fp);

printf("First Searching By Sequential in a unsorted Data_Array\n\n");


// Calculate the time taken by fun()
    clock_t t;
    t = clock();
    LinearSearch(Data_Array,Keys_Array,Size1,Size2);// replace fun() with your search functions

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("Sequential Search took %f seconds to execute \n\n", time_taken);

//opening a file for times
FILE *ap;
ap=fopen("Time Calculate","w");
fprintf(ap,"Time Calculated for Sequential Search is %f\n",time_taken);
fclose(ap);


printf("QuickSorting Data_Array\n\n");



// Calculate the time taken by fun()
    t = clock();
   QuickSort(Data_Array,0,Size1);// replace fun() with your search functions

    t = clock() - t;
    double time_taken2 = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("QuickSorting took %f seconds to execute \n\n", time_taken2);

printf("Now Running Sequential Search With sorted Array\n\n");


// data collection
ap=fopen("Time Calculate","a");
fprintf(ap,"Time Calculated for QuickSort is %f\n",time_taken2);
fclose(ap);



//data collection
FILE *tp;
tp=fopen("Experimental Data1 Sorted","w");
fprintf(tp,"Data_Array");
for(int i=0;i<Size1;i++){
fprintf(tp,"%d\n",Data_Array[i]);
}
fclose(tp);

    t = clock();
    LinearSearch(Data_Array,Keys_Array,Size1,Size2);// replace fun() with your search functions

    t = clock() - t;
    double time_take4 = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("Sequential Sorted Search took %f seconds to execute \n\n", time_take4);
//data collection    
    ap=fopen("Time Calculate","a");
    fprintf(ap,"Time Calculated for Sorted Sequential Search is %f\n",time_take4);
    fclose(ap);
    
    
    
    void callBinary(){
        printf("Searching Sorted Data_Array via BinarySearch\n\n");
            for(int y=0;y<Size2;y++){
                int result=BinarySearch(Data_Array,Size1,Keys_Array[y],Size2);
                if(result==-1){
                    printf("");
                }
                else{
                    printf("The Element %d is in the Data_Array at position %d\n",Keys_Array[y],result);
                }
            }
    }    
    
    
    t = clock();
    callBinary();// replace fun() with your search functions

    t = clock() - t;
    double time_take5 = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("Binary Sorted Search took %f seconds to execute \n", time_take5);


// More file writing
    ap=fopen("Time Calculate","a");
    fprintf(ap,"Time Calculated for Binary Search is %f\n",time_take5);
    fclose(ap);


}

