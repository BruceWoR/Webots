#ifndef NETWORK_H
#define NETWORK_H

class Node
{
	std::string _name;
	int _index;
	Joint _joint;
	//TODO:add others
	
	public:
		Node(void);
		Node(std::string name, Joint joint); //index will be when push in map _nodes.
		void set_index(int index);
		int get_index(void);
		void update(vector<pair<float,float>> update_param);//传入phi_j,phi_ij的vector ??
		float get_angle();
		float get_phi();
};

class Edge
{
	int _index1;
	int _index2;
	float _weight;
	//TODO:add others
	
	public:
		Edge(void);
		Edge(Node node1, Node node2, float weight);	//TODO??
		void get_indexs(int &first, int &second);
		float get_weight();
};

class Network
{
	int _count;
	std::map<int,Node> _nodes;
	//std::vector<Edge> _edges;
	std::map<int, std::map<int, Edge>> _edge_map;
	//TODO:add others
	
	public:
		Network(void);
		int add_node(Node node);
		Node* get_node(int index);  //?
		std::vector<int> add_node_from_vector(std::vector<Node> nodes);

		void clear_edge();
		void add_edge(Edge edge);
		void add_edge_from_vector(std::vector<Edge> edges);

		void update_all();	//全部joint更新
		vector<float> get_angle_all();
};

#endif