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

  //arguments checks
  if (argc < 3) {cout << "WARNING!!  missing arguments:" <<endl
		      << "- file to mix" << endl 
		      << "- block size"<<endl;
		      return (1);}
  if (!atoi(argv[2])) {cout << "WARNING!! second argument must be an int" <<endl;
		      return (1);}
			  

  streampos size;
  char * read;
  int block= atoi(argv[2]);
  ifstream file (argv[1]);
  std::vector<char> data = std::vector<char>(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
  
  if (file.is_open())
  {
    //input file acquisition	
    size = file.tellg();
    int n_block =(int) size/block;
    file.seekg (0, ios::beg);
   
    //shift the string randomly and acquire it in string
    std::uniform_int_distribution<int> distribution(0,block);
    data.insert(data.begin(),distribution(mt),'0');
    
	
	//mixing initialize
	for (int i=0 ; i<n_block ; i++)
	{basket.push_back(i);}
	std::shuffle(basket.begin(), basket.end(), mt);
	
	//mixing
	if (size > block){
	for (int j=0; j<n_block; j++){
	  int pos= basket[j];		
	  std::for_each(data.data()+pos*block, data.data()+(pos+1)*block, [](char c) { std::cout << c; });
		}	
	
	file.close();
 	}
  //errors
	else {clog << "block size bigger than file itself"; return 1;}
  }
  else {clog << "Unable to open file"; return 1;}
  return 0;
}
