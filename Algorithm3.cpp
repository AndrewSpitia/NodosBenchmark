/*
* Date: 2022-03-03
* Course: Parallel and Distributed Computing
* Benchmark: Implement step by step benchmark of Matrix Multiplication
* algorithm clasic (rows*columns) of matrixes of same dimension
* to compile: g++ Algorithm3.cpp -o Algorithm3
* to execute: ./Algorithm3 <integer value>
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <unistd.h>
#include <math.h>
#include <cstring>
using namespace std;

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
/**
*   
*/
double ** createMatrix(int size){
    int i;
    double **matrix=new double *[size];
    for(i=0;i<size;++i)
        matrix[i]= new double[size];
    return matrix;
}

/**
*   @brief Function that initializes a three matrixes before do a multiplication
*   @param matA is a pointer that represents a matrix (matrix 1)
*   @param matB is a pointer that represents a matrix (matrix 2)
*   @param matC is a pointer that represents a matrix (result matrix when matA*matB)
*   @param size that is the matrix size of matA,matB,matC
*/
void initializeMatrixes(int size,double ** &matA, double ** &matB, double ** &matC ){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            matA[i][j]=randMM();
            matB[i][j]=randMM();
            matC[i][j]=0;
        }
    }
}
/**
*   @brief Function that destroyes a matrix. This deletes all the rows of a matrix and later puts the matrix pointer as a null pointer 
*   @param size that is the matrix size N*N
*   @param matrix is a pointer that represents the matrix 
* 
*/
void destroyMatrix(int size, double** &matrix){
    if(matrix){
        int i; 
        for(i=0;i<size;i++){
            delete [] matrix[i];
        }
        delete [] matrix;
        matrix=nullptr;

    }
}
/**
*   @brief Function that multiplies two matrixes
*   @param size that is the matrix size N*N
*   @param matrix1 is a pointer that represents the matrix 1
*   @param matrix2 is a pointer that represents the matrix 2
*/
double ** matrixProduct(int size, double ** &matrix1,double ** &matrix2){
    int i,j,k;
    double **matrix = createMatrix(size);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            for(k=0;k<size;k++){
                matrix[i][j]+=matrix1[i][k]*matrix2[k][j];
            }   
        }     
    }
    return matrix;
}

/**
* @brief Function that prints a matrix
* @param matrix that is the matrix
* @param size that is the matrix size
*/
void printMatrix(double **&matrix,int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf(" %f ",matrix[i][j]);
        }   
        printf("\n");
        
    }
    printf("\n\n");
}
/**
*
*/
int main(int argc,char **argv){
    int N=atoi(argv[1]);
    double **matA = createMatrix(N);
    double **matB = createMatrix(N);
    double **matR = createMatrix(N);
    initializeMatrixes(N,matA,matB,matR);
    
    sampleStart();
    matR=matrixProduct(N,matA,matB);
    sampleEnd();
    
    destroyMatrix(N,matA);
    destroyMatrix(N,matB);
    destroyMatrix(N,matR);
}