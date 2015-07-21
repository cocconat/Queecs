#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string> 
using namespace std;

std::random_device rd;
std::mt19937 mt(rd());
std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0,1);
std::normal_distribution<double> normal(0,1.0);
 
using namespace std;
//basket for random number

vector<int> basket;

int main ( int argc,char * argv[]) {


  streampos size;
  char * read;
  std::string newseq;
  std::string memblock;
  int block= atoi(argv[2]);
	
  ifstream file (argv[1], ios::in|ios::binary|ios::ate);
  //ofstream out ("heart_mother", ios::out|ios::binary);
  
  
  if (file.is_open())
  {
	//input file acquisition
	size = file.tellg();
    int n_block =(int) size/block;

    file.seekg (0, ios::beg);
    read = new char [size];
    file.read (read, size);

    //shift the string randomly
    std::uniform_int_distribution<int> distribution(0,block);
    memblock.insert(0,distribution(mt),'0');
  
    memblock.append(read);
		
    
    //mixing initialize
	for (int i ; i<n_block ; i++){
		basket.push_back(i);
		}
		std::shuffle(basket.begin(), basket.end(), mt);


	if (size > block){
	//mixing
	for (int j=0; j<n_block; j++){
		int pos= basket[j];		
		newseq = memblock.substr (pos*block,block);
		cout << newseq;

//  this keep string in memory, pretty useless for this scope.
//		newseq.append(memblock.begin()+pos*block,memblock.begin()+(pos+1)*block);
		 
		 
	}

//	out.close();
	file.close();
    free (read);
    
	}
	else {clog << "block size bigger than file itself"; return 1;}
  }
  else {clog << "Unable to open file"; return 1;}
  return 0;
}
