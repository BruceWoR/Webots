#include "network.h"
#include "joint.h"
#include "particle.h"
#include "p_to_net.h"
using namespace std;

void initial_network(Network &net)
{
	Joint lateral_ankle;
	Joint lateral_hip;
	Joint frontal_hip;
	Joint frontal_knee;
	Joint frontal_ankle;

	Node node1("lateral_ankle",lateral_ankle);
	Node node2("lateral_hip",lateral_hip);
	Node node3("frontal_hip",frontal_hip);
	Node node4("frontal_knee",frontal_knee);
	Node node5("frontal_ankle",frontal_ankle);

	net.add_node(lateral_ankle);
	net.add_node(lateral_hip);
	net.add_node(frontal_hip);
	net.add_node(frontal_knee);
	net.add_node(frontal_ankle);
}

void p_to_net(Network &net, particle p)
{
	net.clear_edge();

	Edge e12(net._Nodes[0], net._Nodes[1],(PI/2.0)); //TODO
	Edge e21(net._Nodes[1], net._Nodes[0],-(PI/2.0));
	
	Edge e23(net._Nodes[1], net._Nodes[2], p.X[0]);
	Edge e32(net._Nodes[2], net._Nodes[1], -p.X[0]);
	
	Edge e34(net._Nodes[2], net._Nodes[3], X[1]);
	Edge e43(net._Nodes[3], net._Nodes[2], -p.X[1]);

	Edge e45(net._Nodes[3], net._Nodes[4], X[2]);
	Edge e54(net._Nodes[4], net._Nodes[3], -p.X[2]);

	net.add_edge(Edge e12);
	net.add_edge(Edge e21);
	net.add_edge(Edge e23);
	net.add_edge(Edge e32);
	net.add_edge(Edge e34);
	net.add_edge(Edge e43);
	net.add_edge(Edge e45);
	net.add_edge(Edge e54);
}