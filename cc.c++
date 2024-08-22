#include <iostream>
using namespace std;

int main() {
	int A,B,C,X,cuboid,cube;
	cin >> A >> B >> C >> X;
	cuboid = A*B*C;
	cube = X*X*X;
	
	if(cuboid >= cube ){
	     cout << "cuboid";
    }
	else if (cuboid <= cube){
	    cout << "Cube";
	}
	else{
        cout << "Equal";

    }
	
	        }
	
	
