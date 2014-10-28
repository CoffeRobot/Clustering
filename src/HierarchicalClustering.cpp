#include "HierarchicalClustering.h"
#include <limits>


using namespace std;

// constructor
template<class T>
HierarchicalClustering<T>::HierarchicalClustering()
{
	
}

template<class T>
HierarchicalClustering<T>::~HierarchicalClustering(void)
{
}

template<class T>
void HierarchicalClustering<T>::clusterData(vector<T>& data)
{
	m_pi.resize(data.size());
	m_lambda.resize(data.size());

	m_pi[0] = 0;
	m_lambda[0] = numeric_limits<T>::max();

	for (int i = 1; i < data.size(); i++)
	{
		m_pi[i] = i;
		m_lambda[i] = numeric_limits<T>::max();
		
		vector<T> distances(i - 1);

		for (int j = 0; j < i-1; j++)
		{
			distances[j] = getDistance()
		}
	}
}

