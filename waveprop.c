//serial wave propagation code
#include <stdio.h>
#include <stdlib.h>
#define FRAMES 200
#define ALPHA 0.1f // diffusion factor(controls wave spread)
#define N 100  //grid size

int main()
{
	float cell[N][N];
	float new_cell[N][N];

	//initialize values
	for (int i=0; i<N;i++)
	{
		for(int j=0; j<N; j++)
		{
			cell[i][j] = 0.0f;

			if (i == N/2 && j == N/2)
			{
				cell[i][j] = 100.0f;
			}
		}
	}
	
	//simulation
	for (int t=1; t<=FRAMES; t++)
	{
		printf("Grid center wave height at frame %d is : %f\n", t, cell[N/2][N/2]);

		if ( t ==1 || t == 10 || t == 20 || t == 30 ){
			for(int i=40; i<=60; i++){
				 printf(" _________________________________________________________________________________________________________________________________________________\n");
                        	for (int j=40; j<=60; j++){
                                	printf("| %.1f |",cell[i][j]);
                      		}
                        	printf("\n");
                	}
		}	

		for(int i=1; i<N-1; i++){
			for (int j=1; j<N-1; j++){
				float l_cell = cell[i-1][j];
				float r_cell = cell[i+1][j];
				float u_cell = cell[i][j-1];
				float d_cell = cell[i][j+1];
			
				//2D diffusion update
				new_cell[i][j] = cell[i][j] + ALPHA*(l_cell + r_cell + u_cell + d_cell - 4*cell[i][j]);
			}
		}
		//update the cells for next frame
		for(int i=1; i<N-1; i++){
                        for (int j=1; j<N-1; j++){
				cell[i][j] = new_cell[i][j];
			}
		}
	}

	return 0;
}
