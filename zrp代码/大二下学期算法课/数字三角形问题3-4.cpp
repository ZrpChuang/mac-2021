#include<stdio.h>
#define min(x,y) (x<y)? x:y
int minimumTotal(int triangle[][5], int triangleSize, int* triangleColSize){
    for(int i = triangleSize-2;i>=0;i--){
        for(int j = 0;j<triangleColSize[i];j++){
            triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}

int main(void){
	int n = 5;
	int triangle[5][5] = {{2},{3,4},{6,5,7},{4,1,8,3},{5,3,3,9,9}};
	int triangleSize = n;//高度是4
	int triangleColSize[n]; 
	for(int i;i<n;i++){
		triangleColSize[i] = i+1;
	}
	printf("测试用例：\n");
 	for(int i = 0;i<n;i++) {
 		for(int j=0;j<=i;j++){
 			printf("%-3d",triangle[i][j]);
		}
		printf("\n");
	}
	int result = minimumTotal(triangle,triangleSize,triangleColSize);
	printf("\n测试结果%d",result);
	
	return 0;
}
