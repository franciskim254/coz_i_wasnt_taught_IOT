#include<iostream> 
#include<bitset>
using namespace std;

int main(){
	
	int input;
	cout<< "WHAT IS YOUR NUMBER: "<< "\n";
	cin >> input;
    uint8_t byte = static_cast<uint8_t>(input);

	cout<< "bits are:"<< "\n";

	for(int i=0; i<8;i++){
		cout<< ((byte>>i)& 0x01)<< endl;
	}

	return 0;
}
