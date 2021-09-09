#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

class node
{
	public:
	node go(int);
	int go(node);
	node set(int, int, int);
	int x, y, z;
	bool operator==(const node n)
	{
		if(x == n.x && y == n.y && z == n.z)
			return true;
		else 
			return false;
	}
};

bool operator<(node m, node n)
{
	if(m.x < n.x)
		return true;
	if(m.x > n.x)
		return false;
	if(m.y < n.y)
		return true;
	if(m.y > n.y)
		return false;
	if(m.z < n.z)
		return true;
	return false;
	
}

class state
{
	public:
	state(node n)
	{
		at = n;
		sum = 0;
	}
	vector<int> list;
	node at;
	int sum;
};

int main()
{
	string s;
	ifstream in;
	ofstream out;
	in.open("input.txt", ifstream::in);
	out.open("output.txt", ofstream::out);
	in >> s;
	int dim_x, dim_y, dim_z;
	node begin, end;
	in >> dim_x >> dim_y >> dim_z;
	in >> begin.x >> begin.y >> begin.z;
	in >> end.x >> end.y >> end.z;
	int N;
	in >> N;
	map <node, vector<int> > adj;
	int inv[19] = {0, 2, 1, 4, 3, 6, 5, 10, 9, 8, 7, 14, 13, 12, 11, 18, 17, 16, 15};
	int c1[19] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int c2[19] = {0, 10, 10, 10, 10, 10, 10, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14};
	int *cost;
	if(s == "BFS")
		cost = c1;
	else
		cost = c2;
	while(N--)
	{
		node n;
		in >> n.x;
		in >> n.y;
		in >> n.z;
		while(in.peek() != '\n' && in.peek() != EOF)
		{
			int i;
			in >> i;
			adj[n].push_back(i);
		}
	}
	set<node> traveled;
	queue<state> frontier;
	frontier.push(state(begin));
	while(!frontier.empty())
	{
		state now_state = frontier.front();
		frontier.pop();
		if(now_state.at == end)
		{
			if(s == "BFS")
			{
				out << now_state.sum << endl;
				out << now_state.list.size() + 1 << endl;
				out << begin.x << " " << begin.y << " " << begin.z << " " << 0;
				node travel = begin;
				for(int i = 0; i < now_state.list.size(); i++)
				{
					travel = travel.go(now_state.list[i]);
					out << endl;
					out << travel.x << " " << travel.y << " " << travel.z << " ";
					out << cost[now_state.list[i]];
				}
			}
			if(s == "UCS")
			{
				
			}
			return 0;
		}
		vector<int> *vect = &adj[now_state.at];
		for(int i = 0; i < vect->size(); i++)
		{
			node target = now_state.at.go((*vect)[i]);
			if(traveled.count(target))
				continue;
			state s = now_state;
			s.sum += cost[(*vect)[i]];
			s.list.push_back((*vect)[i]);
			s.at = target;
			traveled.insert(s.at);
			frontier.push(s);
		}

	}
	out << "FAIL";
	return 0;
}

node node::set(int in_x, int in_y, int in_z)
{
	this->x = in_x;
	this->y = in_y;
	this->z = in_z;
	return *this;
}

int node::go(node n)
{
	int dx = this->x - n.x;
	int dy = this->y - n.y;
	int dz = this->z - n.z;
	int len = dx * dx + dy * dy + dz * dz;
	if(len == 2)return 14;
	if(len == 1)return 10;
	else return -1;
}

node node::go(int step)
{
	node n;
	switch(step)
	{
		case 1:
		n.set(1, 0, 0);
		break;
		case 2:
		n.set(-1, 0, 0);
		break;
		case 3:
		n.set(0, 1, 0);
		break;
		case 4:
		n.set(0, -1, 0);
		break;
		case 5:
		n.set(0, 0, 1);
		break;
		case 6:
		n.set(0, 0, -1);
		break;
		case 7:
		n.set(1, 1, 0);
		break;
		case 8:
		n.set(1, -1, 0);
		break;
		case 9:
		n.set(-1, 1, 0);
		break;
		case 10:
		n.set(-1, -1, 0);
		break;
		case 11:
		n.set(1, 0, 1);
		break;
		case 12:
		n.set(1, 0, -1);
		break;
		case 13:
		n.set(-1, 0, 1);
		break;
		case 14:
		n.set(-1, 0, -1);
		break;
		case 15:
		n.set(0, 1, 1);
		break;
		case 16:
		n.set(0, 1, -1);
		break;
		case 17:
		n.set(0, -1, 1);
		break;
		case 18:
		n.set(0, -1, -1);
		break;
	}
	n.x += this->x;
	n.y += this->y;
	n.z += this->z;
	return n;
}

