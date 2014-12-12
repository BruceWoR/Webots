#include <vector>
#include <map>
#include <string>
#include <utility>

#include "joint.h"
#include "Network.h"

using namespace std;


//for Node
Node::Node(void){};

Node::Node(string name, int index, Joint joint) : _name(name), _joint(joint) {};

void Node::set_index(int index)
{
	_index = index;
}

int Node::get_index(void)
{
	return _index;
}

void Node::update(vector<pair<float,float>> update_param)
{
	_joint.update(update_param);
}

float Node::get_angle()
{
	return _joint.get_angle();
}

float Node::get_phi()
{
	return _joint.get_phi();
}






//for Edge
Edge::Edge(void){}

Edge::Edge(Node node1, Node node2, float weight) : _index1(node1._index),_index2(node2._index) _weight(weight) {}//TODO
//TODO: be careful, add edge should be add in 
void Edge::get_indexs(int &first, int &second)
{
	first = _index1;
	second = _index2;
}

float Edge::get_weight()
{
	return _weight;
}



//for Network
Network::Network(void)
{ 
	_count = 0;
}
// TODO: use reference for easy give value to Edge. 
// or can only use network._nodes[i]._index to give value to Edge 
int Network::add_node(Node &node) 
{
	int index = _count ++;
	node.set_index(index)
	_nodes[index] = node;

	return index;
} 

Node* Network::get_node(int index)//用编号取得node指针，用来访问，保持一致性
{
	return &_nodes[index];
}

vector<int> Network::add_node_from_vector(vector<Node> nodes)
{
	vector<int> indexs;
	for(int i = 0; i<nodes.size(); i++)
	{
		indexs.push_back(add_node(nodes[i]));
	}

	return indexs;
}

void Network::add_edge(Edge edge)
{
	int first, second;
	edge.get_indexs(first, second);
	if(_edge_map.count(first) == 0)
	{
		map<int,Edge> new_map;
		_edge_map[first] = new_map;
	}
	_edge_map[first][second] = edge;
}

void Network::add_edge_from_vector(vector<Edge> edges)
{
	for(int i = 0; i<edges.size(); i++)
	{
		add_edge(edges[i]);
	}
}

void update_all()
{
	for(map<int,Node>::iterator i = _nodes.begin(); i != _nodes.end(); i++)
	{
		int index_i = i->first;
		vector<pair<float,float>> update_param;//all phi_j and phi_ij
		for(map<int,Edge>::iterator j = _edge_map[index_i].begin(); j != _edge_map[index_i].end(); j++)
		{
			int index_j = j->first;
			float phi_j = _nodes[index_j].get_phi();
			float phi_ij = _edge_map[index_i][index_j].get_weight();
			update_param.push_back(make_pair(phi_j,phi_ij));
		}
		_nodes[index_i].update(update_param);
	}
}

vector<float> get_angle_all()
{
	vector<float> angles;
	for(map<int,Node>::iterator i = _nodes.begin(); i != _nodes.end(); i++)
	{
		int index_i = i->first;
		angles.push_back(_nodes[index_i].get_angle()); 
	}

	return angles;
}

