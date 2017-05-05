#pragma once
#include <vector>
#include <thread>
#include <mutex>
#include <limits>
#include <string>
#include <fstream>
#include <chrono>
#include <algorithm>
const float INF = std::numeric_limits<float>::max();
//grab semaphore and add it here
class FWGraph
{
public:
	FWGraph();
	FWGraph(int n);
	~FWGraph();

	void Initialize(std::string& s);  //Read in file specified by string, initialize matrix with those vals
									// Cost to self (i,i) = 0, INF if edge doesn't exist, value specified by input otherwise

	void AllPairs();
	void BlockedAllPairs(int blockingFactor);




	std::vector<std::vector<int>> totalEdgeCosts;
	int numNodes;


};

