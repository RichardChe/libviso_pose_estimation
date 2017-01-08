#include <iostream>
#include "PoseCompute.h"
#include <vector>

using namespace std;

int main()
{
	FILE *fp = fopen("match.csv", "r");

	vector<p_match> p_matched;
	float u1c, v1c, u2c, v2c, u1p, v1p, u2p, v2p;

	//从CSV文件中读取数据
	while (fscanf(fp, "%f %f %f %f %f %f %f %f", &u1p, &v1p, &u2p, &v2p, &u1c, &v1c, &u2c, &v2c) != EOF)
	{
			p_matched.push_back(p_match(u1p, v1p, 0, u2p, v2p, 0, u1c, v1c, 0, u2c, v2c, 0));
	}

	Parameters param;

	// calibration parameters for sequence 2010_03_09_drive_0019 
	param.calib.f = 645.24; // focal length in pixels
	param.calib.cu = 635.96; // principal point (u-coordinate) in pixels
	param.calib.cv = 194.13; // principal point (v-coordinate) in pixels
	param.base = 0.5707; // baseline in meters

	PoseCompute poseCompute(param);
	vector<double> rt_delta =  poseCompute.estimationMotion(p_matched);

	for (int i = 0; i < 6; i++)
	{
		cout << rt_delta[i] << endl;

	}

	system("pause");
	fclose(fp);
	return 0;
}