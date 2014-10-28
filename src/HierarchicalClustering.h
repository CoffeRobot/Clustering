#ifndef PINOT_CLUSTERING_H
#define PINOT_CLUSTERING_H

#include <vector>

template <class T>
class HierarchicalClustering
{

public:
	// constructor
	HierarchicalClustering();
	// destructor
	~HierarchicalClustering(void);

	void clusterData(std::vector<T>& data);
private:

	std::vector<int> m_pi;
	std::vector<T> m_lambda;

};


#endif

