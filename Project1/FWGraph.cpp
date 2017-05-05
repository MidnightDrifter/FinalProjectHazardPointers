#include "FWGraph.h"



FWGraph::FWGraph() : numNodes(0), totalEdgeCosts() 
{
}

FWGraph::FWGraph(int n) : numNodes(n), totalEdgeCosts(n)
{
	for (std::vector<int> i : totalEdgeCosts)
	{
		for (int j = 0; j < n; ++j)
		{
			i.push_back(INF);
		}
	}
}
/*

std::string timingFilename("Timing info P5 - ");
timingFilename+=std::to_string(pass);
timingFilename += " Passes.txt";
std::ofstream fileOut(timingFilename, std::fstream::out | std::fstream::trunc);


std::cout << "Loop " << passes + 1 << " started." << std::endl;
fileOut << "Loop " << passes + 1 << " started." << std::endl;
std::chrono::time_point<std::chrono::system_clock> start, end;
start = std::chrono::system_clock::now();


//DO STUFF



std::cout << "Loop " << passes + 1 << " ended." << std::endl;
fileOut << "Loop " << passes+1 << " ended." << std::endl;
end = std::chrono::system_clock::now();

std::chrono::duration<double> elapsed_seconds = end - start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);

fileOut << "finished computation at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n\n";


*/

void FWGraph::Initialize(std::string &s)
{
	
	//Every line :  indexA, indexB, cost of edge from A --->  B
	std::string temp;  //Temporary string to store input values that need to be converted to integers
	int x, y, cost;
	std::fstream input(s, std::fstream::in);
	while (!input.eof())
	{
		input >> temp;
		x = std::stoi(temp);
		input >> temp;
		y = std::stoi(temp);
		input >> temp;
		cost = std::stoi(temp);
		totalEdgeCosts[x][y] = cost;
	}
	input.close();

}

void FWGraph::AllPairs()
{//Start from 1 instead of 0?
	for (int k = 0; k < numNodes; ++k)
	{
		for (int i = 0; i < numNodes; ++i)
		{
			for (int j = 0; j < numNodes; ++j)
			{
				totalEdgeCosts[i][j] = std::min(totalEdgeCosts[i][j], totalEdgeCosts[i][k] + totalEdgeCosts[k][j]);
			}
		}
	}
}

void FWGraph::BlockedAllPairs(int blockingFactor)
{

}


FWGraph::~FWGraph()
{


}
