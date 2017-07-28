#include <iomanip>
#include <iostream>


// These numbers define the range of data we expect to see in this lab
// 0 to 1 billion
// use them in the min and max function.

#define LARGEST_NUMBER      1000000000      // 1,000,000,000
#define SMALLEST_NUMBER     0
#define COLUMN_WIDTH        15


//////////////////////////////////////////////////
// Function prototypes 

// an integer only version of min
int min(const int* data, int N);


/////////////////////////////
// max
// 
//// T max (T *data, int N)
//
// returns the largest item in the array
//
// Implement this using templates for any type
template<class T>
// template declaration goes here
T max(const T* data, int N)
{
    int ret = SMALLEST_NUMBER;
    for(int i=0;i<N;i++){
      if (data[i] > ret){
            ret = data[i];
        }
    }
    return ret;
	// your code goes here
}


/////////////////////////////
// min
//
// T min(T *data, int N)
//
// returns the smallest item in the array
//
// Implement this using templates for any type

template<class T>
// template declaration goes here
T min(const T* data, int N) 
{
    int ret = LARGEST_NUMBER;
    for (int i=0; i < N; i++)
    {
        if (data[i] < ret)
        {
            ret = data[i];
        }
    }
    return ret;
}
    
 
    
/////////////////////////////
// sum
//
//
// T sum(T *data[], int N)
//
// returns the sum of all the items in the array
//    

// template declaration goes here
template<class T>
T sum(T *data[], int N)
{
    int sum=0;
   // your code goes here
    for(int i=0;i<N;i++){
        sum+=data[i];
    }
    return sum;
// your code goes here


}
   
/////////////////////////////
// average
//
// double average(T data[], int N)
//
// returns the average of all the items in the array
//

template<class T>
// template declaration goes here
double average(T data[], int N)
{   double sum=0;
   // your code goes here
    for(int i=0;i<N;i++){
        sum+=data[i];
    }
    return sum/N;
}


/////////////////////////////
// read
//
// read N items from the file into the array
// the items are comma separated
// the funtion assumes there is a comma at the beginning
// ,data1, data2,data3, ...., dataN
//
template<class T>
bool read(std::istream& input, T* pData, int N)
{
    char comma;
    
    // read N  numbers separated by commas
    for (int i=0; i< N; i++)
    {
        T number;

        input >> comma;
        if (comma != ',') return false;
        if (input >> number) 
        {
            pData[i] = number;
        }
        else
        {
            return false;
        }
        
    }
    return true;

}

/////////////////////////////
// display
//
// display N items of the array to std::cout
//
template<class T>
void display(const char* rowName, T *pData, int N)
{
    std::cout.width(20);
    std::cout << rowName;
    for (int i=0; i < N; i++)
    {
        std::cout.width(COLUMN_WIDTH);
        std::cout <<std::fixed<<std::setprecision(2)<<pData[i];
    }
    std::cout << std::endl;
}


