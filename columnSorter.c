#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. create a struct where you can store the inputs into parallel arrays
2. read inputs into the struct of arrays
3. sort the array, based on condition of each column
4. print
*/ 


int readFile( char fileName[100]); //to load the file
int printOutput ( int num); //to printf
int SortedName(int num);
int SortedAge(int num);
int SortedFruit (int num);


//create struct where to store data in parallel array
typedef struct columnSorter
    {
        char name[100]; 
        int age; 
        char fruit[100]; 
    } CS;

CS data[100];//creat array of structures

int main(int argc, char *argv[])
{   
    int count = readFile("data_sorting.csv"); 
    int n=count; 
    int userInput; 

    //print what struct has for data 
    printf("This is unsorted data : \n");
    printOutput(n); 


    //prompt user to select which sorted that want to sort. 
    printf("Please insert 1: sorted by name, 2: sourted by age, 3: sorted by fruit. \n");
    scanf("%d", &userInput);

    switch (userInput)
    {
    case 1: //sorted Name by comparing string (strcmp)
        SortedName(n);
        break;
    
    case 2:  //sorted age 
         SortedAge(n);
     break;

    case 3: //sorted fruit
         SortedFruit(n);
    break;

    default:
        printf("You have entered the wrong input. Try again. \n"); 
        break;
    }


}//end of main

int readFile( char fileName[100])
{
    FILE *myFile = NULL;
    int count =0;
    
    
    if ((myFile = fopen(fileName, "r")) == NULL) // error check opening file
    {
        printf("Opening file failed.");
        exit(EXIT_FAILURE);
    }

    while (fscanf(myFile, "%s, %d, %s", data[count].name, &data[count].age, data[count].fruit) != EOF) // read in 
    {
        
      count++;

    } // end while
    fclose(myFile);

    return count; 

}

int printOutput (int num)
{
    int n= num; 
     for(int count=0; count<n; count++)
    {
        printf("%s %d %s \n", data[count].name, data[count].age, data[count].fruit);
        
    }
    printf("///////////// \n");
    printf("\n");
    
return printf; 
}

int SortedName(int num)
{
    int n = num; 
     for (int x =0; x< n; x++)
    {
        for(int count=0; count<n-1;count++) //compare 3 pairs 
        {     
        char temp[100]; //create array temp 
            if(strcmp(data[count].name,  data[count+1].name)>0) //+   
            {   
                //if it "true" mean the 1st string is greater than 2nd string
                //copy 2nd to array temp by strcpy
                strcpy(temp,data[count+1].name);

                //copy string 1st to address of string 2nd
                strcpy(data[count+1].name, data[count].name );

                //copy temp to 1st string 
                strcpy(data[count].name, temp);

                //then will get the string sorted from small to big

            } 
        }
    }
    printf("Sorted by name : \n");
    printOutput(n); 
}

int SortedAge(int num)
{
    int n = num; 
    for (int x =0; x< n; x++)
{
    for(int count=0; count<n-1; count++)
    {     
        char temp[100]; 
        if(strcmp(strchr(data[count].name,','), strchr(data[count+1].name,','))>0) //+    
        {   
            //same as sorted name but use strchr to locate first (the commar) occure in string 
            //which will be compared the value after first commar (age)
            strcpy(temp,data[count+1].name);
            strcpy(data[count+1].name, data[count].name );
            strcpy(data[count].name, temp);

        } 
    }
    
}
    printf("Sorted by age : \n");
    printOutput(n); 

}

int SortedFruit (int num)
{
    int n = num ; 
    for (int x =0; x< n; x++)
{
    for(int count=0; count<n-1; count++)
    {     
        char temp[100]; 
        if(strcmp(strrchr(data[count].name,','), strrchr(data[count+1].name,','))>0) //+     //- , 0 , + 
        {
            //similar to Sorted name but strrchr to located the last (commar) occur in string 
            // //which will be compared the value after last commar (name)
            strcpy(temp,data[count+1].name);
            strcpy(data[count+1].name, data[count].name );
            strcpy(data[count].name, temp);

        } 
    }
    
}

printf("Sorted by friut : \n");
printOutput(n); 


}
