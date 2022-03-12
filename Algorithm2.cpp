/*
* Date: 2022-03-03
* Course: Parallel and Distributed Computing
* Benchmark: toy app thath allows to meausre performance 
* of a specific aspect of the computer
* 
* to compile: g++ Algorithm2 -o Algorithm2
* to execute: ./Algorithm2 <integer value>
*/

/* Its required to impolement an app that multiply 2 matrixes
   the algorithm to use will be the clasic (rows * columns)
*/

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <unistd.h>
#include <math.h>
#include <cstring>
#include <time.h>
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
    printf("%f",totalTime);
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
* Function that multiplies two matrixes
* @param Ma that is the A matrix
* @param Mb that is the B matrix
* @return The matrix product between Ma and Mb
*/
void multiMatrix(vector<vector<double>> Ma, vector<vector<double>> Mb){
	sampleStart();
	vector<vector<double>> MResult(Ma.size(),vector<double>(Ma.size(),0));
	int size=Ma.size();
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			for(int k=0;k<size;k++){
				MResult[i][j]+=Ma[i][k]*Mb[k][j];
			}
		}
	}
	sampleEnd();
}
/**
 * @brief Function that generates a random value 
 * 
 * @param fMin that is the lower limit of the random value
 * @param fMax that is the higher limit of the random value
 * @return a double value between fMin and fMax 
 */
double randomNumber(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
/**
 * @brief that generates a matrix with truly random values
 * @param N that is the size of the matrix
 * @return a matrix with random values
 */
vector<vector<double>> generateMatrix(int N){
	vector<vector<double>> M(N,vector<double>(N,0));

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			M[i][j]=randMM();
		}
	}
    return M;
}

/**
 * @brief that prints in console a matrix
 * @param M that its the matrix will be printed
 */

void printMatrix(vector<vector<double>> M){
	int size = M.size();
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}

}

/**
* Main function
* @param argc that is the number of arguments
* @param argv that is a vector with the arguments
*/
int main (int argc, char** argv){
	srand(time(NULL));
	int N=atoi(argv[1]);
	/*It is used the vector class to create the matrixes*/
	//cout<< "Número ingresado: "<<N<<endl;
	vector<vector<double>> M1(N,vector<double>(N,0));
	vector<vector<double>> M2(N,vector<double>(N,0));
	vector<vector<double>> MR(N,vector<double>(N,0));
	M1=generateMatrix(N);
	M2=generateMatrix(N);
	multiMatrix(M1,M2);	
}

