#include <string>
#include <fstream>
#include <map>
using namespace std;

class node
{
	public:
	node go(int);
	node set(int, int, int);
	int x, y, z;

};

int main()
{
	string s;

	ifstream cin;
	ofstream cout;
	cin.open("input.txt", ifstream::in);
	cout.open("output.txt", ofstream::out);
	cin >> s;
	int dim_x, dim_y, dim_z;
	int begin_x, begin_y, begin_z;
	int end_x, end_y, end_z;
	cin >> dim_x >> dim_y >> dim_z;
	cin >> begin_x >> begin_y >> begin_z;
	cin >> end_x >> end_y >> end_z;
	int N;
	cin >> N;
	map <node, *node> adj;
	while(N--)
	{
		node n;
		cin >> n.x 
	}

	


	return 0;
}

node node::set(int in_x, int in_y, int in_z)
{
	this->x = in_x;
	this->y = in_y;
	this->z = in_z;
	return *this;
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
