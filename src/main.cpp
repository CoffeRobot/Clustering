#include <vector>
#include <random>
#include <sstream>
#include <string>
#include <fstream>
#include <chrono>

#include "DBScanClustering.h"
#include "HierarchicalClustering.h"
#include "OpticsClustering.h"

using namespace std;


struct Point2f
{
	float x;
	float y;

	Point2f(float a, float b)
	{
		x = a;
		y = b;
	}
};

void testOptics()
{
	vector<Point2f> points;
	int numPoints = 10;

	// manually defined clusters
	points.push_back(Point2f(10, 10));
	points.push_back(Point2f(30, 10));
	points.push_back(Point2f(20, 20));
	points.push_back(Point2f(10, 30));
	points.push_back(Point2f(30, 30));

	points.push_back(Point2f(10, 60));

	points.push_back(Point2f(55, 55));
	points.push_back(Point2f(60, 55));
	points.push_back(Point2f(60, 60));
	points.push_back(Point2f(65, 60));
	points.push_back(Point2f(61, 61));
	points.push_back(Point2f(61, 59));

	points.push_back(Point2f(100, 10));
	points.push_back(Point2f(110, 20));

	points.push_back(Point2f(110, 60));

	random_device rd;
	default_random_engine engine(rd());
	normal_distribution<float> center1(50, 10);
	normal_distribution<float> center2(200, 50);
	normal_distribution<float> centerX(400, 5);
	normal_distribution<float> centerY(200, 5);
	normal_distribution<float> centerX2(350, 10);
	normal_distribution<float> centerY2(400, 15);

	uniform_real_distribution<float> randomX(0, 640);
	uniform_real_distribution<float> randomY(0, 480);
	uniform_int_distribution<unsigned int> colorDist(0, 255);

}

void testDBSCan(float eps, int minPoints, int numPoints)
{
	random_device rd;
	default_random_engine engine(rd());
	normal_distribution<float> center1(50, 10);
	normal_distribution<float> center2(200, 50);
	normal_distribution<float> centerX(400, 10);
	normal_distribution<float> centerY(200, 10);
	normal_distribution<float> centerX2(350, 10);
	normal_distribution<float> centerY2(400, 15);

	uniform_real_distribution<float> randomX(0, 640);
	uniform_real_distribution<float> randomY(0, 480);
	uniform_int_distribution<unsigned int> colorDist(0, 255);

	vector<Point2f> points;

	for (size_t i = 0; i < numPoints; i++)
	{
		points.push_back(Point2f(center1(engine), center1(engine)));
		points.push_back(Point2f(center2(engine), center2(engine)));
		points.push_back(Point2f(randomX(engine), randomY(engine)));
		points.push_back(Point2f(centerX(engine), centerY(engine)));
		points.push_back(Point2f(centerX2(engine), centerY2(engine)));
	}

	chrono::high_resolution_clock::time_point begin, end;


	begin = chrono::high_resolution_clock::now();

	DBScanClustering<Point2f> cluster;
	cluster.clusterPoints(&points, eps, minPoints,
		[](Point2f a, Point2f b)
	{
		return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	});


	stringstream ss;

	ss << "eps: " << eps << " minPoints: " << minPoints;

	vector<vector<int> > clusters;
	vector<bool> border;

	cluster.getBorderClusters(clusters, border);

	end = chrono::high_resolution_clock::now();

	cout << " Number of clusters found: " << clusters.size() << "\n";

	cout << "Elapsed time to cluster points "
		 << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms \n";
	
}


int main(int argc, char* argv[])
{
	testDBSCan(10, 3, 100);
}