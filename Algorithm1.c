/*
* Date: 2022-03-03
* Course: Parallel and Distributed Computing
* Topic: build of second benchmark
* Benchmark: Implement step by step benchmark of Matrix Multiplication
* algorithm clasic (rows*columns) of matrixes of same dimension
* to compile: gcc Algorithm1 -o Algorithm1
* to execute: ./Algorithm1 <integer value>
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <errno.h>

clock_t start, endTime;
/*Inicio: medida de tiempo*/
/**
 * @brief Function that starts the time measure
 * 
 */
void sampleStart(){
    start = clock();
}

/*Fin: medida de tiempo*/
/**
 * @brief Function that ends the time measure
 * 
 */
void sampleEnd(){
    /*Print the time*/
    endTime = clock();
    double totalTime= ((double) (endTime - start)) / CLOCKS_PER_SEC;
    printf("%f\t",totalTime);
}

/*More randomly*/
float randMM(){
    float min=0.001,max=9.999;
    static int first=-1;
    if((first=(first<0)))
        srand(time(NULL)+getpid());
    if(min>max)
        return errno=EDOM,NAN;
    return min +(float)rand()/((float)RAND_MAX/(max-min)); 
}

//Variable with high value to reserve memory

#define DATA_SZ (1024*1024*64*3)

//Its reserved the memory space taking into account DATA_SZ
static double MEM_CHUNK[DATA_SZ];

//Its created the function to initialize matrix
/**
 * @brief Function that initializes a matrix
 * 
 * @param SZ that is the matrix size
 * @param Ma that is the matrix A
 * @param Mb that is the matrix B
 * @param Mr that is the result matrix
 */
void initializeMatrix(int SZ,double *Ma,double *Mb, double *Mr){
    int i,j;
    for(i=0;i<SZ;++i){
        for(j=0;j<SZ;++j){
            Ma[j+i*SZ]=randMM();
            Mb[j+i*SZ]=randMM();
            Mr[j+i*SZ]=0.0;
        }
    }
}

//Its implemented the print to validate data
/**
 * @brief Function that prints in the console the matrix passed by parameter
 * 
 * @param SZ that is the matrix size. Considering that the matrix is square
 * @param Ma that is the matrix to print in console
 */
void printMatrix(int SZ,double *Ma){
    int i,j;
    for(i=0;i<SZ;++i){
        for(j=0;j<SZ;++j){
            printf("%f  ",Ma[j+i*SZ]);
        }
        printf("\n");
    }
}
/**
 * @brief Function that multiplies two matrixes
 * 
 * @param size that is the matrix size considering that the matrixes are square
 * @param Ma that is the matrix A
 * @param Mb that is the matrix B
 * @param Mr that is the result matrix
 */
void MatrixMM(int size, double *Ma,double *Mb,double *Mr){
    int i,j,k;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            //Auxiliar pointers
            double *pA, *pB;
            double auxiliarSum=0;
            pA=Ma+(i*size);
            pB=Mb+j;        
            for(k=0;k<size;k++,pA+=size,pB++){
                auxiliarSum+=(*pA * *pB);
            }
            Mr[i*size+j]=auxiliarSum;
        }
    }

}
/**
* Main function
* @param argc that is the number of arguments
* @param argv that is a vector with the arguments
*/
int main (int argc, char ** argv){
    /*Its captured the dimesion of the matrix*/
    int N = (int) atof(argv[1]);
    //printf("Valor ingresado %d\n",N);
    //create the pointers to the reserved memory with dimension NxN
    double *Ma, *Mb, *Mr;
    Ma=MEM_CHUNK;
    Mb=Ma+N*N;
    Mr=Mb+N*N;
    initializeMatrix(N,Ma,Mb,Mr);
    sampleStart();
    MatrixMM(N,Ma,Mb,Mr);
    sampleEnd();
    return 0;
}
